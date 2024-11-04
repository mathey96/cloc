
const char* const serifcap_zero_0 = "  __  \n";
const char* const serifcap_zero_1 = " /  \\ \n";
const char* const serifcap_zero_2 = "( () )\n";
const char* const serifcap_zero_3 = " \\__/ \n";

const char* const serifcap_one_0 = " __ \n";
const char* const serifcap_one_1 = "(  )\n";
const char* const serifcap_one_2 = " )( \n";
const char* const serifcap_one_3 = "(__)\n";

const char* const serifcap_two_0 = " ___ \n";
const char* const serifcap_two_1 = "(__ \\\n";
const char* const serifcap_two_2 = "/ __/\n";
const char* const serifcap_two_3 = "\\___)\n";

const char* const serifcap_three_0 = " ___ \n";
const char* const serifcap_three_1 = "(__ )\n";
const char* const serifcap_three_2 = " (_ \\\n";
const char* const serifcap_three_3 = "(___/\n";

const char* const serifcap_four_0 = "  __  \n";
const char* const serifcap_four_1 = " / ,) \n";
const char* const serifcap_four_2 = "(_  _)\n";
const char* const serifcap_four_3 = "  (_) \n";

const char* const serifcap_five_0 = " ___ \n";
const char* const serifcap_five_1 = "/ __)\n";
const char* const serifcap_five_2 = "\\__ \\\n";
const char* const serifcap_five_3 = "(___/\n";

const char* const serifcap_six_0 = "  _  \n";
const char* const serifcap_six_1 = " / ) \n";
const char* const serifcap_six_2 = "/ , \\\n";
const char* const serifcap_six_3 = "\\___/\n";

const char* const serifcap_seven_0 = " ___ \n";
const char* const serifcap_seven_1 = "(__ )\n";
const char* const serifcap_seven_2 = " / / \n";
const char* const serifcap_seven_3 = "(_/  \n";

const char* const serifcap_eight_0 = " ___ \n";
const char* const serifcap_eight_1 = "( , )\n";
const char* const serifcap_eight_2 = "/ , \\\n";
const char* const serifcap_eight_3 = "\\___/\n";

const char* const serifcap_nine_0 = " ___ \n";
const char* const serifcap_nine_1 = "/ , \\\n";
const char* const serifcap_nine_2 = "\\   /\n";
const char* const serifcap_nine_3 = " (_/ \n";

const char* const serifcap_twodots_0 = " _ \n";
const char* const serifcap_twodots_1 = "(_)\n";
const char* const serifcap_twodots_2 = " _ \n";
const char* const serifcap_twodots_3 = "(_)\n";

const char* const font_serifcap[11][VEC_MAXSIZE] =
{
    { serifcap_zero_0, serifcap_zero_1, serifcap_zero_2, serifcap_zero_3},
    { serifcap_one_0, serifcap_one_1, serifcap_one_2, serifcap_one_3},
    { serifcap_two_0, serifcap_two_1, serifcap_two_2, serifcap_two_3},
    { serifcap_three_0, serifcap_three_1, serifcap_three_2, serifcap_three_3},
    { serifcap_four_0, serifcap_four_1, serifcap_four_2, serifcap_four_3},
    { serifcap_five_0, serifcap_five_1, serifcap_five_2, serifcap_five_3},
    { serifcap_six_0, serifcap_six_1, serifcap_six_2, serifcap_six_3},
    { serifcap_seven_0, serifcap_seven_1, serifcap_seven_2, serifcap_seven_3},
    { serifcap_eight_0, serifcap_eight_1, serifcap_eight_2, serifcap_eight_3},
    { serifcap_nine_0, serifcap_nine_1, serifcap_nine_2, serifcap_nine_3},
    { serifcap_twodots_0, serifcap_twodots_1, serifcap_twodots_2, serifcap_twodots_3}
};

int calculate_offset_serifcap(int digit_1, int digit_2);
int offset_before_twodots_serifcap(int num);
int offset_after_twodots_serifcap(int num);
