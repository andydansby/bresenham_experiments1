// using sdcc80 1.99c

// assembly files are in ram0Z.asm as
// indicated by ramMain.lst

// this has been pushed to zpragma.inc
//#pragma output CRT_ORG_CODE = 49152

//be sure to bank to this slot if you
//plan on using other banks

//we are just putting functions here

//PLACE ASSEMBLY VARIABLES HERE
//HAVE AT LEAST ONE VARIABLE DEFINED AS AN ASM VARIABLE

//if this is before any custom headers
//it will set everything below it to be
//in the correct memory slot


static void naked_placement_in_RAM0(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

# define M_PI		3.14159	// pi
# define M_PI_2		1.57079	// pi/2
# define M_PIx2          M_PI + M_PI
# define degree2radian(degrees) ((degrees) * M_PI / 180.0)  //#define degree2radian(a) (a * 0.0174
# define radian2degree(radians) ((radians) * 180.0 / M_PI)  //#define radian2degree(a) (a * 57.2957)
//# define ABS(N) ((N<0)?(-N):(N))
#define ABS(N) (((N) < 0) ? (-N) : (N))

#include "externs.h"
#include "variables.h"
#include "ram0.h"

#include "menu_options.c"

#include "math_sine.c"
#include "math_cosine.c"

#include "bresenham.c"

#include "routines.c"

// do not have main() here at all since
// we are just compiling to object files
// you will get a RET inserted automatically



//must have blank line at end
