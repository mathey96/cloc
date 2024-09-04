
const char* const smslant_zero_0 = "\n";
const char* const smslant_zero_1 = "  ___ \n";
const char* const smslant_zero_2 = " / _ \\n";
const char* const smslant_zero_3 = "/ // /\n";
const char* const smslant_zero_4 = "\___/ \n";

const char* const smslant_one_0 = "\n";
const char* const smslant_one_1 = "  ___\n";
const char* const smslant_one_2 = " <  /\n";
const char* const smslant_one_3 = " / / \n";
const char* const smslant_one_4 = "/_/  \n";

const char* const smslant_two_0 = "\n";
const char* const smslant_two_1 = "   ___ \n";
const char* const smslant_two_2 = "  |_  |\n";
const char* const smslant_two_3 = " / __/ \n";
const char* const smslant_two_4 = "/____/ \n";

const char* const smslant_three_0 = "\n";
const char* const smslant_three_1 = "   ____\n";
const char* const smslant_three_2 = "  |_  /\n";
const char* const smslant_three_3 = " _/_ < \n";
const char* const smslant_three_4 = "/____/ \n";

const char* const smslant_four_0 = "\n";
const char* const smslant_four_1 = "  ____\n";
const char* const smslant_four_2 = " / / /\n";
const char* const smslant_four_3 = "/_  _/\n";
const char* const smslant_four_4 = " /_/  \n";

const char* const smslant_five_0 = "\n";
const char* const smslant_five_1 = "   ____\n";
const char* const smslant_five_2 = "  / __/\n";
const char* const smslant_five_3 = " /__ \ \n";
const char* const smslant_five_4 = "/____/ \n";

const char* const smslant_six_0 = "\n";
const char* const smslant_six_1 = "  ____\n";
const char* const smslant_six_2 = " / __/\n";
const char* const smslant_six_3 = "/ _ \ \n";
const char* const smslant_six_4 = "\___/ \n";

const char* const smslant_seven_0 = "\n";
const char* const smslant_seven_1 = " ____\n";
const char* const smslant_seven_2 = "/_  /\n";
const char* const smslant_seven_3 = " / / \n";
const char* const smslant_seven_4 = "/_/  \n";

const char* const smslant_eight_0 = "\n";
const char* const smslant_eight_1 = "  ___ \n";
const char* const smslant_eight_2 = " ( _ )\n";
const char* const smslant_eight_3 = "/ _  |\n";
const char* const smslant_eight_4 = "\___/ \n";

const char* const smslant_nine_0 = "\n";
const char* const smslant_nine_1 = "  ___ \n";
const char* const smslant_nine_2 = " / _ \\n";
const char* const smslant_nine_3 = " \_, /\n";
const char* const smslant_nine_4 = "/___/ \n";

const char* const smslant_twodots_0 = "\n";
const char* const smslant_twodots_1 = "   _ \n";
const char* const smslant_twodots_2 = "  (_)\n";
const char* const smslant_twodots_3 = " _   \n";
const char* const smslant_twodots_4 = "(_)  \n";

const char* const font_smslant[11][7] =
{
	{smslant_zero_0,    smslant_zero_1,    smslant_zero_2,    smslant_zero_3,    smslant_zero_4},
	{smslant_one_0,     smslant_one_1,     smslant_one_2,     smslant_one_3,     smslant_one_4},
	{smslant_two_0,     smslant_two_1,     smslant_two_2,     smslant_two_3,     smslant_two_4},
	{smslant_three_0,   smslant_three_1,   smslant_three_2,   smslant_three_3,   smslant_three_4},
	{smslant_four_0,    smslant_four_1,    smslant_four_2,    smslant_four_3,    smslant_four_4},
	{smslant_five_0,    smslant_five_1,    smslant_five_2,    smslant_five_3,    smslant_five_4},
	{smslant_six_0,     smslant_six_1,     smslant_six_2,     smslant_six_3,     smslant_six_4},
	{smslant_seven_0,   smslant_seven_1,   smslant_seven_2,   smslant_seven_3,   smslant_seven_4},
	{smslant_eight_0,   smslant_eight_1,   smslant_eight_2,   smslant_eight_3,   smslant_eight_4},
	{smslant_nine_0,    smslant_nine_1,    smslant_nine_2,    smslant_nine_3,    smslant_nine_4},
	{smslant_twodots_0, smslant_twodots_1, smslant_twodots_2, smslant_twodots_3, smslant_twodots_4}
};

int calculate_offset_smslant(int digit_1, int digit_2);
int offset_before_twodots_smslant(int num);
int offset_after_twodots_smslant(int num);
