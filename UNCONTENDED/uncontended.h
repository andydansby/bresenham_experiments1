#ifndef UNCONTENDED_H
#define UNCONTENDED_H

//#include "non_working.h"


//UNCONTENDED RAM

//https://developer.download.nvidia.com/cg/abs.html


void dummyWait(void)
{
    for (temp5=0; temp5 < 4000; temp5++)
    {    }
}

void degree2radian2(void)
{
    radians = (float)degrees * (M_PI / 180.0);
}


void radian2degree2(void)
{
    degrees = radians * (180.0 / M_PI);
}


///////////////////////////////////////////


float wrap (float xx )
{
    return xx - 6.28 * floor(xx / 6.28 + 0.5);//          1 = 4180 to 10 = 4680
}



void rtunes_pixelRoutine (void)
{
    //zx_cls(PAPER_WHITE | INK_BLACK);
    for (yy = 0; yy < 192; yy++)
    {
        for (xx = 0; xx < 255 ; xx++)
        {
            gfx_xy = (yy << 8) | xx;
            rtunes_pixel();
        }
    }
}

void rtunes_plot(unsigned char x, unsigned char y)
{
    if (x > 254)
        x = 254;
    if (y > 190)
        y = 190;

    gfx_xy = (y << 8) | x;
    rtunes_pixel();

}

void plot(unsigned char x, unsigned char y)
{
    *zx_pxy2saddr(x,y) |= zx_px2bitmask(x);
}



#endif
