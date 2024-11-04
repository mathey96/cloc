
const char* const cursive_zero_0 = "   __ \n";
const char* const cursive_zero_1 = "  /  )\n";
const char* const cursive_zero_2 = " /  / \n";
const char* const cursive_zero_3 = "(__/  \n";

const char* const cursive_one_0 = "  _\n";
const char* const cursive_one_1 = "  /\n";
const char* const cursive_one_2 = " / \n";
const char* const cursive_one_3 = "/  \n";

const char* const cursive_two_0 = "   __ \n";
const char* const cursive_two_1 = "     )\n";
const char* const cursive_two_2 = " .--' \n";
const char* const cursive_two_3 = "(__   \n";

const char* const cursive_three_0 = "   __ \n";
const char* const cursive_three_1 = "     )\n";
const char* const cursive_three_2 = "   -/ \n";
const char* const cursive_three_3 = "___/  \n";

const char* const cursive_four_0 = "  /  \n";
const char* const cursive_four_1 = " /  /\n";
const char* const cursive_four_2 = "'--/ \n";
const char* const cursive_four_3 = "  /  \n";

const char* const cursive_five_0 = "  ___\n";
const char* const cursive_five_1 = " /   \n";
const char* const cursive_five_2 = "'--. \n";
const char* const cursive_five_3 = "___) \n";

const char* const cursive_six_0 = "\n";
const char* const cursive_six_1 = "  / \n";
const char* const cursive_six_2 = " /_ \n";
const char* const cursive_six_3 = "(__)\n";

const char* const cursive_seven_0 = "___\n";
const char* const cursive_seven_1 = "  /\n";
const char* const cursive_seven_2 = "-/-\n";
const char* const cursive_seven_3 = "/  \n";

const char* const cursive_eight_0 = "  __ \n";
const char* const cursive_eight_1 = " (  )\n";
const char* const cursive_eight_2 = " ./' \n";
const char* const cursive_eight_3 = "(__) \n";

const char* const cursive_nine_0 = " __ \n";
const char* const cursive_nine_1 = "(__)\n";
const char* const cursive_nine_2 = "  / \n";
const char* const cursive_nine_3 = " /  \n";

const char* const cursive_twodots_0 = "\n ";
const char* const cursive_twodots_1 = "  o\n";
const char* const cursive_twodots_2 = "\n ";
const char* const cursive_twodots_3 = "o  \n";

const char* const font_cursive[11][VEC_MAXSIZE] =
{
    { cursive_zero_0, cursive_zero_1, cursive_zero_2, cursive_zero_3},
    { cursive_one_0, cursive_one_1, cursive_one_2, cursive_one_3},
    { cursive_two_0, cursive_two_1, cursive_two_2, cursive_two_3},
    { cursive_three_0, cursive_three_1, cursive_three_2, cursive_three_3},
    { cursive_four_0, cursive_four_1, cursive_four_2, cursive_four_3},
    { cursive_five_0, cursive_five_1, cursive_five_2, cursive_five_3},
    { cursive_six_0, cursive_six_1, cursive_six_2, cursive_six_3},
    { cursive_seven_0, cursive_seven_1, cursive_seven_2, cursive_seven_3},
    { cursive_eight_0, cursive_eight_1, cursive_eight_2, cursive_eight_3},
    { cursive_nine_0, cursive_nine_1, cursive_nine_2, cursive_nine_3},
    { cursive_twodots_0, cursive_twodots_1, cursive_twodots_2, cursive_twodots_3}
};

int calculate_offset_cursive(int digit_1, int digit_2);
int offset_before_twodots_cursive(int num);
int offset_after_twodots_cursive(int num);
