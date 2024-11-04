
const char* const lcd_zero_0 = " ___  \n";
const char* const lcd_zero_1 = "|  /| \n";
const char* const lcd_zero_2 = "| + | \n";
const char* const lcd_zero_3 = "|/  | \n";
const char* const lcd_zero_4 = " ---  \n";

const char* const lcd_one_0 = " _    \n";
const char* const lcd_one_1 = "  |   \n";
const char* const lcd_one_2 = "  +   \n";
const char* const lcd_one_3 = "  |   \n";
const char* const lcd_one_4 = " ---  \n";

const char* const lcd_two_0 = " ___  \n";
const char* const lcd_two_1 = "    | \n";
const char* const lcd_two_2 = " -+-  \n";
const char* const lcd_two_3 = "|     \n";
const char* const lcd_two_4 = " ---  \n";

const char* const lcd_three_0 = " ___  \n";
const char* const lcd_three_1 = "    | \n";
const char* const lcd_three_2 = " -+-  \n";
const char* const lcd_three_3 = "    | \n";
const char* const lcd_three_4 = " ---  \n";

const char* const lcd_four_0 = "| |   \n";
const char* const lcd_four_1 = " -+-  \n";
const char* const lcd_four_2 = "  |   \n";

const char* const lcd_five_0 = " ___  \n";
const char* const lcd_five_1 = "|     \n";
const char* const lcd_five_2 = " -+-  \n";
const char* const lcd_five_3 = "    | \n";
const char* const lcd_five_4 = " ---  \n";

const char* const lcd_six_0 = " ___  \n";
const char* const lcd_six_1 = "|     \n";
const char* const lcd_six_2 = "|-+-  \n";
const char* const lcd_six_3 = "|   | \n";
const char* const lcd_six_4 = " ---  \n";

const char* const lcd_seven_0 = " ___  \n";
const char* const lcd_seven_1 = "   /  \n";
const char* const lcd_seven_2 = "  +   \n";
const char* const lcd_seven_3 = " /    \n";

const char* const lcd_eight_0 = " ___  \n";
const char* const lcd_eight_1 = "|   | \n";
const char* const lcd_eight_2 = " -+-  \n";
const char* const lcd_eight_3 = "|   | \n";
const char* const lcd_eight_4 = " ---  \n";

const char* const lcd_nine_0 = " ___  \n";
const char* const lcd_nine_1 = "|   | \n";
const char* const lcd_nine_2 = " -+-| \n";
const char* const lcd_nine_3 = "    | \n";
const char* const lcd_nine_4 = " ---  \n";

const char* const lcd_twodots_0 = "  |   \n";
const char* const lcd_twodots_1 = "\n ";
const char* const lcd_twodots_2 = "  |   \n";
const char* const lcd_twodots_3 = "\n ";
const char* const lcd_twodots_4 = "\n ";

const char* const font_lcd[11][VEC_MAXSIZE] = 
{
    { lcd_zero_0, lcd_zero_1, lcd_zero_2, lcd_zero_3, lcd_zero_4},
    { lcd_one_0, lcd_one_1, lcd_one_2, lcd_one_3, lcd_one_4},
    { lcd_two_0, lcd_two_1, lcd_two_2, lcd_two_3, lcd_two_4},
    { lcd_three_0, lcd_three_1, lcd_three_2, lcd_three_3, lcd_three_4},
    { lcd_four_0, lcd_four_1, lcd_four_2},
    { lcd_five_0, lcd_five_1, lcd_five_2, lcd_five_3, lcd_five_4},
    { lcd_six_0, lcd_six_1, lcd_six_2, lcd_six_3, lcd_six_4},
    { lcd_seven_0, lcd_seven_1, lcd_seven_2, lcd_seven_3},
    { lcd_eight_0, lcd_eight_1, lcd_eight_2, lcd_eight_3, lcd_eight_4},
    { lcd_nine_0, lcd_nine_1, lcd_nine_2, lcd_nine_3, lcd_nine_4},
    { lcd_twodots_0, lcd_twodots_1, lcd_twodots_2, lcd_twodots_3, lcd_twodots_4}
}

int calculate_offset_lcd(int digit_1, int digit_2);
int offset_before_twodots_lcd(int num); 
int offset_after_twodots_lcd(int num);
