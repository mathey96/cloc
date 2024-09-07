#include "../macros.h"

const char* const smshadow_zero_0 = "\n";
const char* const smshadow_zero_1 = "   \\  \n";
const char* const smshadow_zero_2 = " (  | \n";
const char* const smshadow_zero_3 = "\\__/  \n";

const char* const smshadow_one_0 = "\n";
const char* const smshadow_one_1 = "_ | \n";
const char* const smshadow_one_2 = "  | \n";
const char* const smshadow_one_3 = " _| \n";

const char* const smshadow_two_0 = "\n";
const char* const smshadow_two_1 = "_  ) \n";
const char* const smshadow_two_2 = "  /  \n";
const char* const smshadow_two_3 = "___| \n";

const char* const smshadow_three_0 = "\n";
const char* const smshadow_three_1 = "__ / \n";
const char* const smshadow_three_2 = " _ \\ \n";
const char* const smshadow_three_3 = "___/ \n";

const char* const smshadow_four_0 = "\n";
const char* const smshadow_four_1 = " | |  \n";
const char* const smshadow_four_2 = "__ _| \n";
const char* const smshadow_four_3 = "  _|  \n";

const char* const smshadow_five_0 = "\n";
const char* const smshadow_five_1 = " __| \n";
const char* const smshadow_five_2 = "__ \\ \n";
const char* const smshadow_five_3 = "___/ \n";

const char* const smshadow_six_0 = "\n";
const char* const smshadow_six_1 = "  /   \n";
const char* const smshadow_six_2 = "  _ \\ \n";
const char* const smshadow_six_3 = "\\___/ \n";

const char* const smshadow_seven_0 = "\n";
const char* const smshadow_seven_1 = "__  / \n";
const char* const smshadow_seven_2 = "   /  \n";
const char* const smshadow_seven_3 = " _/   \n";

const char* const smshadow_eight_0 = "\n";
const char* const smshadow_eight_1 = "  _ ) \n";
const char* const smshadow_eight_2 = "  _ \\ \n";
const char* const smshadow_eight_3 = "\\___/ \n";

const char* const smshadow_nine_0 = "\n";
const char* const smshadow_nine_1 = "  _ \\ \n";
const char* const smshadow_nine_2 = "\\_  / \n";
const char* const smshadow_nine_3 = "  _/  \n";

const char* const smshadow_twodots_0 = "\n";
const char* const smshadow_twodots_1 = "_) \n";
const char* const smshadow_twodots_2 = "\n ";
const char* const smshadow_twodots_3 = "_) \n";


const char* const font_smshadow[11][VEC_MAXSIZE] =
{
	{smshadow_zero_0,    smshadow_zero_1,    smshadow_zero_2,    smshadow_zero_3},
	{smshadow_one_0,     smshadow_one_1,     smshadow_one_2,     smshadow_one_3},
	{smshadow_two_0,     smshadow_two_1,     smshadow_two_2,     smshadow_two_3},
	{smshadow_three_0,   smshadow_three_1,   smshadow_three_2,   smshadow_three_3},
	{smshadow_four_0,    smshadow_four_1,    smshadow_four_2,    smshadow_four_3},
	{smshadow_five_0,    smshadow_five_1,    smshadow_five_2,    smshadow_five_3},
	{smshadow_six_0,     smshadow_six_1,     smshadow_six_2,     smshadow_six_3},
	{smshadow_seven_0,   smshadow_seven_1,   smshadow_seven_2,   smshadow_seven_3},
	{smshadow_eight_0,   smshadow_eight_1,   smshadow_eight_2,   smshadow_eight_3},
	{smshadow_nine_0,    smshadow_nine_1,    smshadow_nine_2,    smshadow_nine_3},
	{smshadow_twodots_0, smshadow_twodots_1, smshadow_twodots_2, smshadow_twodots_3}
};

int calculate_offset_smshadow(int digit_1, int digit_2);
int offset_before_twodots_smshadow(int num);
int offset_after_twodots_smshadow(int num);
