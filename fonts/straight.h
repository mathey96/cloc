
const char* const straight_zero_0 = "  __  \n";
const char* const straight_zero_1 = " /  \\ \n";
const char* const straight_zero_2 = " \\__/ \n";

const char* const straight_one_0 = "\n";
const char* const straight_one_1 = " /| \n";
const char* const straight_one_2 = "  | \n";

const char* const straight_two_0 = " __  \n";
const char* const straight_two_1 = "  _) \n";
const char* const straight_two_2 = " /__ \n";

const char* const straight_three_0 = " __  \n";
const char* const straight_three_1 = "  _) \n";
const char* const straight_three_2 = " __) \n";

const char* const straight_four_0 = "\n";
const char* const straight_four_1 = " |__| \n";
const char* const straight_four_2 = "    | \n";

const char* const straight_five_0 = "  __ \n";
const char* const straight_five_1 = " |_  \n";
const char* const straight_five_2 = " __) \n";

const char* const straight_six_0 = "  __  \n";
const char* const straight_six_1 = " /__  \n";
const char* const straight_six_2 = " \\__) \n";

const char* const straight_seven_0 = " ___ \n";
const char* const straight_seven_1 = "   / \n";
const char* const straight_seven_2 = "  /  \n";

const char* const straight_eight_0 = "  __  \n";
const char* const straight_eight_1 = " (__) \n";
const char* const straight_eight_2 = " (__) \n";

const char* const straight_nine_0 = "  __  \n";
const char* const straight_nine_1 = " (__\\ \n";
const char* const straight_nine_2 = "  __/ \n";

const char* const straight_twodots_0 = "\n ";
const char* const straight_twodots_1 = ". \n";
const char* const straight_twodots_2 = ". \n";

const char* const font_straight[11][VEC_MAXSIZE] =
{
    { straight_zero_0, straight_zero_1, straight_zero_2},
    { straight_one_0, straight_one_1, straight_one_2},
    { straight_two_0, straight_two_1, straight_two_2},
    { straight_three_0, straight_three_1, straight_three_2},
    { straight_four_0, straight_four_1, straight_four_2},
    { straight_five_0, straight_five_1, straight_five_2},
    { straight_six_0, straight_six_1, straight_six_2},
    { straight_seven_0, straight_seven_1, straight_seven_2},
    { straight_eight_0, straight_eight_1, straight_eight_2},
    { straight_nine_0, straight_nine_1, straight_nine_2},
    { straight_twodots_0, straight_twodots_1, straight_twodots_2}
};

int calculate_offset_straight(int digit_1, int digit_2);
int offset_before_twodots_straight(int num);
int offset_after_twodots_straight(int num);
