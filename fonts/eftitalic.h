#include "../macros.h"

const char* const eftitalic_zero_0 = "\n";
const char* const eftitalic_zero_1 = "   _ \n";
const char* const eftitalic_zero_2 = " ,' \\\n";
const char* const eftitalic_zero_3 = "/ 0 /\n";
const char* const eftitalic_zero_4 = "\\_,' \n";

const char* const eftitalic_one_0 = "\n";
const char* const eftitalic_one_1 = "    _\n";
const char* const eftitalic_one_2 = "  ,'/\n";
const char* const eftitalic_one_3 = "  // \n";
const char* const eftitalic_one_4 = " //  \n";

const char* const eftitalic_two_0 = "\n";
const char* const eftitalic_two_1 = "  ___ \n";
const char* const eftitalic_two_2 = " /_  )\n";
const char* const eftitalic_two_3 = " ,'c' \n";
const char* const eftitalic_two_4 = "(___7 \n";

const char* const eftitalic_three_0 = "\n";
const char* const eftitalic_three_1 = "   ____\n";
const char* const eftitalic_three_2 = "  /_ ,'\n";
const char* const eftitalic_three_3 = " __/<  \n";
const char* const eftitalic_three_4 = "|__,'  \n";

const char* const eftitalic_four_0 = "\n";
const char* const eftitalic_four_1 = "     .\n";
const char* const eftitalic_four_2 = "   ,'/\n";
const char* const eftitalic_four_3 = " ,'o/ \n";
const char* const eftitalic_four_4 = "(___7 \n";

const char* const eftitalic_five_0 = "\n";
const char* const eftitalic_five_1 = "  ___\n";
const char* const eftitalic_five_2 = " / _/\n";
const char* const eftitalic_five_3 = " |_ \\\n";
const char* const eftitalic_five_4 = "/__,'\n";

const char* const eftitalic_six_0 = "\n";
const char* const eftitalic_six_1 = "\n";
const char* const eftitalic_six_2 = " ,'7\n";
const char* const eftitalic_six_3 = "/o \\\n";
const char* const eftitalic_six_4 = "|_,'\n";

const char* const eftitalic_seven_0 = "\n";
const char* const eftitalic_seven_1 = " ___\n";
const char* const eftitalic_seven_2 = "/_ /\n";
const char* const eftitalic_seven_3 = " // \n";
const char* const eftitalic_seven_4 = "//  \n";

const char* const eftitalic_eight_0 = "\n";
const char* const eftitalic_eight_1 = "   __ \n";
const char* const eftitalic_eight_2 = "  /o )\n";
const char* const eftitalic_eight_3 = ",'o | \n";
const char* const eftitalic_eight_4 = "|__,' \n";

const char* const eftitalic_nine_0 = "\n";
const char* const eftitalic_nine_1 = "  __ \n";
const char* const eftitalic_nine_2 = ",'o |\n";
const char* const eftitalic_nine_3 = "|_ / \n";
const char* const eftitalic_nine_4 = " //  \n";

const char* const eftitalic_twodots_0 = "\n";
const char* const eftitalic_twodots_1 = "\n ";
const char* const eftitalic_twodots_2 = " ()\n";
const char* const eftitalic_twodots_3 = "\n ";
const char* const eftitalic_twodots_4 = "() \n";

const char* const font_eftitalic[11][VEC_MAXSIZE] =
{
    { eftitalic_zero_0, eftitalic_zero_1, eftitalic_zero_2, eftitalic_zero_3, eftitalic_zero_4},
    { eftitalic_one_0, eftitalic_one_1, eftitalic_one_2, eftitalic_one_3, eftitalic_one_4},
    { eftitalic_two_0, eftitalic_two_1, eftitalic_two_2, eftitalic_two_3, eftitalic_two_4},
    { eftitalic_three_0, eftitalic_three_1, eftitalic_three_2, eftitalic_three_3, eftitalic_three_4},
    { eftitalic_four_0, eftitalic_four_1, eftitalic_four_2, eftitalic_four_3, eftitalic_four_4},
    { eftitalic_five_0, eftitalic_five_1, eftitalic_five_2, eftitalic_five_3, eftitalic_five_4},
    { eftitalic_six_0, eftitalic_six_1, eftitalic_six_2, eftitalic_six_3, eftitalic_six_4},
    { eftitalic_seven_0, eftitalic_seven_1, eftitalic_seven_2, eftitalic_seven_3, eftitalic_seven_4},
    { eftitalic_eight_0, eftitalic_eight_1, eftitalic_eight_2, eftitalic_eight_3, eftitalic_eight_4},
    { eftitalic_nine_0, eftitalic_nine_1, eftitalic_nine_2, eftitalic_nine_3, eftitalic_nine_4},
    { eftitalic_twodots_0, eftitalic_twodots_1, eftitalic_twodots_2, eftitalic_twodots_3, eftitalic_twodots_4}
};

int calculate_offset_eftitalic(int digit_1, int digit_2);
int offset_before_twodots_eftitalic(int num);
int offset_after_twodots_eftitalic(int num);
