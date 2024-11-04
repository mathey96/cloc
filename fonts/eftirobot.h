
const char* const eftirobot_zero_0 = "  _  \n";
const char* const eftirobot_zero_1 = " / \ \n";
const char* const eftirobot_zero_2 = "( 0 )\n";
const char* const eftirobot_zero_3 = " \_/ \n";

const char* const eftirobot_one_0 = " __ \n";
const char* const eftirobot_one_1 = "/_ |\n";
const char* const eftirobot_one_2 = " ( )\n";
const char* const eftirobot_one_3 = " /_\\n";

const char* const eftirobot_two_0 = " __  \n";
const char* const eftirobot_two_1 = "|_ | \n";
const char* const eftirobot_two_2 = " /(_ \n";
const char* const eftirobot_two_3 = "/___\\n";

const char* const eftirobot_three_0 = " ___\n";
const char* const eftirobot_three_1 = "|_ /\n";
const char* const eftirobot_three_2 = "__))\n";
const char* const eftirobot_three_3 = "\__/\n";

const char* const eftirobot_four_0 = "   . \n";
const char* const eftirobot_four_1 = "  /| \n";
const char* const eftirobot_four_2 = " /o) \n";
const char* const eftirobot_four_3 = "/___\\n";

const char* const eftirobot_five_0 = " ___\n";
const char* const eftirobot_five_1 = "| _/\n";
const char* const eftirobot_five_2 = " ) \\n";
const char* const eftirobot_five_3 = "/__/\n";

const char* const eftirobot_six_0 = "  _ \n";
const char* const eftirobot_six_1 = " // \n";
const char* const eftirobot_six_2 = "(o \\n";
const char* const eftirobot_six_3 = "\__/\n";

const char* const eftirobot_seven_0 = " ____\n";
const char* const eftirobot_seven_1 = "|_  /\n";
const char* const eftirobot_seven_2 = "  )) \n";
const char* const eftirobot_seven_3 = " /_\ \n";

const char* const eftirobot_eight_0 = " __ \n";
const char* const eftirobot_eight_1 = "(o )\n";
const char* const eftirobot_eight_2 = "/o \\n";
const char* const eftirobot_eight_3 = "\__/\n";

const char* const eftirobot_nine_0 = " __ \n";
const char* const eftirobot_nine_1 = "/o \\n";
const char* const eftirobot_nine_2 = "\_ )\n";
const char* const eftirobot_nine_3 = " /_/\n";

const char* const eftirobot_twodots_0 = " _ \n";
const char* const eftirobot_twodots_1 = "(_)\n";
const char* const eftirobot_twodots_2 = "(_)\n";
const char* const eftirobot_twodots_3 = "\n ";

const char* const font_eftirobot[11][VEC_MAXSIZE] = 
{
    { eftirobot_zero_0, eftirobot_zero_1, eftirobot_zero_2, eftirobot_zero_3},
    { eftirobot_one_0, eftirobot_one_1, eftirobot_one_2, eftirobot_one_3},
    { eftirobot_two_0, eftirobot_two_1, eftirobot_two_2, eftirobot_two_3},
    { eftirobot_three_0, eftirobot_three_1, eftirobot_three_2, eftirobot_three_3},
    { eftirobot_four_0, eftirobot_four_1, eftirobot_four_2, eftirobot_four_3},
    { eftirobot_five_0, eftirobot_five_1, eftirobot_five_2, eftirobot_five_3},
    { eftirobot_six_0, eftirobot_six_1, eftirobot_six_2, eftirobot_six_3},
    { eftirobot_seven_0, eftirobot_seven_1, eftirobot_seven_2, eftirobot_seven_3},
    { eftirobot_eight_0, eftirobot_eight_1, eftirobot_eight_2, eftirobot_eight_3},
    { eftirobot_nine_0, eftirobot_nine_1, eftirobot_nine_2, eftirobot_nine_3},
    { eftirobot_twodots_0, eftirobot_twodots_1, eftirobot_twodots_2, eftirobot_twodots_3}
}

int calculate_offset_eftirobot(int digit_1, int digit_2);
int offset_before_twodots_eftirobot(int num); 
int offset_after_twodots_eftirobot(int num);
