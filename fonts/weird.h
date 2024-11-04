
const char* const weird_zero_0 = "  __ \n";
const char* const weird_zero_1 = " /  |\n";
const char* const weird_zero_2 = "(   |\n";
const char* const weird_zero_3 = "|   )\n";
const char* const weird_zero_4 = "|__/ \n";

const char* const weird_one_0 = "  _  \n";
const char* const weird_one_1 = " /|  \n";
const char* const weird_one_2 = "( |  \n";
const char* const weird_one_3 = "  | )\n";
const char* const weird_one_4 = " _|/ \n";

const char* const weird_two_0 = "  __ \n";
const char* const weird_two_1 = " /  )\n";
const char* const weird_two_2 = "(  / \n";
const char* const weird_two_3 = "  / )\n";
const char* const weird_two_4 = " /_/ \n";

const char* const weird_three_0 = "  __ \n";
const char* const weird_three_1 = "    |\n";
const char* const weird_three_2 = " ___|\n";
const char* const weird_three_3 = "    )\n";
const char* const weird_three_4 = " __/ \n";

const char* const weird_four_0 = "\n";
const char* const weird_four_1 = " /  |\n";
const char* const weird_four_2 = "(___|\n";
const char* const weird_four_3 = "    )\n";
const char* const weird_four_4 = "   / \n";

const char* const weird_five_0 = "  __ \n";
const char* const weird_five_1 = " /   \n";
const char* const weird_five_2 = "|___ \n";
const char* const weird_five_3 = "    )\n";
const char* const weird_five_4 = " __/ \n";

const char* const weird_six_0 = "  __ \n";
const char* const weird_six_1 = " /   \n";
const char* const weird_six_2 = "(___ \n";
const char* const weird_six_3 = "|   )\n";
const char* const weird_six_4 = "|__/ \n";

const char* const weird_seven_0 = "  __ \n";
const char* const weird_seven_1 = " /  |\n";
const char* const weird_seven_2 = "(   |\n";
const char* const weird_seven_3 = "    )\n";
const char* const weird_seven_4 = "   / \n";

const char* const weird_eight_0 = "  __ \n";
const char* const weird_eight_1 = " /  |\n";
const char* const weird_eight_2 = "(___|\n";
const char* const weird_eight_3 = "|   )\n";
const char* const weird_eight_4 = "|__/ \n";

const char* const weird_nine_0 = "  __ \n";
const char* const weird_nine_1 = " /  |\n";
const char* const weird_nine_2 = "(___|\n";
const char* const weird_nine_3 = "    )\n";
const char* const weird_nine_4 = " __/ \n";

const char* const weird_twodots_0 = "\n";
const char* const weird_twodots_1 = " _  \n";
const char* const weird_twodots_2 = "\n ";
const char* const weird_twodots_3 = " -  \n";
const char* const weird_twodots_4 = "\n ";

const char* const font_weird[11][VEC_MAXSIZE] =
{
    {weird_zero_0       ,weird_zero_1      ,weird_zero_2      ,weird_zero_3      ,weird_zero_4},
    {weird_one_0        ,weird_one_1       ,weird_one_2       ,weird_one_3       ,weird_one_4},
    {weird_two_0        ,weird_two_1       ,weird_two_2       ,weird_two_3       ,weird_two_4},
    {weird_three_0      ,weird_three_1     ,weird_three_2     ,weird_three_3     ,weird_three_4},
    {weird_four_0       ,weird_four_1      ,weird_four_2      ,weird_four_3      ,weird_four_4},
    {weird_five_0       ,weird_five_1      ,weird_five_2      ,weird_five_3      ,weird_five_4},
    {weird_six_0        ,weird_six_1       ,weird_six_2       ,weird_six_3       ,weird_six_4},
    {weird_seven_0      ,weird_seven_1     ,weird_seven_2     ,weird_seven_3     ,weird_seven_4},
    {weird_eight_0      ,weird_eight_1     ,weird_eight_2     ,weird_eight_3     ,weird_eight_4},
    {weird_nine_0       ,weird_nine_1      ,weird_nine_2      ,weird_nine_3      ,weird_nine_4},
    {weird_twodots_0    ,weird_twodots_1   ,weird_twodots_2   ,weird_twodots_3   ,weird_twodots_4}
};

int calculate_offset_weird(int digit_1, int digit_2);
int offset_before_twodots_weird(int num);
int offset_after_twodots_weird(int num);
