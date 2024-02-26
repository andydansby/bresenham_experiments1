static void naked_placement_in_RAM0_bresenham(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
//https://github.com/andydansby/z88dk-graphics-routines/blob/master/zxgraphics.c#L78
void bresenham (int x1, int y1, int x2, int y2)
{
    int fraction = 0;
	float angleAdjust = 0;

    int dy = y2 - y1;
    int dx = x2 - x1;
    int stepy = (dy < 0) ? -1 : 1;
    int stepx = (dx < 0) ? -1 : 1;

    dx = ABS(dx);
    dy = ABS(dy);

	//plot starting point
    gfx_x = x1;
    gfx_y = y1;
    rtunes_pixel();

    if (dx > dy)
    {
        fraction = dy - (dx >> 1);
        while (x1 != x2)
        {
            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();

            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= dx;
            }
            x1 += stepx;
            fraction += dy;
        }
    }
    else
    {
        fraction = dx - (dy >> 1);
        while (y1 != y2)
        {
            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();

            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= dy;
            }
            y1 += stepy;
            fraction += dx;
        }
    }
}


static void naked_placement_in_RAM0_bresenham0(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
//https://github.com/andydansby/z88dk-graphics-routines/blob/master/zxgraphics.c#L78
void bresenham0 (int x1, int y1, int x2, int y2)
{
    int dy = 0;
    int dx = 0;
    int stepx = 0;
	int stepy = 0;
	int fraction = 0;
	int wait = 0;
	float angleAdjust = 0;

    dy = y2 - y1;
    dx = x2 - x1;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

    //plot starting point
    gfx_x = x1;
    gfx_y = y1;
    rtunes_pixel();

    if (dx > dy)
    {
        fraction = dy - (dx >> 1);	// same as 2*dy - dx
        while (x1 != x2)
        {
           if (fraction >= 0)
           {
               y1 += stepy;
               fraction -= dx;	// same as fraction -= 2*dx
           }
            x1 += stepx;
            fraction += dy;	// same as fraction -= 2*dy

            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();
        }
    }
    else
    {
		fraction = dx - (dy >> 1);
		while (y1 != y2)
		{
			if (fraction >= 0)
			{
				x1 += stepx;
				fraction -= dy;
			}
			y1 += stepy;
            fraction += dx;

            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();
        }
    }
}





static void naked_placement_in_RAM0_bresenham_slow(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

void bresenham_slow (int x1, int y1, int x2, int y2)
{
    int dy = 0;
    int dx = 0;
    int stepx = 0;
	int stepy = 0;
	int fraction = 0;
	int wait = 0;
	float angleAdjust = 0;

    dy = y2 - y1;
    dx = x2 - x1;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

    //plot starting point
    gfx_x = x1;
    gfx_y = y1;
    rtunes_pixel();

    if (dx > dy)
    {
        fraction = dy - (dx >> 1);	// same as 2*dy - dx
        while (x1 != x2)
        {
            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= dx;	// same as fraction -= 2*dx
            }
            x1 += stepx;
            fraction += dy;	// same as fraction -= 2*dy

            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();
            for (wait = 0; wait < 6000; wait++){}
        }
    }
    else
    {
		fraction = dx - (dy >> 1);
        while (y1 != y2)
        {
            if (fraction >= 0)
			{
                x1 += stepx;
				fraction -= dy;
            }
			y1 += stepy;
            fraction += dx;

            gfx_x = x1;
            gfx_y = y1;
            rtunes_pixel();
            for (wait = 0; wait < 6000; wait++){}
        }
    }
}
