static void naked_placement_in_RAM0_cosine(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

float mikeCOS (float xxx)
{
    return mikeSIN(M_PI_2 - xxx);
}
//==========================================================

//leave last line blank
//==========================================================


