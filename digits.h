#include <notcurses/notcurses.h>
#include <ncpp/NotCurses.hh>
#include "fonts/mono9.h"
#include "helpers.h"

#define NUM_OF_SYMBOLS 11
#define VEC_MAXSIZE 7

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

const char* two_dots  = " \n";
const char* two_dots1 = "  _\n";
const char* two_dots2 = " (_)\n";
const char* two_dots3 = "  _\n";
const char* two_dots4 = " (_)\n";
const char* two_dots5 = "	\n";
const char* two_dots6 = "	\n";


/* const char* two_dots  = ""; */
/* const char* two_dots1 = "    \n"; */
/* const char* two_dots2 = "  _ \n"; */
/* const char* two_dots3 = " |_|\n"; */
/* const char* two_dots4 = "    \n"; */
/* const char* two_dots5 = "  _  \n"; */
/* const char* two_dots6 = " |_| \n"; */

const char* const font_standard[NUM_OF_SYMBOLS][VEC_MAXSIZE] = {
	{zero, zero1, zero2, zero3, zero4, zero5, zero6},
	{one, one1, one2, one3, one4, one5, one6},
	{two, two1, two2, two3, two4, two5, two6},
	{three, three1, three2, three3, three4, three5, three6},
	{four, four1, four2, four3, four4, four5, four6},
	{five, five1, five2, five3, five4, five5, five6},
	{six, six1, six2, six3, six4, six5, six6},
	{seven, seven1, seven2, seven3, seven4, seven5, seven6},
	{eight, eight1, eight2, eight3, eight4, eight5, eight6},
	{nine, nine1, nine2, nine3, nine4, nine5, nine6},
	{two_dots, two_dots1, two_dots2, two_dots3, two_dots4, two_dots5, two_dots6}};


typedef struct font {
	const char* const (*pfont)[NUM_OF_SYMBOLS][VEC_MAXSIZE];
	int (*calculate_offset) (int,int);
	int (*offset_before_twodots) (int);
	int (*offset_after_twodots) (int);
	int size;
} font;

font font_standard_font = {&font_standard, &calculate_offset_standard, &offset_before_twodots_standard, &offset_after_twodots_standard, 7};
font font_mono9_font = {&font_mono9, &calculate_offset_mono9, &offset_before_twodots_mono9, &offset_after_twodots_mono9, 6};


font fonts[3] = {font_standard_font, font_mono9_font};

void print_9(struct ncplane* stdplane, int offset, int y_offset, const char* const array[]);
void two_dot(struct ncplane* stdplane, int offset, int y_offset, const char* const array[]);


void print_0(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[0][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

void print_1(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[1][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

void print_2(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[2][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}
void print_3(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[3][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}
void print_4(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[4][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}
void print_5(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[5][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}
void print_6(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[6][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}
void print_7(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[7][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

void print_8(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[8][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

void print_9(struct ncplane* stdplane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[9][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

void two_dot(struct ncplane* stdplane, int offset, int y_offset, font current_font){
	for (int i = 0; i < current_font.size; i++ ){
    ncplane_putstr(stdplane, (*current_font.pfont)[10][i]);
	ncplane_cursor_move_yx(stdplane, 1 + i + y_offset, offset);
	}
}

typedef void (*digit) (struct ncplane* stdplane, int offset, int y_offset, font current_font);

const digit table[] =  // some dynamic dispatch here, who needs c++ anyway?
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
