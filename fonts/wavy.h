
const char* const wavy_zero_0 = " _   \n";
const char* const wavy_zero_1 = "(.\\  \n";
const char* const wavy_zero_2 = " \\_) \n";

const char* const wavy_one_0 = "\n";
const char* const wavy_one_1 = "/(   \n";
const char* const wavy_one_2 = " _)_ \n";

const char* const wavy_two_0 = "_  \n";
const char* const wavy_two_1 = " ) \n";
const char* const wavy_two_2 = "/_ \n";

const char* const wavy_three_0 = "_  \n";
const char* const wavy_three_1 = "_) \n";
const char* const wavy_three_2 = "_) \n";

const char* const wavy_four_0 = "\n";
const char* const wavy_four_1 = "/_(_ \n";
const char* const wavy_four_2 = "   ) \n";

const char* const wavy_five_0 = "__  \n";
const char* const wavy_five_1 = ")_  \n";
const char* const wavy_five_2 = " _) \n";

const char* const wavy_six_0 = " _   \n";
const char* const wavy_six_1 = "(__  \n";
const char* const wavy_six_2 = " \\_) \n";

const char* const wavy_seven_0 = "__  \n";
const char* const wavy_seven_1 = "  ) \n";
const char* const wavy_seven_2 = " (  \n";

const char* const wavy_eight_0 = " _  \n";
const char* const wavy_eight_1 = "(_) \n";
const char* const wavy_eight_2 = "(_) \n";

const char* const wavy_nine_0 = " _   \n";
const char* const wavy_nine_1 = "(_\\  \n";
const char* const wavy_nine_2 = "  _) \n";

const char* const wavy_twodots_0 = "o \n";
const char* const wavy_twodots_1 = "o \n";
const char* const wavy_twodots_2 = "\n ";

const char* const font_wavy[11][VEC_MAXSIZE] =
{
    {wavy_zero_0       ,wavy_zero_1    ,wavy_zero_2},
    {wavy_one_0        ,wavy_one_1     ,wavy_one_2},
    {wavy_two_0        ,wavy_two_1     ,wavy_two_2},
    {wavy_three_0      ,wavy_three_1   ,wavy_three_2},
    {wavy_four_0       ,wavy_four_1    ,wavy_four_2},
    {wavy_five_0       ,wavy_five_1    ,wavy_five_2},
    {wavy_six_0        ,wavy_six_1     ,wavy_six_2},
    {wavy_seven_0      ,wavy_seven_1   ,wavy_seven_2},
    {wavy_eight_0      ,wavy_eight_1   ,wavy_eight_2},
    {wavy_nine_0       ,wavy_nine_1    ,wavy_nine_2},
    {wavy_twodots_0    ,wavy_twodots_1 ,wavy_twodots_2}
};

int calculate_offset_wavy(int digit_1, int digit_2);
int offset_before_twodots_wavy(int num);
int offset_after_twodots_wavy(int num);
