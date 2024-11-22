
const char* const thin_zero_0 = ",--.\n";
const char* const thin_zero_1 = "|  |\n";
const char* const thin_zero_2 = "|  |\n";
const char* const thin_zero_3 = "`--'\n";

const char* const thin_one_0 = " '|\n";
const char* const thin_one_1 = "  |\n";
const char* const thin_one_2 = "  |\n";
const char* const thin_one_3 = "  `\n";

const char* const thin_two_0 = ",--.\n";
const char* const thin_two_1 = ",--'\n";
const char* const thin_two_2 = "|   \n";
const char* const thin_two_3 = "`--'\n";

const char* const thin_three_0 = ",--.\n";
const char* const thin_three_1 = "  -|\n";
const char* const thin_three_2 = "   |\n";
const char* const thin_three_3 = "`--'\n";

const char* const thin_four_0 = "|  |\n";
const char* const thin_four_1 = "`--|\n";
const char* const thin_four_2 = "   |\n";
const char* const thin_four_3 = "   `\n";

const char* const thin_five_0 = "---.\n";
const char* const thin_five_1 = "`--.\n";
const char* const thin_five_2 = "   |\n";
const char* const thin_five_3 = "`--'\n";

const char* const thin_six_0 = ",--.\n";
const char* const thin_six_1 = "|--.\n";
const char* const thin_six_2 = "|  |\n";
const char* const thin_six_3 = "`--'\n";

const char* const thin_seven_0 = "---.\n";
const char* const thin_seven_1 = "   /\n";
const char* const thin_seven_2 = "  | \n";
const char* const thin_seven_3 = "  | \n";

const char* const thin_eight_0 = ",--.\n";
const char* const thin_eight_1 = ",--.\n";
const char* const thin_eight_2 = "|  |\n";
const char* const thin_eight_3 = "`--'\n";

const char* const thin_nine_0 = ",--.\n";
const char* const thin_nine_1 = "`__|\n";
const char* const thin_nine_2 = "   |\n";
const char* const thin_nine_3 = "   '\n";

const char* const thin_twodots_0 = "\n ";
const char* const thin_twodots_1 = "o\n";
const char* const thin_twodots_2 = "\n ";
const char* const thin_twodots_3 = "o\n";

const char* const font_thin[11][VEC_MAXSIZE] = 
{
    {thin_zero_0, thin_zero_1, thin_zero_2, thin_zero_3},
    {thin_one_0, thin_one_1, thin_one_2, thin_one_3},
    {thin_two_0, thin_two_1, thin_two_2, thin_two_3},
    {thin_three_0, thin_three_1, thin_three_2, thin_three_3},
    {thin_four_0, thin_four_1, thin_four_2, thin_four_3},
    {thin_five_0, thin_five_1, thin_five_2, thin_five_3},
    {thin_six_0, thin_six_1, thin_six_2, thin_six_3},
    {thin_seven_0, thin_seven_1, thin_seven_2, thin_seven_3},
    {thin_eight_0, thin_eight_1, thin_eight_2, thin_eight_3},
    {thin_nine_0, thin_nine_1, thin_nine_2, thin_nine_3},
    {thin_twodots_0, thin_twodots_1, thin_twodots_2, thin_twodots_3}
};

int calculate_offset_thin(int digit_1, int digit_2);
int offset_before_twodots_thin(int num); 
int offset_after_twodots_thin(int num);
