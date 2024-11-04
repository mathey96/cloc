
const char* const rectangles_zero_0 = " ___ \n";
const char* const rectangles_zero_1 = "|   |\n";
const char* const rectangles_zero_2 = "| | |\n";
const char* const rectangles_zero_3 = "|___|\n";

const char* const rectangles_one_0 = " ___   \n";
const char* const rectangles_one_1 = "|_  |  \n";
const char* const rectangles_one_2 = " _| |_ \n";
const char* const rectangles_one_3 = "|_____|\n";

const char* const rectangles_two_0 = " ___ \n";
const char* const rectangles_two_1 = "|_  |\n";
const char* const rectangles_two_2 = "|  _|\n";
const char* const rectangles_two_3 = "|___|\n";

const char* const rectangles_three_0 = " ___ \n";
const char* const rectangles_three_1 = "|_  |\n";
const char* const rectangles_three_2 = "|_  |\n";
const char* const rectangles_three_3 = "|___|\n";

const char* const rectangles_four_0 = " ___ \n";
const char* const rectangles_four_1 = "| | |\n";
const char* const rectangles_four_2 = "|_  |\n";
const char* const rectangles_four_3 = "  |_|\n";

const char* const rectangles_five_0 = " ___ \n";
const char* const rectangles_five_1 = "|  _|\n";
const char* const rectangles_five_2 = "|_  |\n";
const char* const rectangles_five_3 = "|___|\n";

const char* const rectangles_six_0 = " ___ \n";
const char* const rectangles_six_1 = "|  _|\n";
const char* const rectangles_six_2 = "| . |\n";
const char* const rectangles_six_3 = "|___|\n";

const char* const rectangles_seven_0 = " ___ \n";
const char* const rectangles_seven_1 = "|_  |\n";
const char* const rectangles_seven_2 = "  | |\n";
const char* const rectangles_seven_3 = "  |_|\n";

const char* const rectangles_eight_0 = " ___ \n";
const char* const rectangles_eight_1 = "| . |\n";
const char* const rectangles_eight_2 = "| . |\n";
const char* const rectangles_eight_3 = "|___|\n";

const char* const rectangles_nine_0 = " ___ \n";
const char* const rectangles_nine_1 = "| . |\n";
const char* const rectangles_nine_2 = "|_  |\n";
const char* const rectangles_nine_3 = "|___|\n";

const char* const rectangles_twodots_0 = " _ \n";
const char* const rectangles_twodots_1 = "|_|\n";
const char* const rectangles_twodots_2 = " _ \n";
const char* const rectangles_twodots_3 = "|_|\n";

const char* const font_rectangles[11][VEC_MAXSIZE] =
{
    { rectangles_zero_0, rectangles_zero_1, rectangles_zero_2, rectangles_zero_3},
    { rectangles_one_0, rectangles_one_1, rectangles_one_2, rectangles_one_3},
    { rectangles_two_0, rectangles_two_1, rectangles_two_2, rectangles_two_3},
    { rectangles_three_0, rectangles_three_1, rectangles_three_2, rectangles_three_3},
    { rectangles_four_0, rectangles_four_1, rectangles_four_2, rectangles_four_3},
    { rectangles_five_0, rectangles_five_1, rectangles_five_2, rectangles_five_3},
    { rectangles_six_0, rectangles_six_1, rectangles_six_2, rectangles_six_3},
    { rectangles_seven_0, rectangles_seven_1, rectangles_seven_2, rectangles_seven_3},
    { rectangles_eight_0, rectangles_eight_1, rectangles_eight_2, rectangles_eight_3},
    { rectangles_nine_0, rectangles_nine_1, rectangles_nine_2, rectangles_nine_3},
    { rectangles_twodots_0, rectangles_twodots_1, rectangles_twodots_2, rectangles_twodots_3}
}

int calculate_offset_rectangles(int digit_1, int digit_2);
int offset_before_twodots_rectangles(int num);
int offset_after_twodots_rectangles(int num);
