
const char* const italic_zero_0 = "  __  \n";
const char* const italic_zero_1 = " /  ) \n";
const char* const italic_zero_2 = "(__/  \n";

const char* const italic_one_0 = "-/ \n";
const char* const italic_one_1 = "/  \n";

const char* const italic_two_0 = " _  \n";
const char* const italic_two_1 = " _) \n";
const char* const italic_two_2 = "/__ \n";

const char* const italic_three_0 = " _  \n";
const char* const italic_three_1 = " _) \n";
const char* const italic_three_2 = "__) \n";

const char* const italic_four_0 = "(_/ \n";
const char* const italic_four_1 = " /  \n";

const char* const italic_five_0 = " __ \n";
const char* const italic_five_1 = "/_  \n";
const char* const italic_five_2 = "__) \n";

const char* const italic_six_0 = "  __ \n";
const char* const italic_six_1 = " /_  \n";
const char* const italic_six_2 = "(__) \n";

const char* const italic_seven_0 = "___ \n";
const char* const italic_seven_1 = " _/ \n";
const char* const italic_seven_2 = "/   \n";

const char* const italic_eight_0 = "  _  \n";
const char* const italic_eight_1 = " (_) \n";
const char* const italic_eight_2 = "(__) \n";

const char* const italic_nine_0 = " __  \n";
const char* const italic_nine_1 = "(__) \n";
const char* const italic_nine_2 = "__/  \n";

const char* const italic_twodots_0 = ". \n";
const char* const italic_twodots_1 = ". \n";
const char* const italic_twodots_2 = "\n ";

const char* const font_italic[11][VEC_MAXSIZE] = 
{
    { italic_zero_0, italic_zero_1, italic_zero_2},
    { italic_one_0, italic_one_1},
    { italic_two_0, italic_two_1, italic_two_2},
    { italic_three_0, italic_three_1, italic_three_2},
    { italic_four_0, italic_four_1},
    { italic_five_0, italic_five_1, italic_five_2},
    { italic_six_0, italic_six_1, italic_six_2},
    { italic_seven_0, italic_seven_1, italic_seven_2},
    { italic_eight_0, italic_eight_1, italic_eight_2},
    { italic_nine_0, italic_nine_1, italic_nine_2},
    { italic_twodots_0, italic_twodots_1, italic_twodots_2}
}

int calculate_offset_italic(int digit_1, int digit_2);
int offset_before_twodots_italic(int num); 
int offset_after_twodots_italic(int num);
