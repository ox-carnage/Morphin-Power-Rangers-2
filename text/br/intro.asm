
		
origin $001FFF92 // ---> Endereço de onde sera gravado os blocos de textos.

text_intro_01:
	break_line()
	db $00
	db $21
	intro_text("LONG AGO AND FAR AWAY, A LEGENDARY.")
text_intro_02:
	db $1E
	intro_text("INTERDIMENSIONAL BEING KNOWN AS")
text_intro_03:
	db $20
	intro_text("ZORDON, CAME TO THE CITY OF ANGEL")
text_intro_04:
	db $23
	intro_text("GROVE TO ESTABLISH A VANGUARD IN THE.")
text_intro_05:
	db $22
	intro_text("NEVER ENDING STRUGGLE AGAINST EVIL.")
text_intro_06:
	db $1A
	intro_text("WITH THE AID OF HIS TRUSTED")
text_intro_07:
	db $23
	intro_text("ASSISTANT, ALPHA 5, THE NOBLE MASTER")
text_intro_08:
	db $1B
	intro_text("SOUGHT OUT SIX EXTRAORDINARY")
text_intro_09:
	db $23
	intro_text("TEENAGERS AND GAVE THEM THE POWER TO")
text_intro_10:
	db $23
	intro_text("TRANSFORM INTO A SUPERHUMAN FIGHTING")
text_intro_11:
	db $20
	intro_text("FORCE. IN TIME OF GREAT NEED, THE")
text_intro_12:
	db $1F
	intro_text("YOUNG HEROES COULD NOW CALL UPON")
text_intro_13:
	db $21
	intro_text("COLOSSAL ASSAULT VEHICLES KNOWN AS")
text_intro_14:
	db $21
	intro_text(""ZORDS". WHILE THE IDENTITY OF THE")
text_intro_15:
	db $23
	intro_text("SIX REMAINED A GUARDED SECRET, THEIR")
text_intro_16:
	break_line()
	db $22
	intro_text("COURAGEOUS EXPLOITS SOON BECAME THE")
text_intro_17:
	db $20
	intro_text("STUFF OF LEGEND, EARNING THEM THE")
text_intro_18:
	db $07
	intro_text("TITLE...")
		
	end()





