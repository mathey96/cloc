
const char* const eftifont_zero_0 = "  _  \n";
const char* const eftifont_zero_1 = " / \\ \n";
const char* const eftifont_zero_2 = "| 0 |\n";
const char* const eftifont_zero_3 = " \\_/ \n";

const char* const eftifont_one_0 = " _ \n";
const char* const eftifont_one_1 = "/o|\n";
const char* const eftifont_one_2 = " ||\n";
const char* const eftifont_one_3 = " L|\n";

const char* const eftifont_two_0 = " __ \n";
const char* const eftifont_two_1 = "[o )\n";
const char* const eftifont_two_2 = " /( \n";
const char* const eftifont_two_3 = "/__|\n";

const char* const eftifont_three_0 = " ___\n";
const char* const eftifont_three_1 = "|_ /\n";
const char* const eftifont_three_2 = "__)\\\n";
const char* const eftifont_three_3 = "\\__/\n";

const char* const eftifont_four_0 = "   . \n";
const char* const eftifont_four_1 = "  /| \n";
const char* const eftifont_four_2 = " /o| \n";
const char* const eftifont_four_3 = "L___|\n";

const char* const eftifont_five_0 = " __ \n";
const char* const eftifont_five_1 = "| _/\n";
const char* const eftifont_five_2 = "\\_ \\\n";
const char* const eftifont_five_3 = "|__/\n";

const char* const eftifont_six_0 = "  _ \n";
const char* const eftifont_six_1 = " // \n";
const char* const eftifont_six_2 = "/o \\\n";
const char* const eftifont_six_3 = "\\__/\n";

const char* const eftifont_seven_0 = " ____\n";
const char* const eftifont_seven_1 = "|__ /\n";
const char* const eftifont_seven_2 = "  // \n";
const char* const eftifont_seven_3 = " //  \n";

const char* const eftifont_eight_0 = " __ \n";
const char* const eftifont_eight_1 = "(o )\n";
const char* const eftifont_eight_2 = "/o \\\n";
const char* const eftifont_eight_3 = "\\__/\n";

const char* const eftifont_nine_0 = " __ \n";
const char* const eftifont_nine_1 = "/o \\\n";
const char* const eftifont_nine_2 = "\\_ /\n";
const char* const eftifont_nine_3 = " // \n";

const char* const eftifont_twodots_0 = "\n ";
const char* const eftifont_twodots_1 = "()\n";
const char* const eftifont_twodots_2 = "()\n";
const char* const eftifont_twodots_3 = "\n ";

const char* const font_eftifont[11][VEC_MAXSIZE] =
{
    { eftifont_zero_0, eftifont_zero_1, eftifont_zero_2, eftifont_zero_3},
    { eftifont_one_0, eftifont_one_1, eftifont_one_2, eftifont_one_3},
    { eftifont_two_0, eftifont_two_1, eftifont_two_2, eftifont_two_3},
    { eftifont_three_0, eftifont_three_1, eftifont_three_2, eftifont_three_3},
    { eftifont_four_0, eftifont_four_1, eftifont_four_2, eftifont_four_3},
    { eftifont_five_0, eftifont_five_1, eftifont_five_2, eftifont_five_3},
    { eftifont_six_0, eftifont_six_1, eftifont_six_2, eftifont_six_3},
    { eftifont_seven_0, eftifont_seven_1, eftifont_seven_2, eftifont_seven_3},
    { eftifont_eight_0, eftifont_eight_1, eftifont_eight_2, eftifont_eight_3},
    { eftifont_nine_0, eftifont_nine_1, eftifont_nine_2, eftifont_nine_3},
    { eftifont_twodots_0, eftifont_twodots_1, eftifont_twodots_2, eftifont_twodots_3}
};

int calculate_offset_eftifont(int digit_1, int digit_2);
int offset_before_twodots_eftifont(int num);
int offset_after_twodots_eftifont(int num);
