static void naked_placement_in_RAM0_sine(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}
//attention, need -lm in the compiling string
float mikeSIN (float xxx)
{
    ///<summary>
    /// this is an SINE estimation function
    /// Input is a floating point number between -1 amd 1
    /// going outside that range will produce bad results
    /// Output in Radians from -M_PI to +M_PI
    /// this function is originally found at
    ///  https://web.archive.org/web/20171228230531/http://forum.devmaster.net/t/fast-and-accurate-sine-cosine/9648
    ///<summary>

    //precalculated values
    const float B = 1.273;  // == 4 / PI;
    const float C = 0.405;  // == -4 /(PI*PI);
    float sin, BCalc, CCalc;

    if (xxx < -M_PI)
        xxx += M_PI * 2;
    else
    if (xxx > M_PI)
        xxx -= M_PI * 2;

    CCalc = C * xxx * xxx;
    BCalc = B * xxx;

    if (xxx < 0)
        sin = BCalc + CCalc;
    else
        sin = BCalc - CCalc;

    return sin;
}
//==========================================================
//leave last line blank
//==========================================================



