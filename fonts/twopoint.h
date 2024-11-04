
const char* const twopoint_zero_0 = "/\\\n";
const char* const twopoint_zero_1 = "\\/\n";

const char* const twopoint_one_0 = "'|\n";
const char* const twopoint_one_1 = " |\n";

const char* const twopoint_two_0 = "~)\n";
const char* const twopoint_two_1 = "/_\n";

const char* const twopoint_three_0 = "~/\n";
const char* const twopoint_three_1 = "_)\n";

const char* const twopoint_four_0 = "/| \n";
const char* const twopoint_four_1 = "~|~\n";

const char* const twopoint_five_0 = "|~\n";
const char* const twopoint_five_1 = "_)\n";

const char* const twopoint_six_0 = " / \n";
const char* const twopoint_six_1 = "(_)\n";

const char* const twopoint_seven_0 = "~/\n";
const char* const twopoint_seven_1 = "/ \n";

const char* const twopoint_eight_0 = "(~)\n";
const char* const twopoint_eight_1 = "(_)\n";

const char* const twopoint_nine_0 = "(~|\n";
const char* const twopoint_nine_1 = " / \n";

const char* const twopoint_twodots_0 = "o\n";
const char* const twopoint_twodots_1 = "o\n";

const char* const font_twopoint[11][VEC_MAXSIZE] =
{
    { twopoint_zero_0, twopoint_zero_1},
    { twopoint_one_0, twopoint_one_1},
    { twopoint_two_0, twopoint_two_1},
    { twopoint_three_0, twopoint_three_1},
    { twopoint_four_0, twopoint_four_1},
    { twopoint_five_0, twopoint_five_1},
    { twopoint_six_0, twopoint_six_1},
    { twopoint_seven_0, twopoint_seven_1},
    { twopoint_eight_0, twopoint_eight_1},
    { twopoint_nine_0, twopoint_nine_1},
    { twopoint_twodots_0, twopoint_twodots_1}
};

int calculate_offset_twopoint(int digit_1, int digit_2);
int offset_before_twodots_twopoint(int num);
int offset_after_twodots_twopoint(int num);
