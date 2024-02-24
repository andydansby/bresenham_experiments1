
void slomo (void)
{
    unsigned int temp;
    for (temp = 0; temp < 20000; temp++)
    {
    }
}
void slomo2 (void)
{
    unsigned int temp;
    for (temp = 0; temp < 50000; temp++)
    {
    }
}


void press_Q (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    in_wait_nokey();

    printf("\x16\x01\x02");



    printf ("Enter Radius \n");
    scanf("%s", &string);
    circleSize = atof(string);

    if (circleSize > 95)
        circleSize = 95;
    printf ("\nCircle Radius = %d \n",circleSize);
}

void press_W (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    in_wait_nokey();

    printf("\x16\x01\x02");

    printf ("Enter Line Length \n");
    scanf("%s", &string);
    lineLength = atof(string);

    if (lineLength > 64)
        lineLength = 64;
    printf ("\nLine Length = %d \n",lineLength);
}

void press_E (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    in_wait_nokey();

    printf("\x16\x01\x02");

    printf ("Enter Line Angle 0 - 359 \n");
    scanf("%s", &string);
    lineAngle = atof(string);

    if (lineAngle > 359)
        lineAngle = 359;
    printf ("\nLine Length = %d \n",lineAngle);
}


void press_A (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    rtunes_pixel();

    slomo2 ();
    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_S (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    circle();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_D (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    line1();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}


void press_F (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    lineCircle1();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_G (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    line3();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_H (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    lineCircle2();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_Z (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;
    line_SPAN();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}

void press_X (void)
{
    zx_cls(PAPER_WHITE | INK_BLUE);
    zx_border (2);

    set_attributes();

    in_wait_nokey();

    //buffer_plotX = screenCenterX;
    //buffer_plotY = screenCenterY;
    //buffer_plot();
    gfx_x = screenCenterX;
    gfx_y = screenCenterY;

    lineSPAN2();

    slomo2 ();

    printf("\x16\x01\x02");
    printf ("Press a Key");
    in_wait_key ();
}






void Keypress (void)
{
    while (1)
    {
        if (in_key_pressed( IN_KEY_SCANCODE_q ))    //set Radius
		{
		    press_Q();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_w ))    //set Radius
		{
		    press_W();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_e ))    //draw pixel
		{
		    press_E();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_a ))    //draw pixel
		{
		    press_A();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_s ))    //draw circle
		{
		    press_S();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_d ))    //draw line using sin/cos
		{
		    press_D();
		    slomo ();
			break;
		}
		if (in_key_pressed( IN_KEY_SCANCODE_f ))    //draw line using sin/cos
		{
		    press_F();
		    slomo ();
			break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_g ))    //draw line using sin/cos
		{
		    press_G();
		    slomo ();
			break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_h ))    //draw line using sin/cos
		{
		    press_H();
		    slomo ();
			break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_z ))    //draw line using sin/cos
		{
		    press_Z();
		    slomo ();
			break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_x ))    //draw line using sin/cos
		{
		    press_X();
		    slomo ();
			break;
		}

    }
}



