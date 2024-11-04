
const char* const slant_zero_0 = "   ____ \n";
const char* const slant_zero_1 = "  / __ \\n";
const char* const slant_zero_2 = " / / / /\n";
const char* const slant_zero_3 = "/ /_/ / \n";
const char* const slant_zero_4 = "\____/  \n";

const char* const slant_one_0 = "   ___\n";
const char* const slant_one_1 = "  <  /\n";
const char* const slant_one_2 = "  / / \n";
const char* const slant_one_3 = " / /  \n";
const char* const slant_one_4 = "/_/   \n";

const char* const slant_two_0 = "   ___ \n";
const char* const slant_two_1 = "  |__ \\n";
const char* const slant_two_2 = "  __/ /\n";
const char* const slant_two_3 = " / __/ \n";
const char* const slant_two_4 = "/____/ \n";

const char* const slant_three_0 = "   _____\n";
const char* const slant_three_1 = "  |__  /\n";
const char* const slant_three_2 = "   /_ < \n";
const char* const slant_three_3 = " ___/ / \n";
const char* const slant_three_4 = "/____/  \n";

const char* const slant_four_0 = "   __ __\n";
const char* const slant_four_1 = "  / // /\n";
const char* const slant_four_2 = " / // /_\n";
const char* const slant_four_3 = "/__  __/\n";
const char* const slant_four_4 = "  /_/   \n";

const char* const slant_five_0 = "    ______\n";
const char* const slant_five_1 = "   / ____/\n";
const char* const slant_five_2 = "  /___ \  \n";
const char* const slant_five_3 = " ____/ /  \n";
const char* const slant_five_4 = "/_____/   \n";

const char* const slant_six_0 = "   _____\n";
const char* const slant_six_1 = "  / ___/\n";
const char* const slant_six_2 = " / __ \ \n";
const char* const slant_six_3 = "/ /_/ / \n";
const char* const slant_six_4 = "\____/  \n";

const char* const slant_seven_0 = " _____\n";
const char* const slant_seven_1 = "/__  /\n";
const char* const slant_seven_2 = "  / / \n";
const char* const slant_seven_3 = " / /  \n";
const char* const slant_seven_4 = "/_/   \n";

const char* const slant_eight_0 = "   ____ \n";
const char* const slant_eight_1 = "  ( __ )\n";
const char* const slant_eight_2 = " / __  |\n";
const char* const slant_eight_3 = "/ /_/ / \n";
const char* const slant_eight_4 = "\____/  \n";

const char* const slant_nine_0 = "   ____ \n";
const char* const slant_nine_1 = "  / __ \\n";
const char* const slant_nine_2 = " / /_/ /\n";
const char* const slant_nine_3 = " \__, / \n";
const char* const slant_nine_4 = "/____/  \n";

const char* const slant_twodots_0 = "   _ \n";
const char* const slant_twodots_1 = "  (_)\n";
const char* const slant_twodots_2 = " _   \n";
const char* const slant_twodots_3 = "(_)  \n";
const char* const slant_twodots_4 = "\n ";

const char* const font_slant[11][VEC_MAXSIZE] = 
{
    { slant_zero_0, slant_zero_1, slant_zero_2, slant_zero_3, slant_zero_4},
    { slant_one_0, slant_one_1, slant_one_2, slant_one_3, slant_one_4},
    { slant_two_0, slant_two_1, slant_two_2, slant_two_3, slant_two_4},
    { slant_three_0, slant_three_1, slant_three_2, slant_three_3, slant_three_4},
    { slant_four_0, slant_four_1, slant_four_2, slant_four_3, slant_four_4},
    { slant_five_0, slant_five_1, slant_five_2, slant_five_3, slant_five_4},
    { slant_six_0, slant_six_1, slant_six_2, slant_six_3, slant_six_4},
    { slant_seven_0, slant_seven_1, slant_seven_2, slant_seven_3, slant_seven_4},
    { slant_eight_0, slant_eight_1, slant_eight_2, slant_eight_3, slant_eight_4},
    { slant_nine_0, slant_nine_1, slant_nine_2, slant_nine_3, slant_nine_4},
    { slant_twodots_0, slant_twodots_1, slant_twodots_2, slant_twodots_3, slant_twodots_4}
}

int calculate_offset_slant(int digit_1, int digit_2);
int offset_before_twodots_slant(int num); 
int offset_after_twodots_slant(int num);
