#include <notcurses/notcurses.h>
#include <ncpp/NotCurses.hh>
#include "fonts/mono9.h"
#include "fonts/mini.h"
#include "fonts/standard.h"
#include "fonts/lean.h"
#include "fonts/mono12.h"
#include "fonts/smmono12.h"
#include "fonts/smscript.h"
#include "fonts/smshadow.h"
#include "fonts/smslant.h"

#include "helpers.h"

#define NO_OFFSET 0

typedef struct font {
	const char* const (*pfont)[NUM_OF_SYMBOLS][VEC_MAXSIZE];
	int (*calculate_offset) (int,int);
	int (*offset_before_twodots) (int);
	int (*offset_after_twodots) (int);
	int size;
	int correct_offset;
} font;

font font_standard_font = {&font_standard, &calculate_offset_standard, &offset_before_twodots_standard, &offset_after_twodots_standard, 7, NO_OFFSET};
font font_mono9_font	= {&font_mono9, &calculate_offset_mono9, &offset_before_twodots_mono9, &offset_after_twodots_mono9, 6, NO_OFFSET};
font font_mini_font		= {&font_mini, &calculate_offset_mini, &offset_before_twodots_mini, &offset_after_twodots_mini, 4, 15};
font font_lean_font  =    {&font_lean, &calculate_offset_lean, &offset_before_twodots_lean, &offset_after_twodots_lean, 6, -5};
font font_mono12_font =   {&font_mono12, &calculate_offset_mono12, &offset_before_twodots_mono12, &offset_after_twodots_mono12, 7, -10};
font font_smmono12_font = {&font_smmono12, &calculate_offset_smmono12, &offset_before_twodots_smmono12, &offset_after_twodots_smmono12, 7, 0};
font font_smscript_font = {&font_smscript, &calculate_offset_smscript, &offset_before_twodots_smscript, &offset_after_twodots_smscript, 5, 5};
font font_smshadow_font = {&font_smshadow, &calculate_offset_smshadow, &offset_before_twodots_smshadow, &offset_after_twodots_smshadow, 4, 5};
font font_smslant_font =  {&font_smslant, &calculate_offset_smslant, &offset_before_twodots_smslant, &offset_after_twodots_smslant, 5, 5};

font fonts[9] =
{font_standard_font,  font_mono9_font,  font_mono12_font, font_smmono12_font, font_lean_font, font_mini_font, font_smscript_font, font_smshadow_font, font_smslant_font};

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
