#ifndef _COBOL_EVALUATE
#define _COBOL_EVALUATE

#define EVALUATE(X) switch(X) {
#define WHEN(X,Y) case (X):\
	{ Y; }\
	break;
#define WHEN_OTHER(X) default:\
	{ X; }\
	break;
#define END_EVALUATE }

#endif
