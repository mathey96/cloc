
const char* const drpepper_zero_0 = " ___ \n";
const char* const drpepper_zero_1 = "|   |\n";
const char* const drpepper_zero_2 = "| / |\n";
const char* const drpepper_zero_3 = "`___'\n";

const char* const drpepper_one_0 = " _ \n";
const char* const drpepper_one_1 = "/ |\n";
const char* const drpepper_one_2 = "| |\n";
const char* const drpepper_one_3 = "|_|\n";

const char* const drpepper_two_0 = " ___ \n";
const char* const drpepper_two_1 = "<_  >\n";
const char* const drpepper_two_2 = " / / \n";
const char* const drpepper_two_3 = "<___>\n";

const char* const drpepper_three_0 = " ____\n";
const char* const drpepper_three_1 = "<__ /\n";
const char* const drpepper_three_2 = " <_ \\\n";
const char* const drpepper_three_3 = "<___/\n";

const char* const drpepper_four_0 = "  __  \n";
const char* const drpepper_four_1 = " /. | \n";
const char* const drpepper_four_2 = "/_  .|\n";
const char* const drpepper_four_3 = "  |_| \n";

const char* const drpepper_five_0 = " ___ \n";
const char* const drpepper_five_1 = "| __|\n";
const char* const drpepper_five_2 = "`__ \\\n";
const char* const drpepper_five_3 = "|___/\n";

const char* const drpepper_six_0 = " ___ \n";
const char* const drpepper_six_1 = "| __>\n";
const char* const drpepper_six_2 = "| . \\\n";
const char* const drpepper_six_3 = "`___/\n";

const char* const drpepper_seven_0 = " ___ \n";
const char* const drpepper_seven_1 = "|_  |\n";
const char* const drpepper_seven_2 = " / / \n";
const char* const drpepper_seven_3 = "/_/  \n";

const char* const drpepper_eight_0 = " ___ \n";
const char* const drpepper_eight_1 = "< . >\n";
const char* const drpepper_eight_2 = "/ . \\\n";
const char* const drpepper_eight_3 = "\\___/\n";

const char* const drpepper_nine_0 = " ___ \n";
const char* const drpepper_nine_1 = "| . |\n";
const char* const drpepper_nine_2 = "`_  /\n";
const char* const drpepper_nine_3 = " /_/ \n";

const char* const drpepper_twodots_0 = " _ \n";
const char* const drpepper_twodots_1 = "<_>\n";
const char* const drpepper_twodots_2 = " _ \n";
const char* const drpepper_twodots_3 = "<_>\n";

const char* const font_drpepper[11][VEC_MAXSIZE] =
{
    { drpepper_zero_0, drpepper_zero_1, drpepper_zero_2, drpepper_zero_3},
    { drpepper_one_0, drpepper_one_1, drpepper_one_2, drpepper_one_3},
    { drpepper_two_0, drpepper_two_1, drpepper_two_2, drpepper_two_3},
    { drpepper_three_0, drpepper_three_1, drpepper_three_2, drpepper_three_3},
    { drpepper_four_0, drpepper_four_1, drpepper_four_2, drpepper_four_3},
    { drpepper_five_0, drpepper_five_1, drpepper_five_2, drpepper_five_3},
    { drpepper_six_0, drpepper_six_1, drpepper_six_2, drpepper_six_3},
    { drpepper_seven_0, drpepper_seven_1, drpepper_seven_2, drpepper_seven_3},
    { drpepper_eight_0, drpepper_eight_1, drpepper_eight_2, drpepper_eight_3},
    { drpepper_nine_0, drpepper_nine_1, drpepper_nine_2, drpepper_nine_3},
    { drpepper_twodots_0, drpepper_twodots_1, drpepper_twodots_2, drpepper_twodots_3}
};

int calculate_offset_drpepper(int digit_1, int digit_2);
int offset_before_twodots_drpepper(int num);
int offset_after_twodots_drpepper(int num);
