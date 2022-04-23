@echo off
echo Mem_M68k
nasmw.exe -f win32 -Xvc -o release\Mem_M68k.obj Mem_M68k.asm
rem echo Mem_S68k
rem nasmw.exe -f win32 -o release\Mem_S68k.obj Mem_S68k.asm
rem echo Mem_Z80
rem nasmw.exe -f win32 -o release\Mem_Z80.obj Mem_Z80.asm
rem echo blit
rem nasmw.exe -f win32 -o release\blit.obj blit.asm
echo main68k
nasmw.exe -f win32 -Xvc -o release\main68k.obj Starscream\Main68k\main68k.asm
echo sub68k
nasmw.exe -f win32 -Xvc -o release\sub68k.obj Starscream\Sub68k\sub68k.asm
rem echo vdp_io
rem nasmw.exe -f win32 -o release\vdp_io.obj vdp_io.asm
rem echo vdp_rend
rem nasmw.exe -f win32 -o release\vdp_rend.obj vdp_rend.asm
rem echo io
rem nasmw.exe -f win32 -o release\io.obj io.asm
rem echo Misc
rem nasmw.exe -f win32 -o release\Misc.obj Misc.asm
rem echo z80
rem nasmw.exe -f win32 -o release\z80.obj z80.asm