

static void naked_placement_in_RAM0_circle(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

void circle (void)
{
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();
    for (temp1 = 0; temp1 <= 360; temp1++)
    {
        //x = center_x + radius * cos(angle)
        //y = center_y + radius * sin(angle)

        radians = (float)degree2radian (temp1);

        gfx_x = screenCenterX + circleSize * mikeCOS(radians);
        gfx_y = screenCenterY + circleSize * mikeSIN(radians);
        rtunes_pixel();
    }
}


static void naked_placement_in_RAM0_line1(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
void line1 (void)
{
    float angleAdjust;
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 <= lineLength; temp1++)
    {
        angleAdjust = (360 - (360 + lineAngle) % 360);
        radians = (float)degree2radian (angleAdjust);

        gfx_x = screenCenterX + temp1 * mikeCOS(radians);
        gfx_y = screenCenterY + temp1 * mikeSIN(radians);

        rtunes_pixel();
    }
}

static void naked_placement_in_RAM0_lineCircle1(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
void lineCircle1 (void)
{
    float angleAdjust;
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 <= 360; temp1++)
    {
        //x = center_x + radius * cos(angle)
        //y = center_y + radius * sin(angle)

        radians = (float)degree2radian (temp1);

        gfx_x = screenCenterX + circleSize * mikeCOS(radians);
        gfx_y = screenCenterY + circleSize * mikeSIN(radians);
        rtunes_pixel();
    }

    for (temp1 = circleSize; temp1 <= lineLength + circleSize; temp1++)
    {
        //x = center_x + radius * cos(angle)
        //y = center_y + radius * sin(angle)

        //signed int LA2 = lineAngle;
        //signed int LA2 = 90 - lineAngle;
        //signed int LA2 = lineAngle - 180;
        //radians = (float)degree2radian (LA2);

        angleAdjust = (360 - (360 + lineAngle) % 360);
        radians = (float)degree2radian (angleAdjust);

        gfx_x = screenCenterX + temp1 * mikeCOS(radians);
        gfx_y = screenCenterY + temp1 * mikeSIN(radians);
        //gfx_x = screenCenterX + temp1 * mikeSIN(radians);
        //gfx_y = screenCenterY + temp1 * mikeCOS(radians);

        rtunes_pixel();
    }
}


static void naked_placement_in_RAM0_line3(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
//https://github.com/andydansby/z88dk-graphics-routines/blob/master/zxgraphics.c#L78
void line3 (void)
{
    int y1 = 0;
    int x1 = 0;
    int y2 = 0;
    int x2 = 0;
    int dy = 0;
    int dx = 0;
    int stepx = 0;
	int stepy = 0;
	int fraction = 0;
	int wait = 0;
	float angleAdjust = 0;

    y1 = screenCenterY;
    x1 = screenCenterX;

    angleAdjust = (360 - (360 + lineAngle) % 360);
    radians = (float)degree2radian (angleAdjust);
    y2 = screenCenterY + lineLength * mikeSIN(radians);
    x2 = screenCenterX + lineLength * mikeCOS(radians);

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
            for (wait = 0; wait < 3000; wait++){}
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
            for (wait = 0; wait < 3000; wait++){}
        }
     }
}

static void naked_placement_in_RAM0_lineCircle2(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
void lineCircle2 (void)
{
    int y1 = 0;
    int x1 = 0;
    int y2 = 0;
    int x2 = 0;
    int dy = 0;
    int dx = 0;
    int stepx = 0;
	int stepy = 0;
	int fraction = 0;
	int wait = 0;
	float angleAdjust = 0;

    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 <= 360; temp1++)
    {
        radians = (float)degree2radian (temp1);

        gfx_x = screenCenterX + circleSize * mikeCOS(radians);
        gfx_y = screenCenterY + circleSize * mikeSIN(radians);
        rtunes_pixel();
    }

    y1 = screenCenterY;
    x1 = screenCenterX;


    for (temp1 = circleSize; temp1 <= lineLength + circleSize; temp1++)
    {
        //y1 = temp1;
        //x1 = temp1;

        angleAdjust = (360 - (360 + lineAngle) % 360);
        radians = (float)degree2radian (angleAdjust);

        y2 = screenCenterY + temp1 * mikeSIN(radians);
        x2 = screenCenterX + temp1 * mikeCOS(radians);
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
                for (wait = 0; wait < 3000; wait++){}
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
                for (wait = 0; wait < 3000; wait++){}
            }
         }



        //gfx_x = screenCenterX + temp1 * mikeCOS(radians);
        //gfx_y = screenCenterY + temp1 * mikeSIN(radians);
        //rtunes_pixel();
    }

}



static void naked_placement_in_RAM0_lineSPAN(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
void line_SPAN (void)
{
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 < 360; temp1+=10)
    {
        for (temp2 = 0; temp2 <= lineLength; temp2++)
        {
            signed int LA2 = temp1;

            radians = degree2radian((float)LA2);

            //x = center_x + radius * cos(angle)
            //y = center_y + radius * sin(angle)
            //orig
            gfx_x = screenCenterX + temp2 * mikeCOS(radians);
            gfx_y = screenCenterY + temp2 * mikeSIN(radians);

            rtunes_pixel();
        }

    }

}

//////////////

static void naked_placement_in_RAM0_lineSPAN2(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
//https://github.com/andydansby/z88dk-graphics-routines/blob/master/zxgraphics.c#L78
void lineSPAN2 (void)
{
    int y1, x1;
    int y2, x2;
    int dy;
    int dx;
    int stepx;
	int stepy;
	int fraction = 0;
	float angleAdjust;

	for (temp1 = 0; temp1 < 360; temp1+=10)
    {
        y1 = screenCenterY;
        x1 = screenCenterX;
        //radians = (float)degree2radian (temp1);

        angleAdjust = (360 - (360 + temp1) % 360);
        radians = (float)degree2radian (angleAdjust);

        y2 = screenCenterY + lineLength * mikeSIN(radians);
        x2 = screenCenterX + lineLength * mikeCOS(radians);



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
        }//X majority
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
        }//end Y majority
    }//end angles
}







//==========================================================

//leave last line blank
//==========================================================


