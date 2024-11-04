
const char* const avatar_zero_0 = " ____ \n";
const char* const avatar_zero_1 = "/  _ \\\n";
const char* const avatar_zero_2 = "| / \\|\n";
const char* const avatar_zero_3 = "| \\_/|\n";
const char* const avatar_zero_4 = "\\____/\n";

const char* const avatar_one_0 = " _ \n";
const char* const avatar_one_1 = "/ \\\n";
const char* const avatar_one_2 = "| |\n";
const char* const avatar_one_3 = "| |\n";
const char* const avatar_one_4 = "\\_/\n";

const char* const avatar_two_0 = " ____ \n";
const char* const avatar_two_1 = "/_   \\\n";
const char* const avatar_two_2 = " /   /\n";
const char* const avatar_two_3 = "/   /_\n";
const char* const avatar_two_4 = "\\____/\n";

const char* const avatar_three_0 = "_____ \n";
const char* const avatar_three_1 = "\\__  \\\n";
const char* const avatar_three_2 = "  /  |\n";
const char* const avatar_three_3 = " _\\  |\n";
const char* const avatar_three_4 = "/____/\n";

const char* const avatar_four_0 = "    _ \n";
const char* const avatar_four_1 = "/\\ / |\n";
const char* const avatar_four_2 = "\\_\\| |\n";
const char* const avatar_four_3 = "   | |\n";
const char* const avatar_four_4 = "   \\_|\n";

const char* const avatar_five_0 = " ____ \n";
const char* const avatar_five_1 = "/ ___\\\n";
const char* const avatar_five_2 = "|    \\\n";
const char* const avatar_five_3 = "\\___ |\n";
const char* const avatar_five_4 = "\\____/\n";

const char* const avatar_six_0 = "    _ \n";
const char* const avatar_six_1 = " __/ \\\n";
const char* const avatar_six_2 = "/__  |\n";
const char* const avatar_six_3 = "|\\/  |\n";
const char* const avatar_six_4 = "\\____/\n";

const char* const avatar_seven_0 = " ____ \n";
const char* const avatar_seven_1 = "/ _  \\\n";
const char* const avatar_seven_2 = "\\/ | |\n";
const char* const avatar_seven_3 = "   | |\n";
const char* const avatar_seven_4 = "   \\_/\n";

const char* const avatar_eight_0 = " ____ \n";
const char* const avatar_eight_1 = "/ ___\\\n";
const char* const avatar_eight_2 = "\\ \\ //\n";
const char* const avatar_eight_3 = "/ /_\\\\\n";
const char* const avatar_eight_4 = "\\____/\n";

const char* const avatar_nine_0 = " ____ \n";
const char* const avatar_nine_1 = "/__  \\\n";
const char* const avatar_nine_2 = "|\\/  |\n";
const char* const avatar_nine_3 = "\\__  |\n";
const char* const avatar_nine_4 = "   \\_/\n";

const char* const avatar_twodots_0 = "__\n";
const char* const avatar_twodots_1 = "\\/\n";
const char* const avatar_twodots_2 = "__\n";
const char* const avatar_twodots_3 = "\\/\n";
const char* const avatar_twodots_4 = "\n ";

const char* const font_avatar[11][VEC_MAXSIZE] = 
{
    { avatar_zero_0, avatar_zero_1, avatar_zero_2, avatar_zero_3, avatar_zero_4},
    { avatar_one_0, avatar_one_1, avatar_one_2, avatar_one_3, avatar_one_4},
    { avatar_two_0, avatar_two_1, avatar_two_2, avatar_two_3, avatar_two_4},
    { avatar_three_0, avatar_three_1, avatar_three_2, avatar_three_3, avatar_three_4},
    { avatar_four_0, avatar_four_1, avatar_four_2, avatar_four_3, avatar_four_4},
    { avatar_five_0, avatar_five_1, avatar_five_2, avatar_five_3, avatar_five_4},
    { avatar_six_0, avatar_six_1, avatar_six_2, avatar_six_3, avatar_six_4},
    { avatar_seven_0, avatar_seven_1, avatar_seven_2, avatar_seven_3, avatar_seven_4},
    { avatar_eight_0, avatar_eight_1, avatar_eight_2, avatar_eight_3, avatar_eight_4},
    { avatar_nine_0, avatar_nine_1, avatar_nine_2, avatar_nine_3, avatar_nine_4},
    { avatar_twodots_0, avatar_twodots_1, avatar_twodots_2, avatar_twodots_3, avatar_twodots_4}
};

int calculate_offset_avatar(int digit_1, int digit_2);
int offset_before_twodots_avatar(int num);
int offset_after_twodots_avatar(int num);
