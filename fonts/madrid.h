
const char* const madrid_zero_0 = "\n";
const char* const madrid_zero_1 = "/=\\ \n";
const char* const madrid_zero_2 = "|/| \n";
const char* const madrid_zero_3 = "\\=/ \n";

const char* const madrid_one_0 = "\n";
const char* const madrid_one_1 = "/| \n";
const char* const madrid_one_2 = " = \n";
const char* const madrid_one_3 = " | \n";

const char* const madrid_two_0 = "\n";
const char* const madrid_two_1 = "/=\\ \n";
const char* const madrid_two_2 = " /  \n";
const char* const madrid_two_3 = "/=/ \n";

const char* const madrid_three_0 = "\n";
const char* const madrid_three_1 = "/=\\ \n";
const char* const madrid_three_2 = " =< \n";
const char* const madrid_three_3 = "\\=/ \n";

const char* const madrid_four_0 = "\n";
const char* const madrid_four_1 = " /| \n";
const char* const madrid_four_2 = "<=| \n";
const char* const madrid_four_3 = "  | \n";

const char* const madrid_five_0 = "\n";
const char* const madrid_five_1 = "|=\\ \n";
const char* const madrid_five_2 = "\"-\\ \n";
const char* const madrid_five_3 = "\\=/ \n";

const char* const madrid_six_0 = "\n";
const char* const madrid_six_1 = "/=\\ \n";
const char* const madrid_six_2 = "|=\\ \n";
const char* const madrid_six_3 = "\\=/ \n";

const char* const madrid_seven_0 = "\n";
const char* const madrid_seven_1 = "/=| \n";
const char* const madrid_seven_2 = " /\" \n";
const char* const madrid_seven_3 = "/   \n";

const char* const madrid_eight_0 = "\n";
const char* const madrid_eight_1 = "/=\\ \n";
const char* const madrid_eight_2 = ">=< \n";
const char* const madrid_eight_3 = "\\=/ \n";

const char* const madrid_nine_0 = "\n";
const char* const madrid_nine_1 = "/=\\ \n";
const char* const madrid_nine_2 = "\\=| \n";
const char* const madrid_nine_3 = "  | \n";

const char* const madrid_twodots_0 = "\n";
const char* const madrid_twodots_1 = "= \n";
const char* const madrid_twodots_2 = "\n ";
const char* const madrid_twodots_3 = "= \n";

const char* const font_madrid[11][VEC_MAXSIZE] = 
{
    { madrid_zero_0, madrid_zero_1, madrid_zero_2, madrid_zero_3},
    { madrid_one_0, madrid_one_1, madrid_one_2, madrid_one_3},
    { madrid_two_0, madrid_two_1, madrid_two_2, madrid_two_3},
    { madrid_three_0, madrid_three_1 ,madrid_three_2, madrid_three_3},
    { madrid_four_0, madrid_four_1, madrid_four_2, madrid_four_3},
    { madrid_five_0, madrid_five_1, madrid_five_2, madrid_five_3},
    { madrid_six_0, madrid_six_1, madrid_six_2, madrid_six_3},
    { madrid_seven_0, madrid_seven_1, madrid_seven_2, madrid_seven_3},
    { madrid_eight_0, madrid_eight_1, madrid_eight_2, madrid_eight_3},
    { madrid_nine_0, madrid_nine_1, madrid_nine_2, madrid_nine_3},
    { madrid_twodots_0, madrid_twodots_1, madrid_twodots_2, madrid_twodots_3}
};

int calculate_offset_madrid(int digit_1, int digit_2);
int offset_before_twodots_madrid(int num);
int offset_after_twodots_madrid(int num);
