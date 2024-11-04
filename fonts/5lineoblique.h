
const char* const lineoblique_zero_0 = "\n";
const char* const lineoblique_zero_1 = "     ___    \n";
const char* const lineoblique_zero_2 = "   //   ) ) \n";
const char* const lineoblique_zero_3 = "  //   / /  \n";
const char* const lineoblique_zero_4 = " //   / /   \n";
const char* const lineoblique_zero_5 = "((___/ /    \n";

const char* const lineoblique_one_0 = "\n";
const char* const lineoblique_one_1 = " /_  /    \n";
const char* const lineoblique_one_2 = " /_  /    \n";
const char* const lineoblique_one_3 = "  / /     \n";
const char* const lineoblique_one_4 = " / /      \n";
const char* const lineoblique_one_5 = "/ /       \n";

const char* const lineoblique_two_0 = "\n";
const char* const lineoblique_two_1 = "    ___    \n";
const char* const lineoblique_two_2 = "  //   ) ) \n";
const char* const lineoblique_two_3 = "   ___/ /  \n";
const char* const lineoblique_two_4 = " / ____/   \n";
const char* const lineoblique_two_5 = "/ /____    \n";

const char* const lineoblique_three_0 = "\n";
const char* const lineoblique_three_1 = "    ___    \n";
const char* const lineoblique_three_2 = "  //   ) ) \n";
const char* const lineoblique_three_3 = "   __ / /  \n";
const char* const lineoblique_three_4 = "      ) )  \n";
const char* const lineoblique_three_5 = "((___/ /   \n";

const char* const lineoblique_four_0 = "\n";
const char* const lineoblique_four_1 = " //___/ /  \n";
const char* const lineoblique_four_2 = " //___/ /  \n";
const char* const lineoblique_four_3 = "/____  /   \n";
const char* const lineoblique_four_4 = "    / /    \n";
const char* const lineoblique_four_5 = "   / /     \n";

const char* const lineoblique_five_0 = "\n";
const char* const lineoblique_five_1 = "     ____  \n";
const char* const lineoblique_five_2 = "   //      \n";
const char* const lineoblique_five_3 = "  //__     \n";
const char* const lineoblique_five_4 = "      ) )  \n";
const char* const lineoblique_five_5 = "((___/ /   \n";

const char* const lineoblique_six_0 = "\n";
const char* const lineoblique_six_1 = "     ____  \n";
const char* const lineoblique_six_2 = "   //      \n";
const char* const lineoblique_six_3 = "  //__     \n";
const char* const lineoblique_six_4 = " //   ) )  \n";
const char* const lineoblique_six_5 = "((___/ /   \n";

const char* const lineoblique_seven_0 = "\n";
const char* const lineoblique_seven_1 = "  ___     \n";
const char* const lineoblique_seven_2 = "//   / /  \n";
const char* const lineoblique_seven_3 = "    / /   \n";
const char* const lineoblique_seven_4 = "   / /    \n";
const char* const lineoblique_seven_5 = "  / /     \n";

const char* const lineoblique_eight_0 = "\n";
const char* const lineoblique_eight_1 = "     __    \n";
const char* const lineoblique_eight_2 = "   //  ) ) \n";
const char* const lineoblique_eight_3 = "  ((_ / /  \n";
const char* const lineoblique_eight_4 = " //  ) )   \n";
const char* const lineoblique_eight_5 = "((__/ /    \n";

const char* const lineoblique_nine_0 = "\n";
const char* const lineoblique_nine_1 = "   ___     \n";
const char* const lineoblique_nine_2 = " //   / /  \n";
const char* const lineoblique_nine_3 = "((___/ /   \n";
const char* const lineoblique_nine_4 = "    / /    \n";
const char* const lineoblique_nine_5 = "   / /     \n";

const char* const lineoblique_twodots_0 = "\n";
const char* const lineoblique_twodots_1 = "\n";
const char* const lineoblique_twodots_2 = " () \n";
const char* const lineoblique_twodots_3 = "\n ";
const char* const lineoblique_twodots_4 = "()  \n";
const char* const lineoblique_twodots_5 = "\n ";

const char* const font_5lineoblique[11][VEC_MAXSIZE] =
{
    {lineoblique_zero_0, lineoblique_zero_1, lineoblique_zero_2, lineoblique_zero_3, lineoblique_zero_4, lineoblique_zero_5},
    {lineoblique_one_0, lineoblique_one_1, lineoblique_one_2, lineoblique_one_3, lineoblique_one_4, lineoblique_one_5},
    {lineoblique_two_0, lineoblique_two_1, lineoblique_two_2, lineoblique_two_3, lineoblique_two_4, lineoblique_two_5},
    {lineoblique_three_0, lineoblique_three_1, lineoblique_three_2, lineoblique_three_3, lineoblique_three_4, lineoblique_three_5},
    {lineoblique_four_0, lineoblique_four_1, lineoblique_four_2, lineoblique_four_3, lineoblique_four_4, lineoblique_four_5},
    {lineoblique_five_0, lineoblique_five_1, lineoblique_five_2, lineoblique_five_3, lineoblique_five_4, lineoblique_five_5},
    {lineoblique_six_0, lineoblique_six_1, lineoblique_six_2, lineoblique_six_3, lineoblique_six_4, lineoblique_six_5},
    {lineoblique_seven_0, lineoblique_seven_1, lineoblique_seven_2, lineoblique_seven_3, lineoblique_seven_4, lineoblique_seven_5},
    {lineoblique_eight_0, lineoblique_eight_1, lineoblique_eight_2, lineoblique_eight_3, lineoblique_eight_4, lineoblique_eight_5},
    {lineoblique_nine_0, lineoblique_nine_1, lineoblique_nine_2, lineoblique_nine_3, lineoblique_nine_4, lineoblique_nine_5},
    {lineoblique_twodots_0, lineoblique_twodots_1, lineoblique_twodots_2, lineoblique_twodots_3, lineoblique_twodots_4, lineoblique_twodots_5}
};

int calculate_offset_5lineoblique(int digit_1, int digit_2);
int offset_before_twodots_5lineoblique(int num);
int offset_after_twodots_5lineoblique(int num);
