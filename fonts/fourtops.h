
const char* const fourtops_zero_0 = " /~~\\ \n";
const char* const fourtops_zero_1 = "|    |\n";
const char* const fourtops_zero_2 = " \\__/ \n";

const char* const fourtops_one_0 = "/| \n";
const char* const fourtops_one_1 = " | \n";
const char* const fourtops_one_2 = "_|_\n";

const char* const fourtops_two_0 = "/~\\\n";
const char* const fourtops_two_1 = " ,/\n";
const char* const fourtops_two_2 = "/__\n";

const char* const fourtops_three_0 = "/~\\\n";
const char* const fourtops_three_1 = "  <\n";
const char* const fourtops_three_2 = "\\_/\n";

const char* const fourtops_four_0 = " /| \n";
const char* const fourtops_four_1 = "/_|_\n";
const char* const fourtops_four_2 = "  | \n";

const char* const fourtops_five_0 = "|~~\n";
const char* const fourtops_five_1 = "`~\\\n";
const char* const fourtops_five_2 = "__/\n";

const char* const fourtops_six_0 = "/~~\n";
const char* const fourtops_six_1 = "Y~\\\n";
const char* const fourtops_six_2 = "\\_/\n";

const char* const fourtops_seven_0 = "~~/\n";
const char* const fourtops_seven_1 = " / \n";
const char* const fourtops_seven_2 = "/  \n";

const char* const fourtops_eight_0 = "(~)\n";
const char* const fourtops_eight_1 = "/~\\\n";
const char* const fourtops_eight_2 = "\\_/\n";

const char* const fourtops_nine_0 = "/~\\\n";
const char* const fourtops_nine_1 = "`-/\n";
const char* const fourtops_nine_2 = " / \n";

const char* const fourtops_twodots_0 = ".\n";
const char* const fourtops_twodots_1 = ".\n";
const char* const fourtops_twodots_2 = "\n ";

const char* const font_fourtops[11][VEC_MAXSIZE] =
{
    {fourtops_zero_0, fourtops_zero_1, fourtops_zero_2},
    {fourtops_one_0, fourtops_one_1, fourtops_one_2},
    {fourtops_two_0, fourtops_two_1, fourtops_two_2},
    {fourtops_three_0, fourtops_three_1, fourtops_three_2},
    {fourtops_four_0, fourtops_four_1, fourtops_four_2},
    {fourtops_five_0, fourtops_five_1, fourtops_five_2},
    {fourtops_six_0, fourtops_six_1, fourtops_six_2},
    {fourtops_seven_0, fourtops_seven_1, fourtops_seven_2},
    {fourtops_eight_0, fourtops_eight_1, fourtops_eight_2},
    {fourtops_nine_0, fourtops_nine_1, fourtops_nine_2},
    {fourtops_twodots_0, fourtops_twodots_1, fourtops_twodots_2},
};

int calculate_offset_fourtops(int digit_1, int digit_2);
int offset_before_twodots_fourtops(int num);
int offset_after_twodots_fourtops(int num);
