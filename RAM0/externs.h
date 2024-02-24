#ifndef EXTERNS_H
#define EXTERNS_H

//RAM 0
    extern unsigned char buffer_plotX;
    extern unsigned char buffer_plotY;
    extern void buffer_plot (void) __z88dk_fastcall;

    extern float radians;
    extern unsigned int temp1;
    extern unsigned int temp2;
    extern unsigned int x;
    extern unsigned int y;


    extern unsigned const screenCenterX;
    extern unsigned const screenCenterY;
    extern unsigned char circleSize;
    extern unsigned char temp;


    extern unsigned char lineLength;
    extern unsigned int lineAngle;

    extern unsigned int gfx_xy;
    extern unsigned char gfx_x;
    extern unsigned char gfx_y;
    extern void rtunes_pixel (void) __z88dk_fastcall;

    //routines.c:46: error 20: Undefined identifier 'screenCenterX'
    //routines.c:46: error 20: Undefined identifier 'circleSize'
    //routines.c:47: error 20: Undefined identifier 'screenCenterY'
    //routines.c:47: error 20: Undefined identifier 'circleSize'
    //routines.c:39: error 20: Undefined identifier 'temp'

#endif
