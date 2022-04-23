// A few notes about this implementation of a RAM dump window:
//
// Speed of update was one of the highest priories.
// This is because I wanted the RAM search window to be able to
// update every single value in RAM every single frame,
// without causing the emulation to run noticeably slower than normal.
//

#include "resource.h"
#include "gens.h"
#include "mem_m68k.h"
#include "mem_s68k.h"
#include "mem_sh2.h"
#include "misc.h"
#include "mem_z80.h"
#include "vdp_io.h"
#include "save.h"
#include "ram_search.h"
#include "ram_dump.h"
#include "g_main.h"
#include <assert.h>
#include <commctrl.h>
#include "G_dsound.h"
#include "ramwatch.h"
#include "luascript.h"
#include <list>
#include <vector>
#ifdef _WIN32
   #include "BaseTsd.h"
   typedef INT_PTR intptr_t;
#else
   #include "stdint.h"
#endif

HFONT RamDumpFonts[2];
HDC RamDumpMemDC;
HBITMAP RamDumpMemBMP;
HBITMAP RamDumpLastBMP;

void Update_RAM_Dump() //keeps RAM values up to date in the search and watch windows
{
	//if(disableRamDumpUpdate)
	//	return;
	if (RamDumpHWnd)
		InvalidateRect(RamDumpHWnd,NULL,FALSE);
}

LRESULT CALLBACK RamDumpProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	RECT r;
	RECT r2;
	int dx1, dy1, dx2, dy2;
	static int watchIndex=0;

	switch(uMsg)
	{
		case WM_INITDIALOG: {
			HDC hdc = GetDC(hDlg);
			RamDumpMemDC=CreateCompatibleDC(hdc);
			RamDumpMemBMP=CreateCompatibleBitmap(hdc,RAM_DUMP_WIDTH,RAM_DUMP_HEIGHT);
			LOGFONT lf;
			memset(&lf,0,sizeof(lf));
			lf.lfHeight=-MulDiv(10, GetDeviceCaps(hdc, LOGPIXELSY), 72);
			lf.lfWeight=700;
			lf.lfCharSet=DEFAULT_CHARSET;
			lf.lfOutPrecision=OUT_DEFAULT_PRECIS;
			lf.lfClipPrecision=CLIP_DEFAULT_PRECIS;
			lf.lfQuality=DEFAULT_QUALITY;
			lf.lfPitchAndFamily=DEFAULT_PITCH;
			strcpy(lf.lfFaceName,"Courier New");
			RamDumpFonts[1] = CreateFontIndirect( &lf ); 
			RamDumpLastBMP=(HBITMAP)SelectObject(RamDumpMemDC,RamDumpMemBMP);
			RamDumpFonts[0]=(HFONT)SelectObject(RamDumpMemDC,RamDumpFonts[1]);

			RamDumpHWnd = hDlg;

			if (Full_Screen)
			{
				while (ShowCursor(false) >= 0);
				while (ShowCursor(true) < 0);
			}

			GetWindowRect(HWnd, &r);
			dx1 = (r.right - r.left) / 2;
			dy1 = (r.bottom - r.top) / 2;

			GetWindowRect(hDlg, &r2);
			dx2 = (r2.right - r2.left) / 2;
			dy2 = (r2.bottom - r2.top) / 2;

			// push it away from the main window if we can
			const int width = (r.right-r.left); 
			const int width2 = (r2.right-r2.left); 
			if(r.left+width2 + width < GetSystemMetrics(SM_CXSCREEN))
			{
				r.right += width;
				r.left += width;
			}
			else if((int)r.left - (int)width2 > 0)
			{
				r.right -= width2;
				r.left -= width2;
			}

			SetWindowPos(hDlg, NULL, r.left, r.top, NULL, NULL, SWP_NOSIZE | SWP_NOZORDER | SWP_SHOWWINDOW);
			SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,0,(_68K_RAM_SIZE)/16-RAM_DUMP_ROWS,TRUE);
			return true;
		}	break;

		case WM_COMMAND:
		{
			switch(wParam)
			{
			case IDC_SAVE:
				{
				char fname[2048];
				strcpy(fname,"dump.bin");
				if(Change_File_S(fname,".","Save Full Dump As...","All Files\0*.*\0\0","*.*",hDlg))
				{
					FILE *out=fopen(fname,"wb+");
					int i;
					for (i=0;i<sizeof(Ram_68k);++i)
					{
						fname[i&2047]=Ram_68k[i^1];
						if ((i&2047)==2047)
							fwrite(fname,1,sizeof(fname),out);
					}
					fwrite(fname,1,i&2047,out);
					fclose(out);
				}
				}
				break;

			case IDC_BUTTON1:
				{
				char fname[2048];
				GetDlgItemText(hDlg,IDC_EDIT1,fname,2047);
				int CurPos;
				if ((strnicmp(fname,"ff",2)==0) && sscanf(fname+2,"%x",&CurPos))
				{
					SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,(CurPos>>4),TRUE);
					Update_RAM_Dump();
				}
				}
				break;
			}
		}	break;

		case WM_VSCROLL:
		{
			int CurPos=GetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL);
			int nSBCode=LOWORD(wParam);
			int nPos=HIWORD(wParam);
			switch (nSBCode)
			{
			case SB_LEFT:      // Scroll to far left.
				CurPos = 0;
				break;

			case SB_RIGHT:      // Scroll to far right.
				CurPos = 10000000;
				break;

			case SB_ENDSCROLL:   // End scroll.
				break;

			case SB_LINELEFT:      // Scroll left.
				if (CurPos > 0)
					CurPos--;
				break;

			case SB_LINERIGHT:   // Scroll right.
				//if (CurPos < 122)
				CurPos++;
				break;

			case SB_PAGELEFT:    // Scroll one page left.
				if (CurPos - 15 > 0)
					CurPos -= 15;
				break;

			case SB_PAGERIGHT:      // Scroll one page righ
				CurPos += 15;
				break;

			case SB_THUMBTRACK:   // Drag scroll box to specified position. nPos is the
			case SB_THUMBPOSITION: // Scroll to absolute position. nPos is the position
			{
				SCROLLINFO si;
				ZeroMemory(&si, sizeof(si));
				si.cbSize = sizeof(si);
				si.fMask = SIF_TRACKPOS;
 
				// Call GetScrollInfo to get current tracking 
				//    position in si.nTrackPos
 
				if (!GetScrollInfo(GetDlgItem(hDlg,IDC_SCROLLBAR1), SB_CTL, &si) )
					return 1; // GetScrollInfo failed
				CurPos = si.nTrackPos;
			}	break;
			}
			SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,CurPos,TRUE);
			Update_RAM_Dump();
		}	break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hDlg,&ps);
			static char buff[1000];
			int i,x=GetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL);
			RECT r;
			r.top=r.left=0;
			r.right=RAM_DUMP_WIDTH;
			r.bottom=RAM_DUMP_HEIGHT;
			FillRect(RamDumpMemDC,&r,(HBRUSH)GetStockObject(WHITE_BRUSH));
			x*=16;
			for (i=0;i<RAM_DUMP_ROWS&&x+15<_68K_RAM_SIZE;++i)
			{
				sprintf(buff,"%06X:",0xFF0000+x);
				TextOut(RamDumpMemDC,0,i*18,buff,7);
				int j;
				for(j=0;j<8;++j)
				{
					sprintf(buff,"%02X",(int)Ram_68k[x^1]);
					++x;
					TextOut(RamDumpMemDC,55+j*20,i*18,buff,2);
				}
				for(;j<16;++j)
				{
					sprintf(buff,"%02X",(int)Ram_68k[x^1]);
					++x;
					TextOut(RamDumpMemDC,60+j*20,i*18,buff,2);
				}
				TextOut(RamDumpMemDC,55+8*20-3,i*18,"|",1);
			}
			BitBlt(ps.hdc,5,5,RAM_DUMP_WIDTH,RAM_DUMP_HEIGHT,RamDumpMemDC,0,0,SRCCOPY);
			EndPaint(hDlg,&ps);
			return true;
		}	break;

		case WM_CLOSE:
			if (Full_Screen)
			{
				while (ShowCursor(true) < 0);
				while (ShowCursor(false) >= 0);
			}
			SelectObject(RamDumpMemDC, RamDumpFonts[0]);
			SelectObject(RamDumpMemDC, RamDumpLastBMP);
			DeleteObject(RamDumpMemBMP);
			DeleteObject(RamDumpFonts[1]);
			DeleteObject(RamDumpMemDC);
			DialogsOpen--;
			RamDumpHWnd = NULL;
			EndDialog(hDlg, true);
			return true;
	}

	return false;
}