// checks for correct #undef
#ifdef P
	#error P must be undefined
#endif

#ifdef R 
	#error R must be undefined
#endif

#ifdef S 
	#error S must be undefined
#endif

#define P 0xF000
#define R 0x9000

unsigned short RCircle[81] = {
	0,0,0,P,P,P,0,0,0,
	0,0,P,P,P,P,P,0,0,
	0,P,P,P,P,P,P,P,0,
	P,P,P,P,P,P,P,P,R,
	P,P,P,P,P,P,P,P,R,
	P,P,P,P,P,P,P,P,R,
	0,P,P,P,P,P,P,R,0,
	0,0,P,P,P,P,R,0,0,
	0,0,0,R,R,R,0,0,0};

#undef P
#undef R

#define P 0xFFFE0000
#define R 0xFF990000

unsigned int RCircle32[81] = {
	0,0,0,P,P,P,0,0,0,
	0,0,P,P,P,P,P,0,0,
	0,P,P,P,P,P,P,P,0,
	P,P,P,P,P,P,P,P,R,
	P,P,P,P,P,P,P,P,R,
	P,P,P,P,P,P,P,P,R,
	0,P,P,P,P,P,P,R,0,
	0,0,P,P,P,P,R,0,0,
	0,0,0,R,R,R,0,0,0};

#undef P
#undef R

#define P 0xffff
#define R 0x9bef
#define S 0x8bef

unsigned short FCDigit[1040] = { //720
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,P,P,P,P,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,P,0,
	0,0,0,P,0,0,
	0,0,P,0,0,0,
	0,P,0,0,0,0,
	P,0,0,0,0,0,

	0,P,P,P,0,0,
	P,0,0,P,P,0,
	P,0,P,0,P,0,
	P,P,0,0,P,0,
	0,P,P,P,0,0,

	0,P,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,P,P,P,P,0,

	0,P,P,P,0,0,
	P,0,0,P,P,0,
	0,0,P,P,0,0,
	0,P,P,0,0,0,
	P,P,P,P,P,0,

	P,P,P,P,0,0,
	0,0,0,P,P,0,
	0,P,P,P,0,0,
	0,0,0,P,P,0,
	P,P,P,P,0,0,

	0,P,P,P,0,0,
	P,0,P,P,0,0,
	P,P,P,P,P,0,
	0,0,P,P,0,0,
	0,P,P,P,P,0,

	P,P,P,P,P,0,
	P,0,0,0,0,0,
	P,P,P,P,0,0,
	0,0,0,P,P,0,
	P,P,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,0,0,0,
	P,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,
	
	P,P,P,P,P,0,
	0,0,0,P,P,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,P,0,
	0,0,0,P,P,0,
	0,P,P,P,0,0,

	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	0,P,0,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,

	P,P,0,0,
	P,0,P,0,
	P,P,0,0,
	P,0,P,0,
	P,P,0,0,

	0,P,0,0,
	P,0,P,0,
	P,0,0,0,
	P,0,P,0,
	0,P,0,0,

	P,P,0,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,P,0,0,

	P,P,P,0,
	P,0,0,0,
	P,P,0,0,
	P,0,0,0,
	P,P,P,0,

	P,P,P,0,
	P,0,0,0,
	P,P,0,0,
	P,0,0,0,
	P,0,0,0,

	0,P,P,0,
	P,0,0,P,
	P,R,P,0,
	P,0,P,0,
	P,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,

	P,P,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,
	P,P,P,0,

	0,P,P,P,
	0,0,P,0,
	0,0,P,0,
	P,0,P,0,
	0,P,P,0,

	P,0,P,0,
	P,0,P,0,
	P,P,0,0,
	P,0,P,0,
	P,0,P,0,

	P,0,0,0,
	P,0,0,0,
	P,0,0,0,
	P,0,P,0,
	P,P,P,0,

	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,

	P,0,0,P,
	P,R,0,P,
	P,P,R,P,
	P,R,P,P,
	P,0,R,P,

	0,P,0,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	0,P,0,0,

	P,P,R,0,
	P,0,P,0,
	P,P,R,0,
	P,0,0,0,
	P,0,0,0,

	0,P,0,0,
	P,0,P,0,
	P,R,P,0,
	P,0,P,0,
	0,P,0,P,

	P,P,R,0,
	P,0,P,0,
	P,P,R,0,
	P,0,P,0,
	P,0,P,0,

	0,P,P,0,
	P,0,0,0,
	0,P,0,0,
	0,0,P,0,
	P,P,0,0,

	P,P,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	R,P,R,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	0,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,

	P,0,P,0,
	P,0,P,0,
	0,P,0,0,
	P,0,P,0,
	P,0,P,0,

	P,0,P,0,
	P,0,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,

	P,P,P,0,
	0,0,P,0,
	0,P,0,0,
	P,0,0,0,
	P,P,P,0,

	0,P,0,0,
	S,P,S,0,
	P,P,P,0,
	0,0,0,0,
	0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	P,P,P,0,
	S,P,R,0,
	0,P,0,0,

	0,0,P,0,
	0,P,P,0,
	P,P,P,0,
	0,P,P,0,
	0,0,P,0,

	P,0,0,0,
	P,P,0,0,
	P,P,P,0,
	P,P,0,0,
	P,0,0,0

};

#undef P
#undef R
#undef S

#define P 0xFFFFFFFF
#define R 0xFF7F7F7F

unsigned int FCDigit32[1040] = { //720
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,P,P,P,P,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,P,0,
	0,0,0,P,0,0,
	0,0,P,0,0,0,
	0,P,0,0,0,0,
	P,0,0,0,0,0,

	0,P,P,P,0,0,
	P,0,0,P,P,0,
	P,0,P,0,P,0,
	P,P,0,0,P,0,
	0,P,P,P,0,0,

	0,P,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,P,P,P,P,0,

	0,P,P,P,0,0,
	P,0,0,P,P,0,
	0,0,P,P,0,0,
	0,P,P,0,0,0,
	P,P,P,P,P,0,

	P,P,P,P,0,0,
	0,0,0,P,P,0,
	0,P,P,P,0,0,
	0,0,0,P,P,0,
	P,P,P,P,0,0,

	0,P,P,P,0,0,
	P,0,P,P,0,0,
	P,P,P,P,P,0,
	0,0,P,P,0,0,
	0,P,P,P,P,0,

	P,P,P,P,P,0,
	P,0,0,0,0,0,
	P,P,P,P,0,0,
	0,0,0,P,P,0,
	P,P,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,0,0,0,
	P,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,
	
	P,P,P,P,P,0,
	0,0,0,P,P,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,
	0,0,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,0,0,

	0,P,P,P,0,0,
	P,P,0,P,P,0,
	0,P,P,P,P,0,
	0,0,0,P,P,0,
	0,P,P,P,0,0,

	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,
	0,0,P,0,0,0,
	0,0,0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	0,P,0,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,

	P,P,0,0,
	P,0,P,0,
	P,P,0,0,
	P,0,P,0,
	P,P,0,0,

	0,P,0,0,
	P,0,P,0,
	P,0,0,0,
	P,0,P,0,
	0,P,0,0,

	P,P,0,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,P,0,0,

	P,P,P,0,
	P,0,0,0,
	P,P,0,0,
	P,0,0,0,
	P,P,P,0,

	P,P,P,0,
	P,0,0,0,
	P,P,0,0,
	P,0,0,0,
	P,0,0,0,

	0,P,P,0,
	P,0,0,P,
	P,R,P,0,
	P,0,P,0,
	P,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,

	P,P,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,
	P,P,P,0,

	0,P,P,P,
	0,0,P,0,
	0,0,P,0,
	P,0,P,0,
	0,P,P,0,

	P,0,P,0,
	P,0,P,0,
	P,P,0,0,
	P,0,P,0,
	P,0,P,0,

	P,0,0,0,
	P,0,0,0,
	P,0,0,0,
	P,0,P,0,
	P,P,P,0,

	P,0,P,0,
	P,P,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,

	P,0,0,P,
	P,R,0,P,
	P,P,R,P,
	P,R,P,P,
	P,0,R,P,

	0,P,0,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	0,P,0,0,

	P,P,R,0,
	P,0,P,0,
	P,P,R,0,
	P,0,0,0,
	P,0,0,0,

	0,P,0,0,
	P,0,P,0,
	P,R,P,0,
	P,0,P,0,
	0,P,0,P,

	P,P,R,0,
	P,0,P,0,
	P,P,R,0,
	P,0,P,0,
	P,0,P,0,

	0,P,P,0,
	P,0,0,0,
	0,P,0,0,
	0,0,P,0,
	P,P,0,0,

	P,P,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	R,P,R,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	0,P,0,0,

	P,0,P,0,
	P,0,P,0,
	P,0,P,0,
	P,P,P,0,
	P,0,P,0,

	P,0,P,0,
	P,0,P,0,
	0,P,0,0,
	P,0,P,0,
	P,0,P,0,

	P,0,P,0,
	P,0,P,0,
	0,P,0,0,
	0,P,0,0,
	0,P,0,0,

	P,P,P,0,
	0,0,P,0,
	0,P,0,0,
	P,0,0,0,
	P,P,P,0,

	0,P,0,0,
	R,P,R,0,
	P,P,P,0,
	0,0,0,0,
	0,0,0,0,

	0,0,0,0,
	0,0,0,0,
	P,P,P,0,
	R,P,R,0,
	0,P,0,0,

	0,0,P,0,
	0,P,P,0,
	P,P,P,0,
	0,P,P,0,
	0,0,P,0,

	P,0,0,0,
	P,P,0,0,
	P,P,P,0,
	P,P,0,0,
	P,0,0,0

};

#undef P
#undef R

unsigned short FCColor [2][5] = {{0x001F,0x07E0,0xF800,0x03FF,0xFC00},{0x001F,0x03E0,0x7C00,0x021F,0x7DE0}};
unsigned int FCColor32 [5] = {0xFF0000FF,0xFF00FF00,0xFFFF0000,0xFF007FFF,0xFFFF8000};