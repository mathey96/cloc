const char* const mini_zero_0 = "\n";
const char* const mini_zero_1 = " _  \n";
const char* const mini_zero_2 = "/ \\ \n";
const char* const mini_zero_3 = "\\_/ \n";


const char* const mini_one_0 = "\n";
const char* const mini_one_1 = " \n";
const char* const mini_one_2 = "/| \n";
const char* const mini_one_3 = " | \n";

const char* const mini_two_0 = "\n";
const char* const mini_two_1 = "_  \n";
const char* const mini_two_2 = " ) \n";
const char* const mini_two_3 = "/_ \n";

const char* const mini_three_0 = "\n";
const char* const mini_three_1 = "_  \n";
const char* const mini_three_2 = "_) \n";
const char* const mini_three_3 = "_) \n";


const char* const mini_four_0 = "\n";
const char* const mini_four_1 = "\n";
const char* const mini_four_2 = "|_|_ \n";
const char* const mini_four_3 = "  |  \n";

const char* const mini_five_0 = "\n";
const char* const mini_five_1 = " _  \n";
const char* const mini_five_2 = "|_  \n";
const char* const mini_five_3 = " _) \n";

const char* const mini_six_0 = "\n";
const char* const mini_six_1 = " _  \n";
const char* const mini_six_2 = "|_  \n";
const char* const mini_six_3 = "|_) \n";

const char* const mini_seven_0 = "\n";;
const char* const mini_seven_1 = "__ \n";
const char* const mini_seven_2 = " / \n";
const char* const mini_seven_3 = "/  \n";

const char* const mini_eight_0 = "\n";
const char* const mini_eight_1 = " _  \n";
const char* const mini_eight_2 = "(_) \n";
const char* const mini_eight_3 = "(_) \n";


const char* const mini_nine_0 = "\n";
const char* const mini_nine_1 = " _  \n";
const char* const mini_nine_2 = "(_| \n";
const char* const mini_nine_3 = "  | \n";


const char* const mini_twodots_0  = "\n ";
const char* const mini_twodots_1  = "\n ";
const char* const mini_twodots_2  = "o \n";
const char* const mini_twodots_3  = "o \n";

const char* const font_mini[11][7] =
{
  {mini_zero_0,     mini_zero_1,     mini_zero_2,     mini_zero_3},
  {mini_one_0,      mini_one_1,      mini_one_2,      mini_one_3},
  {mini_two_0,      mini_two_1,      mini_two_2,      mini_two_3},
  {mini_three_0,    mini_three_1,    mini_three_2,    mini_three_3},
  {mini_four_0,     mini_four_1,     mini_four_2,     mini_four_3},
  {mini_five_0,     mini_five_1,     mini_five_2,     mini_five_3},
  {mini_six_0,      mini_six_1,      mini_six_2,      mini_six_3},
  {mini_seven_0,    mini_seven_1,    mini_seven_2,    mini_seven_3},
  {mini_eight_0,    mini_eight_1,    mini_eight_2,    mini_eight_3},
  {mini_nine_0,     mini_nine_1,     mini_nine_2,     mini_nine_3},
  {mini_twodots_0,  mini_twodots_1,  mini_twodots_2,  mini_twodots_3}
};

int calculate_offset_mini(int digit_1, int digit_2);
int offset_before_twodots_mini(int num);
int offset_after_twodots_mini(int num);
