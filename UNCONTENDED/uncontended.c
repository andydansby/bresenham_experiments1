// using sdcc_iy 1.99c
//moving over to sdcc
//attention, need -lm in the compiling string

#pragma printf "%f %ld %d %c"//attention temp
#pragma scanf %f

//https://web.archive.org/web/20171228230531/http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648

//Using advise from Stefan
//moved Stack pointer from $BFFF to $C000 as
//Stack automatically decrements before useage
// see zpragma.inc in Uncontended




#include "define.h"


#include <arch/zx.h>
#include <stdio.h>//standard input output
#include <stdlib.h>//standard library
#include <input.h>//used for detecting key inputs
#include <float.h>
#include <math.h>


#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);

#include "externs.h"    //references to asm functions
#include "variables.h"

#include "uncontended.h"
#include "functions.h"

#include "key_press.c"


void main ()
{
    //new
    SETUP_IM2();// set up for the interrupt MODE 2
    // this will point the I register to IM2 Vector

    xorshift_prng ();//generate a Pseudo Random number
    random_number_16 = random_number_16 % (255 + 1 - 0) + 0;
    printf("\x16\x01\x02");
    printf ("random number =  %d \n", random_number_16);
    printf ("\n");

    while (1)
    {
        zx_cls(PAPER_WHITE);
        //printf("\x16\x01\x02");//ok
        printf("\x16\x01\x01");
        printf ("Welcome to the Circle&Line Test");
        printf ("\n\n");
        printf ("All Lines and circles are\n");
        printf ("drawn from Center screen\n");

        printf ("\n\n");

        printf ("Q Change circle size  = %d", circleSize);
        printf ("\n");
        printf ("W Line Length   = %d", lineLength);
        printf ("\n");
        printf ("E Line Angle   = %d", lineAngle);
        printf ("\n\n");


        printf ("A-Plot");
        printf ("\n");
        printf ("S-Circle");
        printf ("\n");
        printf ("D-Line using SIN/COS");
        printf ("\n");
        printf ("F-Line using SIN/COS outside");
        printf ("\n");
        printf ("G-Bresenham Line");
        printf ("\n");
        printf ("H-Line using Bresenham outside");

        printf ("\n\n");
        printf ("Z-Line Span using SIN/COS");
        printf ("\n");
        printf ("X-Line Span using Bresenham");
        printf ("\n");
        printf ("M-Span using Bresenham outside");

        Keypress();
    }







    {//using Z88dk built in functions
        //x_coordinate = 128;
        //y_coordinate = 47;
        //plot(x_coordinate, y_coordinate);
    }
    {
        //x_coordinate = 128;
        //y_coordinate = 47;
        //rtunes_plot(x_coordinate, y_coordinate);
        //rtunes_pixelRoutine();
    }



}

// must have blank line at end
