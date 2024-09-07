#include "../macros.h"

const char* const smscript_zero_0 = "\n";
const char* const smscript_zero_1 = "  _  \n";
const char* const smscript_zero_2 = " / \\\n";
const char* const smscript_zero_3 = "|   |\n";
const char* const smscript_zero_4 = " \\_/ \n";

const char* const smscript_one_0 = "\n";
const char* const smscript_one_1 = " ,\n";
const char* const smscript_one_2 = "/|\n";
const char* const smscript_one_3 = " |\n";
const char* const smscript_one_4 = " |\n";

const char* const smscript_two_0 = "\n";
const char* const smscript_two_1 = " _ \n";
const char* const smscript_two_2 = "/ )\n";
const char* const smscript_two_3 = " / \n";
const char* const smscript_two_4 = "/__\n";

const char* const smscript_three_0 = "\n";
const char* const smscript_three_1 = "____\n";
const char* const smscript_three_2 = " __/\n";
const char* const smscript_three_3 = "   \\\n";
const char* const smscript_three_4 = "\\__/\n";


const char* const smscript_four_0 = "\n";
const char* const smscript_four_1 = "\n";
const char* const smscript_four_2 = "|  | \n";
const char* const smscript_four_3 = "|__|_\n";
const char* const smscript_four_4 = "   | \n";

const char* const smscript_five_0 = "\n";
const char* const smscript_five_1 = " ___\n";
const char* const smscript_five_2 = "|__ \n";
const char* const smscript_five_3 = "   \\\n";
const char* const smscript_five_4 = "\\__/\n";

const char* const smscript_six_0 = "\n";
const char* const smscript_six_1 = "  _ \n";
const char* const smscript_six_2 = " /_ \n";
const char* const smscript_six_3 = "|/ \\\n";
const char* const smscript_six_4 = " \\_/\n";

const char* const smscript_seven_0 = "\n";
const char* const smscript_seven_1 = "____\n";
const char* const smscript_seven_2 = "   /\n";
const char* const smscript_seven_3 = "  / \n";
const char* const smscript_seven_4 = " /  \n";

const char* const smscript_eight_0 = "\n";
const char* const smscript_eight_1 = " __ \n";
const char* const smscript_eight_2 = "(__)\n";
const char* const smscript_eight_3 = "/  \\\n";
const char* const smscript_eight_4 = "\\__/\n";

const char* const smscript_nine_0 = "\n";
const char* const smscript_nine_1 = " __ \n";
const char* const smscript_nine_2 = "/  |\n";
const char* const smscript_nine_3 = "\\_/|\n";
const char* const smscript_nine_4 = "   |\n";


const char* const smscript_twodots_0 = "\n";
const char* const smscript_twodots_1 = "\n ";
const char* const smscript_twodots_2 = "o\n";
const char* const smscript_twodots_3 = "\n ";
const char* const smscript_twodots_4 = "o\n";


const char* const font_smscript[11][VEC_MAXSIZE] =
{
	{smscript_zero_0,    smscript_zero_1,    smscript_zero_2,    smscript_zero_3,    smscript_zero_4},
	{smscript_one_0,     smscript_one_1,     smscript_one_2,     smscript_one_3,     smscript_one_4},
	{smscript_two_0,     smscript_two_1,     smscript_two_2,     smscript_two_3,     smscript_two_4},
	{smscript_three_0,   smscript_three_1,   smscript_three_2,   smscript_three_3,   smscript_three_4},
	{smscript_four_0,    smscript_four_1,    smscript_four_2,    smscript_four_3,    smscript_four_4},
	{smscript_five_0,    smscript_five_1,    smscript_five_2,    smscript_five_3,    smscript_five_4},
	{smscript_six_0,     smscript_six_1,     smscript_six_2,     smscript_six_3,     smscript_six_4},
	{smscript_seven_0,   smscript_seven_1,   smscript_seven_2,   smscript_seven_3,   smscript_seven_4},
	{smscript_eight_0,   smscript_eight_1,   smscript_eight_2,   smscript_eight_3,   smscript_eight_4},
	{smscript_nine_0,    smscript_nine_1,    smscript_nine_2,    smscript_nine_3,    smscript_nine_4},
	{smscript_twodots_0, smscript_twodots_1, smscript_twodots_2, smscript_twodots_3, smscript_twodots_4}
};

int calculate_offset_smscript(int digit_1, int digit_2);
int offset_before_twodots_smscript(int num);
int offset_after_twodots_smscript(int num);
