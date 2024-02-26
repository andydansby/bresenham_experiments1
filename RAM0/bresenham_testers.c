// bresenham
void line1 (void)
{
    float angleAdjust;
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 <= lineLength; temp1++)
    {
        radians = (float)degree2radian (lineAngle);
        gfx_x = screenCenterX + temp1 * mikeCOS(radians);
        gfx_y = screenCenterY + temp1 * mikeSIN(radians);

        rtunes_pixel();
    }
}

/////////////////////////////////

void line1 (void)
{
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    for (temp1 = 0; temp1 <= lineLength; temp1++)
    {
        signed int LA2 = lineAngle - 180;
        radians = (float)degree2radian (LA2);

        //x = center_x + radius * cos(angle)
        //y = center_y + radius * sin(angle)
        //orig
        gfx_x = screenCenterX + temp1 * mikeCOS(radians);
        gfx_y = screenCenterY + temp1 * mikeSIN(radians);

        rtunes_pixel();
    }
}

/////////////////////////////////

void original(void)
{
    //https://dgp.toronto.edu/~karan/courses/csc418/lectures/BRESENHAM.HTML
    dy = y2-y1;
    dx = x2-x1;
    y = y1;
    f = 2*dy-dx;
    incrE = 2*dy;
    incrNE = 2*(dy-dx);

    plot(x1,y1);
    for (x=x1+1; x< x++)
    {
        plot(x,y);
        if (f > 0)
        {
            y = y+1;
            f = f + incrNE;
        }
        else
        f = f + incrE;
    }
    plot(x2,y2);                        /* <------------ */
}

/////////////////////////////////

void line3_junk (void)
{
    signed int dy;//destination Y
    signed int dx;//destination X
    signed int y;
    signed int x = 0;
    signed int x1;
    signed int x2;
    signed int y1;
    signed int y2;

    signed int f;
    signed int incrE;
    signed int incrNE;

    y1 = screenCenterY;
    x1 = screenCenterX;

    radians = (float)degree2radian (lineAngle);
    y2 = screenCenterY + lineLength * mikeSIN(radians);
    x2 = screenCenterX + lineLength * mikeCOS(radians);

    dy = y2 - y1;
    dx = x2 - x1;

    y = y1;
    f = 2 * dy-dx;

    incrE = 2 * dy;
    incrNE = 2 * (dy-dx);

    //plot starting point
    gfx_x = x1;
    gfx_y = y1;
    rtunes_pixel();

    //plot end point
    gfx_x = x2;
    gfx_y = y2;
    rtunes_pixel();

    for (x = x1; x <= x2; x++)
    {
        gfx_x = x;
        gfx_y = y;
        rtunes_pixel();

        if (f > 0)
        {
            y = y + 1;
            f = f + incrNE;
        }
        else
        {
            f = f + incrE;
        }
    }
    //gfx_x = x2;
    //gfx_y = y2;
    //rtunes_pixel();
}

/////////////////////////////////

plot_line (int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = dx + dy, e2; /* error value e_xy */

  for (;;){  /* loop */
    setPixel (x0,y0);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

/////////////////////////////////

void line3 (void)
{
    signed int dx;//destination X
    signed int dy;//destination Y

    signed int x0;
    signed int x1;
    signed int y0;
    signed int y1;

    signed int sx = 0;
    signed int sy = 0;

    signed int err;
    signed int e2;



    y0 = screenCenterY;
    x0 = screenCenterX;

    radians = (float)degree2radian (lineAngle);
    y1 = screenCenterY + lineLength * mikeSIN(radians);
    x1 = screenCenterX + lineLength * mikeCOS(radians);


    dx =  ABS (x1 - x0);
    dy = -ABS (y1 - y0);
    sx = x0 < x1 ? 1 : -1;
    sy = y0 < y1 ? 1 : -1;

    err = dx + dy;

    //plot starting point
    gfx_x = x0;
    gfx_y = y0;
    rtunes_pixel();

    //plot end point
    gfx_x = x1;
    gfx_y = y1 ;
    rtunes_pixel();

    for (;;)
    {
        //setPixel (x0,y0);
        gfx_x = x0;
        gfx_y = y0;
        rtunes_pixel();

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        e2 = 2 * err;

        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        } // e_xy+e_x > 0


        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        } // e_xy+e_y < 0
    }

    //gfx_x = x2;
    //gfx_y = y2;
    //rtunes_pixel();
}

/////////////////////////////////

void ZXLine(int x1, int y1, int x2, int y2, unsigned char colour, unsigned char plotUnplot)
{
    int dy = y2 - y1;
    int dx = x2 - x1;

    int stepx;
	int stepy;
	int fraction = 0;

    if (dy < 0) { dy = -dy;  stepy = -1; } else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; } else { stepx = 1; }
    dy <<= 1;        // dy is now 2*dy
    dx <<= 1;        // dx is now 2*dx

    ZXplot(x1,y1, colour);

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

		   ZXplot(x1, y1, colour);

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

		   ZXplot(x1, y1);


        }
     }
}

/////////////////////////////////

void line3 (void)
{
    int y1, x1;
    int y2, x2;
    int dy;
    int dx;
    int stepx;
	int stepy;
	int fraction = 0;
	int wait = 0;

    y1 = screenCenterY;
    x1 = screenCenterX;

    radians = (float)degree2radian (lineAngle);

    y2 = screenCenterY + lineLength * -mikeSIN(radians) * M_PI_2;
    x2 = screenCenterX + lineLength * mikeCOS(radians) * M_PI_2;

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

/////////////////////////////////

//https://github.com/andydansby/z88dk-graphics-routines/blob/master/zxgraphics.c#L78
void line3 (void)
{
    int y1, x1;
    int y2, x2;
    int dy;
    int dx;
    int stepx;
	int stepy;
	int fraction = 0;
	int wait = 0;

    y1 = screenCenterY;
    x1 = screenCenterX;

    radians = (float)degree2radian (lineAngle);

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

/////////////////////////////////

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

/////////////////////////////////

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

    //draw circle
    for (temp1 = 0; temp1 <= 360; temp1++)
    {
        radians = (float)degree2radian (temp1);

        gfx_x = screenCenterX + circleSize * mikeCOS(radians);
        gfx_y = screenCenterY + circleSize * mikeSIN(radians);
        rtunes_pixel();
    }//end draw circle

    //y1 = screenCenterY;
    //x1 = screenCenterX;
    //y1 = circleSize;
    //x1 = circleSize;
    //y1 = screenCenterY * mikeSIN(radians) + circleSize;
    //x1 = screenCenterX * mikeCOS(radians) + circleSize;




    //precalculate y2 and x2
    angleAdjust = (360 - (360 + lineAngle) % 360);
    radians = (float)degree2radian (angleAdjust);


    y1 = screenCenterY;
    x1 = screenCenterX;

    y2 = screenCenterY + circleSize * mikeSIN(radians);
    x2 = screenCenterX + circleSize * mikeCOS(radians);

    //march to outside to calculate x1 and y1
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



    int y = y0;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int slope = 2 * dy;
    int error = -dx;
    int errorInc = -2 * dx;

		for (int x = x0; x <= x1; ++x)
		{
			gfx.setPixel(x, y, Color(255, 255, 255));
			error += slope;

			if (error >= 0)
			{
				y++;
				error += errorInc;
			}
		}
		gfx.render();





void bresen_short (void)
{
    int x1;
    int x2;
    int y1;
    int y2;
    int angleAdjust;

    //draw circle
    for (temp1 = 0; temp1 <= 360; temp1++)
    {
        radians = (float)degree2radian (temp1);

        gfx_x = screenCenterX + circleSize * mikeCOS(radians);
        gfx_y = screenCenterY + circleSize * mikeSIN(radians);
        rtunes_pixel();
    }

    //set parameters for start and end points
    {
        y1 = screenCenterY;
        x1 = screenCenterX;
        angleAdjust = (360 - (360 + lineAngle) % 360);
        radians = (float)degree2radian (angleAdjust);
        y2 = screenCenterY + lineLength * mikeSIN(radians);
        x2 = screenCenterX + lineLength * mikeCOS(radians);
    }

    //draw line
    {
        bresenham (x1, y1, x2, y2);
    }



    //gfx_x = x0;
    //gfx_y = y0;
    //rtunes_pixel();
}












