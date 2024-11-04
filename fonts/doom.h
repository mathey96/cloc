
const char* const doom_zero_0 = " _____ \n";
const char* const doom_zero_1 = "|  _  |\n";
const char* const doom_zero_2 = "| |/' |\n";
const char* const doom_zero_3 = "|  /| |\n";
const char* const doom_zero_4 = "\\ |_/ /\n";
const char* const doom_zero_5 = " \\___/ \n";

const char* const doom_one_0 = " __  \n";
const char* const doom_one_1 = "/  | \n";
const char* const doom_one_2 = "`| | \n";
const char* const doom_one_3 = " | | \n";
const char* const doom_one_4 = "_| |_\n";
const char* const doom_one_5 = "\\___/\n";

const char* const doom_two_0 = " _____ \n";
const char* const doom_two_1 = "/ __  \\\n";
const char* const doom_two_2 = "`' / /'\n";
const char* const doom_two_3 = "  / /  \n";
const char* const doom_two_4 = "./ /___\n";
const char* const doom_two_5 = "\\_____/\n";

const char* const doom_three_0 = " _____ \n";
const char* const doom_three_1 = "|____ |\n";
const char* const doom_three_2 = "    / /\n";
const char* const doom_three_3 = "    \\ \\\n";
const char* const doom_three_4 = ".___/ /\n";
const char* const doom_three_5 = "\\____/ \n";

const char* const doom_four_0 = "   ___ \n";
const char* const doom_four_1 = "  /   |\n";
const char* const doom_four_2 = " / /| |\n";
const char* const doom_four_3 = "/ /_| |\n";
const char* const doom_four_4 = "\\___  |\n";
const char* const doom_four_5 = "    |_/\n";

const char* const doom_five_0 = " _____ \n";
const char* const doom_five_1 = "|  ___|\n";
const char* const doom_five_2 = "|___ \\ \n";
const char* const doom_five_3 = "    \\ \\\n";
const char* const doom_five_4 = "/\\__/ /\n";
const char* const doom_five_5 = "\\____/ \n";

const char* const doom_six_0 = "  ____ \n";
const char* const doom_six_1 = " / ___|\n";
const char* const doom_six_2 = "/ /___ \n";
const char* const doom_six_3 = "| ___ \\\n";
const char* const doom_six_4 = "| \\_/ |\n";
const char* const doom_six_5 = "\\_____/\n";

const char* const doom_seven_0 = " ______\n";
const char* const doom_seven_1 = "|___  /\n";
const char* const doom_seven_2 = "   / / \n";
const char* const doom_seven_3 = "  / /  \n";
const char* const doom_seven_4 = "./ /   \n";
const char* const doom_seven_5 = "\\_/    \n";

const char* const doom_eight_0 = " _____ \n";
const char* const doom_eight_1 = "|  _  |\n";
const char* const doom_eight_2 = " \\ V / \n";
const char* const doom_eight_3 = " / _ \\ \n";
const char* const doom_eight_4 = "| |_| |\n";
const char* const doom_eight_5 = "\\_____/\n";

const char* const doom_nine_0 = " _____ \n";
const char* const doom_nine_1 = "|  _  |\n";
const char* const doom_nine_2 = "| |_| |\n";
const char* const doom_nine_3 = "\\____ |\n";
const char* const doom_nine_4 = ".___/ /\n";
const char* const doom_nine_5 = "\\____/ \n";

const char* const doom_twodots_0 = " _ \n";
const char* const doom_twodots_1 = "(_)\n";
const char* const doom_twodots_2 = "\n ";
const char* const doom_twodots_3 = " _ \n";
const char* const doom_twodots_4 = "(_)\n";
const char* const doom_twodots_5 = "\n ";

const char* const font_doom[11][VEC_MAXSIZE] = 
{
    { doom_zero_0, doom_zero_1, doom_zero_2, doom_zero_3, doom_zero_4, doom_zero_5},
    { doom_one_0, doom_one_1, doom_one_2, doom_one_3, doom_one_4, doom_one_5},
    { doom_two_0, doom_two_1, doom_two_2, doom_two_3, doom_two_4, doom_two_5},
    { doom_three_0, doom_three_1, doom_three_2, doom_three_3, doom_three_4, doom_three_5},
    { doom_four_0, doom_four_1, doom_four_2, doom_four_3, doom_four_4, doom_four_5},
    { doom_five_0, doom_five_1, doom_five_2, doom_five_3, doom_five_4, doom_five_5},
    { doom_six_0, doom_six_1, doom_six_2, doom_six_3, doom_six_4, doom_six_5},
    { doom_seven_0, doom_seven_1, doom_seven_2, doom_seven_3, doom_seven_4, doom_seven_5},
    { doom_eight_0, doom_eight_1, doom_eight_2, doom_eight_3, doom_eight_4, doom_eight_5},
    { doom_nine_0, doom_nine_1, doom_nine_2, doom_nine_3, doom_nine_4, doom_nine_5},
    { doom_twodots_0, doom_twodots_1, doom_twodots_2, doom_twodots_3, doom_twodots_4, doom_twodots_5}
};

int calculate_offset_doom(int digit_1, int digit_2);
int offset_before_twodots_doom(int num);
int offset_after_twodots_doom(int num);
