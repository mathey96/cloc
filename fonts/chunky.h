
const char* const chunky_zero_0 = " ______ \n";
const char* const chunky_zero_1 = "|      |\n";
const char* const chunky_zero_2 = "|  --  |\n";
const char* const chunky_zero_3 = "|______|\n";

const char* const chunky_one_0 = " ____   \n";
const char* const chunky_one_1 = "|_   |  \n";
const char* const chunky_one_2 = " _|  |_ \n";
const char* const chunky_one_3 = "|______|\n";

const char* const chunky_two_0 = " ______ \n";
const char* const chunky_two_1 = "|__    |\n";
const char* const chunky_two_2 = "|    __|\n";
const char* const chunky_two_3 = "|______|\n";

const char* const chunky_three_0 = " ______ \n";
const char* const chunky_three_1 = "|__    |\n";
const char* const chunky_three_2 = "|__    |\n";
const char* const chunky_three_3 = "|______|\n";

const char* const chunky_four_0 = " _____  \n";
const char* const chunky_four_1 = "|  |  | \n";
const char* const chunky_four_2 = "|__    |\n";
const char* const chunky_four_3 = "   |__| \n";

const char* const chunky_five_0 = " ______ \n";
const char* const chunky_five_1 = "|    __|\n";
const char* const chunky_five_2 = "|__    |\n";
const char* const chunky_five_3 = "|______|\n";

const char* const chunky_six_0 = " ______ \n";
const char* const chunky_six_1 = "|    __|\n";
const char* const chunky_six_2 = "|  __  |\n";
const char* const chunky_six_3 = "|______|\n";

const char* const chunky_seven_0 = " ______ \n";
const char* const chunky_seven_1 = "|      |\n";
const char* const chunky_seven_2 = "|_     |\n";
const char* const chunky_seven_3 = "  |____|\n";

const char* const chunky_eight_0 = " ______ \n";
const char* const chunky_eight_1 = "|  __  |\n";
const char* const chunky_eight_2 = "|  __  |\n";
const char* const chunky_eight_3 = "|______|\n";

const char* const chunky_nine_0 = " ______ \n";
const char* const chunky_nine_1 = "|  __  |\n";
const char* const chunky_nine_2 = "|__    |\n";
const char* const chunky_nine_3 = "|______|\n";

const char* const chunky_twodots_0 = " __ \n";
const char* const chunky_twodots_1 = "|__|\n";
const char* const chunky_twodots_2 = " __ \n";
const char* const chunky_twodots_3 = "|__|\n";

const char* const font_chunky[11][VEC_MAXSIZE] = 
{
    { chunky_zero_0, chunky_zero_1, chunky_zero_2, chunky_zero_3},
    { chunky_one_0, chunky_one_1, chunky_one_2, chunky_one_3},
    { chunky_two_0, chunky_two_1, chunky_two_2, chunky_two_3},
    { chunky_three_0, chunky_three_1, chunky_three_2, chunky_three_3},
    { chunky_four_0, chunky_four_1, chunky_four_2, chunky_four_3},
    { chunky_five_0, chunky_five_1, chunky_five_2, chunky_five_3},
    { chunky_six_0, chunky_six_1, chunky_six_2, chunky_six_3},
    { chunky_seven_0, chunky_seven_1, chunky_seven_2, chunky_seven_3},
    { chunky_eight_0, chunky_eight_1, chunky_eight_2, chunky_eight_3},
    { chunky_nine_0, chunky_nine_1, chunky_nine_2, chunky_nine_3},
    { chunky_twodots_0, chunky_twodots_1, chunky_twodots_2, chunky_twodots_3}
};

int calculate_offset_chunky(int digit_1, int digit_2);
int offset_before_twodots_chunky(int num);
int offset_after_twodots_chunky(int num);
