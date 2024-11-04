
const char* const tinker-toy_zero_0 = " o-o  \n";
const char* const tinker-toy_zero_1 = "o  /o \n";
const char* const tinker-toy_zero_2 = "| / | \n";
const char* const tinker-toy_zero_3 = "o/  o \n";
const char* const tinker-toy_zero_4 = " o-o  \n";

const char* const tinker-toy_one_0 = "  0   \n";
const char* const tinker-toy_one_1 = " /|   \n";
const char* const tinker-toy_one_2 = "o |   \n";
const char* const tinker-toy_one_3 = "  |   \n";
const char* const tinker-toy_one_4 = "o-o-o \n";

const char* const tinker-toy_two_0 = " --  \n";
const char* const tinker-toy_two_1 = "o  o \n";
const char* const tinker-toy_two_2 = "  /  \n";
const char* const tinker-toy_two_3 = " /   \n";
const char* const tinker-toy_two_4 = "o--o \n";

const char* const tinker-toy_three_0 = "o-o  \n";
const char* const tinker-toy_three_1 = "   | \n";
const char* const tinker-toy_three_2 = " oo  \n";
const char* const tinker-toy_three_3 = "   | \n";
const char* const tinker-toy_three_4 = "o-o  \n";

const char* const tinker-toy_four_0 = "o  o \n";
const char* const tinker-toy_four_1 = "|  | \n";
const char* const tinker-toy_four_2 = "o--O \n";
const char* const tinker-toy_four_3 = "   | \n";
const char* const tinker-toy_four_4 = "   o \n";

const char* const tinker-toy_five_0 = "o--o \n";
const char* const tinker-toy_five_1 = "|    \n";
const char* const tinker-toy_five_2 = "o-o  \n";
const char* const tinker-toy_five_3 = "   | \n";
const char* const tinker-toy_five_4 = "o-o  \n";

const char* const tinker-toy_six_0 = "  o   \n";
const char* const tinker-toy_six_1 = " /    \n";
const char* const tinker-toy_six_2 = "O--o  \n";
const char* const tinker-toy_six_3 = "o   | \n";
const char* const tinker-toy_six_4 = " o-o  \n";

const char* const tinker-toy_seven_0 = "o---o \n";
const char* const tinker-toy_seven_1 = "   /  \n";
const char* const tinker-toy_seven_2 = "  o   \n";
const char* const tinker-toy_seven_3 = "  |   \n";
const char* const tinker-toy_seven_4 = "  o   \n";

const char* const tinker-toy_eight_0 = " o-o  \n";
const char* const tinker-toy_eight_1 = "|   | \n";
const char* const tinker-toy_eight_2 = " o-o  \n";
const char* const tinker-toy_eight_3 = "|   | \n";
const char* const tinker-toy_eight_4 = " o-o  \n";

const char* const tinker-toy_nine_0 = " o-o  \n";
const char* const tinker-toy_nine_1 = "|   o \n";
const char* const tinker-toy_nine_2 = " o--O \n";
const char* const tinker-toy_nine_3 = "   /  \n";
const char* const tinker-toy_nine_4 = "  o   \n";

const char* const tinker-toy_twodots_0 = "O \n";
const char* const tinker-toy_twodots_1 = "\n ";
const char* const tinker-toy_twodots_2 = "O \n";
const char* const tinker-toy_twodots_3 = "\n ";
const char* const tinker-toy_twodots_4 = "\n ";

const char* const font_tinker-toy[11][VEC_MAXSIZE] = 
{
    { tinker-toy_zero_0, tinker-toy_zero_1, tinker-toy_zero_2, tinker-toy_zero_3, tinker-toy_zero_4},
    { tinker-toy_one_0, tinker-toy_one_1, tinker-toy_one_2, tinker-toy_one_3, tinker-toy_one_4},
    { tinker-toy_two_0, tinker-toy_two_1, tinker-toy_two_2, tinker-toy_two_3, tinker-toy_two_4},
    { tinker-toy_three_0, tinker-toy_three_1, tinker-toy_three_2, tinker-toy_three_3, tinker-toy_three_4},
    { tinker-toy_four_0, tinker-toy_four_1, tinker-toy_four_2, tinker-toy_four_3, tinker-toy_four_4},
    { tinker-toy_five_0, tinker-toy_five_1, tinker-toy_five_2, tinker-toy_five_3, tinker-toy_five_4},
    { tinker-toy_six_0, tinker-toy_six_1, tinker-toy_six_2, tinker-toy_six_3, tinker-toy_six_4},
    { tinker-toy_seven_0, tinker-toy_seven_1, tinker-toy_seven_2, tinker-toy_seven_3, tinker-toy_seven_4},
    { tinker-toy_eight_0, tinker-toy_eight_1, tinker-toy_eight_2, tinker-toy_eight_3, tinker-toy_eight_4},
    { tinker-toy_nine_0, tinker-toy_nine_1, tinker-toy_nine_2, tinker-toy_nine_3, tinker-toy_nine_4},
    { tinker-toy_twodots_0, tinker-toy_twodots_1, tinker-toy_twodots_2, tinker-toy_twodots_3, tinker-toy_twodots_4}
}

int calculate_offset_tinker-toy(int digit_1, int digit_2);
int offset_before_twodots_tinker-toy(int num); 
int offset_after_twodots_tinker-toy(int num);
