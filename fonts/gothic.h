
const char* const gothic_zero_0 = "\n";
const char* const gothic_zero_1 = " /\\\\  \n";
const char* const gothic_zero_2 = "|| || \n";
const char* const gothic_zero_3 = "|| || \n";
const char* const gothic_zero_4 = "|| || \n";
const char* const gothic_zero_5 = "|| || \n";
const char* const gothic_zero_6 = " \\\\/  \n";

const char* const gothic_one_0 = "\n";
const char* const gothic_one_1 = " /|  \n";
const char* const gothic_one_2 = "/||  \n";
const char* const gothic_one_3 = " ||  \n";
const char* const gothic_one_4 = " ||  \n";
const char* const gothic_one_5 = " ||  \n";
const char* const gothic_one_6 = ",/-' \n";

const char* const gothic_two_0 = "\n";
const char* const gothic_two_1 = " /\\  \n";
const char* const gothic_two_2 = "(  ) \n";
const char* const gothic_two_3 = "  // \n";
const char* const gothic_two_4 = " //  \n";
const char* const gothic_two_5 = "/(   \n";
const char* const gothic_two_6 = "{___ \n";

const char* const gothic_three_0 = "____ \n";
const char* const gothic_three_1 = "` // \n";
const char* const gothic_three_2 = " //  \n";
const char* const gothic_three_3 = " \\\\  \n";
const char* const gothic_three_4 = "  )) \n";
const char* const gothic_three_5 = " //  \n";
const char* const gothic_three_6 = "/'   \n";

const char* const gothic_four_0 = "  ,  \n";
const char* const gothic_four_1 = " /|  \n";
const char* const gothic_four_2 = "/ |  \n";
const char* const gothic_four_3 = "__|_ \n";
const char* const gothic_four_4 = "---- \n";
const char* const gothic_four_5 = "  |  \n";
const char* const gothic_four_6 = " ,_, \n";

const char* const gothic_five_0 = "____  \n";
const char* const gothic_five_1 = "||  ` \n";
const char* const gothic_five_2 = "||_   \n";
const char* const gothic_five_3 = "|/ \\  \n";
const char* const gothic_five_4 = "   )) \n";
const char* const gothic_five_5 = "  //  \n";
const char* const gothic_five_6 = " /'   \n";

const char* const gothic_six_0 = "\n";
const char* const gothic_six_1 = "  ,/  \n";
const char* const gothic_six_2 = " //   \n";
const char* const gothic_six_3 = "((_-  \n";
const char* const gothic_six_4 = "|| )) \n";
const char* const gothic_six_5 = "(( || \n";
const char* const gothic_six_6 = " \\//  \n";

const char* const gothic_seven_0 = "____  \n";
const char* const gothic_seven_1 = "`  || \n";
const char* const gothic_seven_2 = "   /, \n";
const char* const gothic_seven_3 = "  //  \n";
const char* const gothic_seven_4 = " ((   \n";
const char* const gothic_seven_5 = " ||   \n";
const char* const gothic_seven_6 = " |'   \n";

const char* const gothic_eight_0 = " /\\\\  \n";
const char* const gothic_eight_1 = "|| || \n";
const char* const gothic_eight_2 = " \\ /  \n";
const char* const gothic_eight_3 = " /\\\\  \n";
const char* const gothic_eight_4 = "// \\\\ \n";
const char* const gothic_eight_5 = "|| || \n";
const char* const gothic_eight_6 = " \\\\/  \n";

const char* const gothic_nine_0 = "\n";
const char* const gothic_nine_1 = " /\\\\  \n";
const char* const gothic_nine_2 = "|| || \n";
const char* const gothic_nine_3 = "|| || \n";
const char* const gothic_nine_4 = " \\/|| \n";
const char* const gothic_nine_5 = "   || \n";
const char* const gothic_nine_6 = " \\_/  \n";

const char* const gothic_twodots_0 = "\n";
const char* const gothic_twodots_1 = "\n ";
const char* const gothic_twodots_2 = "<> \n";
const char* const gothic_twodots_3 = "\n ";
const char* const gothic_twodots_4 = "\n ";
const char* const gothic_twodots_5 = "<> \n";
const char* const gothic_twodots_6 = "\n ";

const char* const font_gothic[11][VEC_MAXSIZE] =
{
    { gothic_zero_0, gothic_zero_1, gothic_zero_2, gothic_zero_3, gothic_zero_4, gothic_zero_5, gothic_zero_6},
    { gothic_one_0, gothic_one_1, gothic_one_2, gothic_one_3, gothic_one_4, gothic_one_5, gothic_one_6},
    { gothic_two_0, gothic_two_1, gothic_two_2, gothic_two_3, gothic_two_4, gothic_two_5, gothic_two_6},
    { gothic_three_0, gothic_three_1, gothic_three_2, gothic_three_3, gothic_three_4, gothic_three_5, gothic_three_6},
    { gothic_four_0, gothic_four_1, gothic_four_2, gothic_four_3, gothic_four_4, gothic_four_5, gothic_four_6},
    { gothic_five_0, gothic_five_1, gothic_five_2, gothic_five_3, gothic_five_4, gothic_five_5, gothic_five_6},
    { gothic_six_0, gothic_six_1, gothic_six_2, gothic_six_3, gothic_six_4, gothic_six_5, gothic_six_6},
    { gothic_seven_0, gothic_seven_1, gothic_seven_2, gothic_seven_3, gothic_seven_4, gothic_seven_5, gothic_seven_6},
    { gothic_eight_0, gothic_eight_1, gothic_eight_2, gothic_eight_3, gothic_eight_4, gothic_eight_5, gothic_eight_6},
    { gothic_nine_0, gothic_nine_1, gothic_nine_2, gothic_nine_3, gothic_nine_4, gothic_nine_5, gothic_nine_6},
    { gothic_twodots_0, gothic_twodots_1, gothic_twodots_2, gothic_twodots_3, gothic_twodots_4, gothic_twodots_5, gothic_twodots_6}
};

int calculate_offset_gothic(int digit_1, int digit_2);
int offset_before_twodots_gothic(int num);
int offset_after_twodots_gothic(int num);
