
const char* const slscript_zero_0 = "   __ \n";
const char* const slscript_zero_1 = "  /  )\n";
const char* const slscript_zero_2 = " /  / \n";
const char* const slscript_zero_3 = "(__/  \n";

const char* const slscript_one_0 = "  _\n";
const char* const slscript_one_1 = "  /\n";
const char* const slscript_one_2 = " / \n";
const char* const slscript_one_3 = "/  \n";

const char* const slscript_two_0 = "   __ \n";
const char* const slscript_two_1 = "     )\n";
const char* const slscript_two_2 = " .--' \n";
const char* const slscript_two_3 = "(__   \n";

const char* const slscript_three_0 = "   __ \n";
const char* const slscript_three_1 = "     )\n";
const char* const slscript_three_2 = "   -/ \n";
const char* const slscript_three_3 = "___/  \n";

const char* const slscript_four_0 = "\n";
const char* const slscript_four_1 = " /  /\n";
const char* const slscript_four_2 = "'--/ \n";
const char* const slscript_four_3 = "  /  \n";

const char* const slscript_five_0 = "  ___\n";
const char* const slscript_five_1 = " /   \n";
const char* const slscript_five_2 = "'--. \n";
const char* const slscript_five_3 = "___) \n";

const char* const slscript_six_0 = "\n";
const char* const slscript_six_1 = "  / \n";
const char* const slscript_six_2 = " /_ \n";
const char* const slscript_six_3 = "(__)\n";

const char* const slscript_seven_0 = "___\n";
const char* const slscript_seven_1 = "  /\n";
const char* const slscript_seven_2 = "-/-\n";
const char* const slscript_seven_3 = "/  \n";

const char* const slscript_eight_0 = "  __ \n";
const char* const slscript_eight_1 = " (  )\n";
const char* const slscript_eight_2 = " ./' \n";
const char* const slscript_eight_3 = "(__) \n";

const char* const slscript_nine_0 = " __ \n";
const char* const slscript_nine_1 = "(__)\n";
const char* const slscript_nine_2 = "  / \n";
const char* const slscript_nine_3 = " /  \n";

const char* const slscript_twodots_0 = "  o\n";
const char* const slscript_twodots_1 = "\n ";
const char* const slscript_twodots_2 = "o  \n";
const char* const slscript_twodots_3 = "\n ";

const char* const font_slscript[11][VEC_MAXSIZE] =
{
    {slscript_zero_0, slscript_zero_1, slscript_zero_2, slscript_zero_3},
    {slscript_one_0, slscript_one_1, slscript_one_2, slscript_one_3},
    {slscript_two_0, slscript_two_1, slscript_two_2, slscript_two_3},
    {slscript_three_0, slscript_three_1, slscript_three_2, slscript_three_3},
    {slscript_four_0, slscript_four_1, slscript_four_2, slscript_four_3},
    {slscript_five_0, slscript_five_1, slscript_five_2, slscript_five_3},
    {slscript_six_0, slscript_six_1, slscript_six_2, slscript_six_3},
    {slscript_seven_0, slscript_seven_1, slscript_seven_2, slscript_seven_3},
    {slscript_eight_0, slscript_eight_1, slscript_eight_2, slscript_eight_3},
    {slscript_nine_0, slscript_nine_1, slscript_nine_2, slscript_nine_3},
    {slscript_twodots_0, slscript_twodots_1, slscript_twodots_2, slscript_twodots_3}
};

int calculate_offset_slscript(int digit_1, int digit_2);
int offset_before_twodots_slscript(int num);
int offset_after_twodots_slscript(int num);
