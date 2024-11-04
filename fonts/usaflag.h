
const char* const usaflag_zero_0 = " :::==== \n";
const char* const usaflag_zero_1 = " :::  ===\n";
const char* const usaflag_zero_2 = " ===  ===\n";
const char* const usaflag_zero_3 = " ===  ===\n";
const char* const usaflag_zero_4 = "  ====== \n";

const char* const usaflag_one_0 = " :::\n";
const char* const usaflag_one_1 = " :::\n";
const char* const usaflag_one_2 = " ===\n";
const char* const usaflag_one_3 = " ===\n";
const char* const usaflag_one_4 = " ===\n";

const char* const usaflag_two_0 = " :::==== \n";
const char* const usaflag_two_1 = " ::   ===\n";
const char* const usaflag_two_2 = "    ==== \n";
const char* const usaflag_two_3 = "  ===    \n";
const char* const usaflag_two_4 = " ========\n";

const char* const usaflag_three_0 = " :::=== \n";
const char* const usaflag_three_1 = "     ===\n";
const char* const usaflag_three_2 = "  ===== \n";
const char* const usaflag_three_3 = "     ===\n";
const char* const usaflag_three_4 = " ====== \n";

const char* const usaflag_four_0 = " :::  ===\n";
const char* const usaflag_four_1 = " :::  ===\n";
const char* const usaflag_four_2 = " ========\n";
const char* const usaflag_four_3 = "      ===\n";
const char* const usaflag_four_4 = "      ===\n";

const char* const usaflag_five_0 = " :::====\n";
const char* const usaflag_five_1 = " :::    \n";
const char* const usaflag_five_2 = " ====== \n";
const char* const usaflag_five_3 = "     ===\n";
const char* const usaflag_five_4 = " ====== \n";

const char* const usaflag_six_0 = " :::==== \n";
const char* const usaflag_six_1 = " :::     \n";
const char* const usaflag_six_2 = " ======= \n";
const char* const usaflag_six_3 = " ===  ===\n";
const char* const usaflag_six_4 = "  ====== \n";

const char* const usaflag_seven_0 = " :::=====\n";
const char* const usaflag_seven_1 = "      ===\n";
const char* const usaflag_seven_2 = "     === \n";
const char* const usaflag_seven_3 = "  ====   \n";
const char* const usaflag_seven_4 = " ===     \n";

const char* const usaflag_eight_0 = " :::==== \n";
const char* const usaflag_eight_1 = " :::  ===\n";
const char* const usaflag_eight_2 = "  ====== \n";
const char* const usaflag_eight_3 = " ===  ===\n";
const char* const usaflag_eight_4 = "  ====== \n";

const char* const usaflag_nine_0 = " :::==== \n";
const char* const usaflag_nine_1 = " :::  ===\n";
const char* const usaflag_nine_2 = "  =======\n";
const char* const usaflag_nine_3 = "      ===\n";
const char* const usaflag_nine_4 = "  =====  \n";

const char* const usaflag_twodots_0 = " ==\n";
const char* const usaflag_twodots_1 = "\n ";
const char* const usaflag_twodots_2 = " ==\n";
const char* const usaflag_twodots_3 = "\n ";
const char* const usaflag_twodots_4 = "\n ";

const char* const font_usaflag[11][VEC_MAXSIZE] =
{
    {usaflag_zero_0    ,usaflag_zero_1    ,usaflag_zero_2    ,usaflag_zero_3    ,usaflag_zero_4},
    {usaflag_one_0     ,usaflag_one_1     ,usaflag_one_2     ,usaflag_one_3     ,usaflag_one_4},
    {usaflag_two_0     ,usaflag_two_1     ,usaflag_two_2     ,usaflag_two_3     ,usaflag_two_4},
    {usaflag_three_0   ,usaflag_three_1   ,usaflag_three_2   ,usaflag_three_3   ,usaflag_three_4},
    {usaflag_four_0    ,usaflag_four_1    ,usaflag_four_2    ,usaflag_four_3    ,usaflag_four_4},
    {usaflag_five_0    ,usaflag_five_1    ,usaflag_five_2    ,usaflag_five_3    ,usaflag_five_4},
    {usaflag_six_0     ,usaflag_six_1     ,usaflag_six_2     ,usaflag_six_3     ,usaflag_six_4 },
    {usaflag_seven_0   ,usaflag_seven_1   ,usaflag_seven_2   ,usaflag_seven_3   ,usaflag_seven_4},
    {usaflag_eight_0   ,usaflag_eight_1   ,usaflag_eight_2   ,usaflag_eight_3   ,usaflag_eight_4},
    {usaflag_nine_0    ,usaflag_nine_1    ,usaflag_nine_2    ,usaflag_nine_3    ,usaflag_nine_4},
    {usaflag_twodots_0 ,usaflag_twodots_1 ,usaflag_twodots_2 ,usaflag_twodots_3 ,usaflag_twodots_4}
};

int calculate_offset_usaflag(int digit_1, int digit_2);
int offset_before_twodots_usaflag(int num);
int offset_after_twodots_usaflag(int num);
