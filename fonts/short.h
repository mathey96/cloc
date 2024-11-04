
const char* const short_zero_0 = "/\\\n";
const char* const short_zero_1 = "\\/\n";

const char* const short_one_0 = "'| \n";
const char* const short_one_1 = "_|_\n";

const char* const short_two_0 = "')\n";
const char* const short_two_1 = "/_\n";

const char* const short_three_0 = "')\n";
const char* const short_three_1 = ".)\n";

const char* const short_four_0 = "/| \n";
const char* const short_four_1 = "~|~\n";

const char* const short_five_0 = "|~\n";
const char* const short_five_1 = "_)\n";

const char* const short_six_0 = " / \n";
const char* const short_six_1 = "(_)\n";

const char* const short_seven_0 = "~/\n";
const char* const short_seven_1 = "/ \n";

const char* const short_eight_0 = "(~)\n";
const char* const short_eight_1 = "(_)\n";

const char* const short_nine_0 = "(~)\n";
const char* const short_nine_1 = " / \n";

const char* const short_twodots_0 = " .\n";
const char* const short_twodots_1 = " .\n";

const char* const font_short[11][VEC_MAXSIZE] =
{
    { short_zero_0, short_zero_1},
    { short_one_0, short_one_1},
    { short_two_0, short_two_1},
    { short_three_0, short_three_1},
    { short_four_0, short_four_1},
    { short_five_0, short_five_1},
    { short_six_0, short_six_1},
    { short_seven_0, short_seven_1},
    { short_eight_0, short_eight_1},
    { short_nine_0, short_nine_1},
    { short_twodots_0, short_twodots_1}
};

int calculate_offset_short(int digit_1, int digit_2);
int offset_before_twodots_short(int num);
int offset_after_twodots_short(int num);
