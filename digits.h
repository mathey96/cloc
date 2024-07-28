#include <notcurses/notcurses.h>
#include <ncpp/NotCurses.hh>
//  output taken from figlet


const char* zero = "";
const char* zero1 = "  ___\n";
const char* zero2 = " / _ \\ \n";
const char* zero3 = "| | | |\n";
const char* zero4 = "| |_| |\n";
const char* zero5 = " \\___/ \n";
const char* zero6 = "       \n";


const char* one  =  "";
const char* one1 =	" _ \n";
const char* one2 =	"/ |\n";
const char* one3 =	"| |\n";
const char* one4 =	"| |\n";
const char* one5 =	"|_|\n";
const char* one6 =	"   \n";

const char* two  =  "";
const char* two1 =	" ____  \n";
const char* two2 =	"|___ \\ \n";
const char* two3 =	"  __) |\n";
const char* two4 =	" / __/ \n";
const char* two5 =	"|_____|\n";
const char* two6 =	"       \n";

const char* three  = "";
const char* three1 = " _____ \n";
const char* three2 = "|___ / \n";
const char* three3 = "  |_ \\ \n";
const char* three4 = " ___) |\n";
const char* three5 = "|____/ \n";
const char* three6 = "       \n";

const char* four =  "";
const char* four1 =	" _  _   \n";
const char* four2 =	"| || |  \n";
const char* four3 =	"| || |_ \n";
const char* four4 =	"|__   _|\n";
const char* four5 =	"   |_|  \n";
const char* four6 =	"        \n";

const char* five ="";
const char* five1 =	" ____  \n";
const char* five2 =	"| ___| \n";
const char* five3 =	"|___ \\ \n";
const char* five4 =	" ___) |\n";
const char* five5 =	"|____/ \n";
const char* five6 =	"       \n";

const char* six  = "";
const char* six1 = "  __   \n";
const char* six2 = " / /_  \n";
const char* six3 = "| '_ \\ \n";
const char* six4 = "| (_) |\n";
const char* six5 = " \\___/ \n";
const char* six6 = "       \n";

const char* seven  = "";
const char* seven1 = " _____ \n";
const char* seven2 = "|___  |\n";
const char* seven3 = "   / / \n";
const char* seven4 = "  / /  \n";
const char* seven5 = " /_/   \n";
const char* seven6 = "       \n";

const char* eight  = "";
const char* eight1 = "  ___  \n";
const char* eight2 = " ( _ ) \n";
const char* eight3 = " / _ \\ \n";
const char* eight4 = "| (_) |\n";
const char* eight5 = " \\___/ \n";
const char* eight6 = "       \n";

const char* nine  = "";
const char* nine1 =	"  ___  \n";
const char* nine2 =	" / _ \\ \n";
const char* nine3 =	"| (_) |\n";
const char* nine4 =	" \\__, |\n";
const char* nine5 =	"   /_/ \n";
const char* nine6 =	"\n";

const char* two_dots  = " ";
const char* two_dots1 = "   _  \n";
const char* two_dots2 = "  |_|   \n";
const char* two_dots3 = "     \n";
const char* two_dots4 = "   _  \n";
const char* two_dots5 = "  |_|\n";
const char* two_dots6 = "     \n";


/* const char* two_dots  = ""; */
/* const char* two_dots1 = "    \n"; */
/* const char* two_dots2 = "  _ \n"; */
/* const char* two_dots3 = " |_|\n"; */
/* const char* two_dots4 = "    \n"; */
/* const char* two_dots5 = "  _  \n"; */
/* const char* two_dots6 = " |_| \n"; */

void print_1(struct ncplane* stdplane,int offset);
void print_2(struct ncplane* stdplane,int offset);
void print_3(struct ncplane* stdplane,int offset);
void print_4(struct ncplane* stdplane,int offset);
void print_5(struct ncplane* stdplane,int offset);
void print_6(struct ncplane* stdplane,int offset);
void print_7(struct ncplane* stdplane,int offset);
void print_8(struct ncplane* stdplane,int offset);
void print_9(struct ncplane* stdplane,int offset);
void two_dot(struct ncplane* stdplane,int offset);

void print_0(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, zero);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, zero1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, zero2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, zero3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, zero4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, zero5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, zero6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_1(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, one);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, one1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, one2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, one3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, one4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, one5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, one6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}

void print_2(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, two);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, two1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, two2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, two3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, two4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, two5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, two6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_3(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, three);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, three1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, three2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, three3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, three4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, three5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, three6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_4(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, four);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, four1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, four2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, four3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, four4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, four5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, four6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_5(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, five);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, five1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, five2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, five3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, five4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, five5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, five6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_6(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, six);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, six1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, six2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, six3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, six4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, six5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, six6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_7(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, seven);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, seven1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, seven2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, seven3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, seven4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, seven5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, seven6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}
void print_8(struct ncplane* stdplane,int offset){
    ncplane_putstr(stdplane, eight);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, eight1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, eight2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, eight3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, eight4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, eight5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, eight6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}

void print_9(struct ncplane* stdplane,int offset){
	ncplane_putstr(stdplane, nine);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, nine1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, nine2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, nine3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, nine4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, nine5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, nine6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}

void two_dot(struct ncplane* stdplane,int offset){
	ncplane_cursor_move_yx(stdplane, 0, 0);
	ncplane_putstr(stdplane, two_dots);
	ncplane_cursor_move_yx(stdplane, 1, offset);
    ncplane_putstr(stdplane, two_dots1);
	ncplane_cursor_move_yx(stdplane, 2, offset);
    ncplane_putstr(stdplane, two_dots2);
	ncplane_cursor_move_yx(stdplane, 3, offset);
    ncplane_putstr(stdplane, two_dots3);
	ncplane_cursor_move_yx(stdplane, 4, offset);
    ncplane_putstr(stdplane, two_dots4);
	ncplane_cursor_move_yx(stdplane, 5, offset);
    ncplane_putstr(stdplane, two_dots5);
	ncplane_cursor_move_yx(stdplane, 6, offset);
    ncplane_putstr(stdplane, two_dots6);
	ncplane_cursor_move_yx(stdplane, 7, offset);
	ncplane_cursor_move_yx(stdplane, 0, 0);
}




enum numbers {
	ZERO = 0,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TWO_DOTS,
};


typedef void (*digit) (struct ncplane* ,int );
const digit table[] =
{
	print_0,
	print_1,
	print_2,
	print_3,
	print_4,
	print_5,
	print_6,
	print_7,
	print_8,
	print_9,
	two_dot,
};
