sub asd
{
	$p=@_[0];
	$p.="\\"if ($p ne"");
	for $i(<$p*>)
	{
		print "$i\n";
		if (-d $i)
		{
			asd($i);
		}
		else
		{
			$msg=`fc \"$i\" \"C:\\gens11\\svnblah\\$i\"`;
			if (!($msg=~/no differences/))
			{
				print"$msg\n";
			}
		}
	}
}
asd("");