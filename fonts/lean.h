#include "../macros.h"


const char* const lean_zero_0 = "\n";
const char* const lean_zero_1 = "     _/    \n";
const char* const lean_zero_2 = "  _/  _/   \n";
const char* const lean_zero_3 = " _/  _/    \n";
const char* const lean_zero_4 = "_/  _/     \n";
const char* const lean_zero_5 = " _/        \n";



const char* const lean_one_0 = "\n";
const char* const lean_one_1 = "    _/   \n";
const char* const lean_one_2 = " _/_/    \n";
const char* const lean_one_3 = "  _/     \n";
const char* const lean_one_4 = " _/      \n";
const char* const lean_one_5 = "_/       \n";



const char* const lean_two_0 = "\n";
const char* const lean_two_1 = "      _/_/    \n";
const char* const lean_two_2 = "   _/    _/   \n";
const char* const lean_two_3 = "      _/      \n";
const char* const lean_two_4 = "   _/         \n";
const char* const lean_two_5 = "_/_/_/_/      \n";



const char* const lean_three_0 = "\n";
const char* const lean_three_1 = "    _/_/_/    \n";
const char* const lean_three_2 = "         _/   \n";
const char* const lean_three_3 = "    _/_/      \n";
const char* const lean_three_4 = "       _/     \n";
const char* const lean_three_5 = "_/_/_/        \n";



const char* const lean_four_0 = "\n";
const char* const lean_four_1 = "  _/  _/   \n";
const char* const lean_four_2 = " _/  _/    \n";
const char* const lean_four_3 = "_/_/_/_/   \n";
const char* const lean_four_4 = "   _/      \n";
const char* const lean_four_5 = "  _/       \n";



const char* const lean_five_0 = "\n";
const char* const lean_five_1 = "    _/_/_/_/   \n";
const char* const lean_five_2 = "   _/          \n";
const char* const lean_five_3 = "  _/_/_/       \n";
const char* const lean_five_4 = "       _/      \n";
const char* const lean_five_5 = "_/_/_/         \n";



const char* const lean_six_0 = "\n";
const char* const lean_six_1 = "     _/_/_/   \n";
const char* const lean_six_2 = "  _/          \n";
const char* const lean_six_3 = " _/_/_/       \n";
const char* const lean_six_4 = "_/    _/      \n";
const char* const lean_six_5 = " _/_/         \n";



const char* const lean_seven_0 = "\n";
const char* const lean_seven_1 = "  _/_/_/_/_/   \n";
const char* const lean_seven_2 = "         _/    \n";
const char* const lean_seven_3 = "      _/       \n";
const char* const lean_seven_4 = "   _/          \n";
const char* const lean_seven_5 = "_/             \n";



const char* const lean_eight_0 = "\n";
const char* const lean_eight_1 = "     _/_/    \n";
const char* const lean_eight_2 = "  _/    _/   \n";
const char* const lean_eight_3 = "   _/_/      \n";
const char* const lean_eight_4 = "_/    _/     \n";
const char* const lean_eight_5 = " _/_/        \n";



const char* const lean_nine_0 = "\n";
const char* const lean_nine_1 = "      _/_/    \n";
const char* const lean_nine_2 = "   _/    _/   \n";
const char* const lean_nine_3 = "    _/_/_/    \n";
const char* const lean_nine_4 = "       _/     \n";
const char* const lean_nine_5 = "_/_/_/        \n";




const char* const lean_twodots_0 = "\n";
const char* const lean_twodots_1 = "   _/   \n";
const char* const lean_twodots_2 = "\n ";
const char* const lean_twodots_3 = "\n ";
const char* const lean_twodots_4 = "_/      \n";
const char* const lean_twodots_5 = "\n ";


const char* const font_lean[11][VEC_MAXSIZE] =
{
	{lean_zero_0,    lean_zero_1,    lean_zero_2,    lean_zero_3,    lean_zero_4,    lean_zero_5},
	{lean_one_0,     lean_one_1,     lean_one_2,     lean_one_3,     lean_one_4,     lean_one_5},
	{lean_two_0,     lean_two_1,     lean_two_2,     lean_two_3,     lean_two_4,     lean_two_5},
	{lean_three_0,   lean_three_1,   lean_three_2,   lean_three_3,   lean_three_4,   lean_three_5},
	{lean_four_0,    lean_four_1,    lean_four_2,    lean_four_3,    lean_four_4,    lean_four_5},
	{lean_five_0,    lean_five_1,    lean_five_2,    lean_five_3,    lean_five_4,    lean_five_5},
	{lean_six_0,     lean_six_1,     lean_six_2,     lean_six_3,     lean_six_4,     lean_six_5},
	{lean_seven_0,   lean_seven_1,   lean_seven_2,   lean_seven_3,   lean_seven_4,   lean_seven_5},
	{lean_eight_0,   lean_eight_1,   lean_eight_2,   lean_eight_3,   lean_eight_4,   lean_eight_5},
	{lean_nine_0,    lean_nine_1,    lean_nine_2,    lean_nine_3,    lean_nine_4,    lean_nine_5},
	{lean_twodots_0, lean_twodots_1, lean_twodots_2, lean_twodots_3, lean_twodots_4, lean_twodots_5}
};

int calculate_offset_lean(int digit_1, int digit_2);
int offset_before_twodots_lean(int num);
int offset_after_twodots_lean(int num);
