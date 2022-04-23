
#include <idc.idc>

static dogenscommand()
{
	auto id,file,s,c;
	id=GetArrayId("GensFile");
	file=fopen(GetArrayElement('S',id,0),"r");
	if (file==0)
		return;
	s="";
	while((c=fgetc(file))!=-1)
	{
		s=s+c;
	}
	Message("Gens jump to "+s+"\n");
	Jump(xtol(s));
}

static main()
{
  auto id,filename;
  filename=AskFile(0,"*.*","Select Gens File for ida");

  if (filename!=0)
  {
    CreateArray("GensFile");
    id=GetArrayId("GensFile");
	SetArrayString(id,0,filename);
	if (AddHotkey("Z","dogenscommand")!=0)
	  Message("Can't add hotkey at Z\n");
	Message("OK\n");
  }
}
