
#include <idc.idc>

static main()
{
	auto filename,file,offs,i,c,fsize,fs;
	
	filename=AskFile(0,"*.*","Select Gens File for ida");

	file=fopen(filename,"rb");
	if (file==0)
		return;

	Message("Processing...\n");
	
	fsize=filelength(file);
	fs=0;
	offs=0;
	while(fs<fsize)
	{
		fs=fs+1;
		c=fgetc(file);//readlong(file,0);
		if (c==-1)
			break;
		for (i=0;i<8;++i)
		{
			if ((c&1)==1)
			{
				//if (GetMnem(offs)=="") Message(ltoa(offs,16)+"\n");
				MakeCode(offs);
			}
			offs=offs+1;
			c=(c>>1);
		}
	}
	Message("OK\n");
}
