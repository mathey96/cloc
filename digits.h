#include <notcurses/notcurses.h>
#include "fonts/mono9.h"
#include "fonts/mini.h"
#include "fonts/standard.h"
#include "fonts/lean.h"
#include "fonts/mono12.h"
#include "fonts/smmono12.h"
#include "fonts/smscript.h"
#include "fonts/smshadow.h"
#include "fonts/smslant.h"
#include "fonts/eftitalic.h"
#include "fonts/larry3d.h"
#include "fonts/graffiti.h"
#include "fonts/madrid.h"
#include "fonts/5lineoblique.h"
#include "fonts/acrobatic.h"
#include "fonts/avatar.h"
#include "fonts/chunky.h"
#include "fonts/cricket.h"
#include "fonts/cursive.h"
#include "fonts/doom.h"
#include "fonts/drpepper.h"
#include "fonts/eftifont.h"
#include "fonts/fourtops.h"
#include "fonts/kban.h"
#include "fonts/serifcap.h"
#include "fonts/short.h"
#include "fonts/slscript.h"
#include "fonts/twopoint.h"
#include "fonts/usaflag.h"
#include "fonts/wavy.h"
#include "fonts/straight.h"
#include "fonts/weird.h"
#include "fonts/thin.h"
#include "fonts/gothic.h"
#include "offset.h"

#define STANDARD_FONT_WIDTH      50
#define MONO9_FONT_WIDTH         53
#define MINI_FONT_WIDTH          24
#define LEAN_FONT_WIDTH          67
#define MONO12_FONT_WIDTH        73
#define SMMONO12_FONT_WIDTH      53
#define SMSCRIPT_FONT_WIDTH      42
#define SMSHADOW_FONT_WIDTH      40
#define SMSLANT_FONT_WIDTH       52
#define EFTITALIC_FONT_WIDTH     40
#define LARRY3D_FONT_WIDTH       74
#define GRAFFITI_FONT_WIDTH      64
#define MADRID_FONT_WIDTH        28
#define LINEOBLIQUE_FONT_WIDTH   65
#define ACROBATIC_FONT_WIDTH     94
#define AVATAR_FONT_WIDTH        50
#define CHUNKY_FONT_WIDTH        62
#define CRICKET_FONT_WIDTH       72
#define CURSIVE_FONT_WIDTH       42
#define DOOM_FONT_WIDTH          58
#define DRPEPPER_FONT_WIDTH      44
#define EFTIFONT_FONT_WIDTH      38
#define FOURTOPS_FONT_WIDTH      38
#define KBAN_FONT_WIDTH          47
#define SERIFCAP_FONT_WIDTH      42
#define SHORT_FONT_WIDTH         28
#define SLSCRIPT_FONT_WIDTH      40
#define TWOPOINT_FONT_WIDTH      26
#define USAFLAG_FONT_WIDTH       68
#define WAVY_FONT_WIDTH          30
#define STRAIGHT_FONT_WIDTH      32
#define WEIRD_FONT_WIDTH         40
#define THIN_FONT_WIDTH          38
#define GOTHIC_FONT_WIDTH        40

#if defined(DEBUG_MODE) || defined(DEBUG_OFFSET)
typedef struct font {
	const char* const font_name;
	const char* const (*pfont)[NUM_OF_SYMBOLS][VEC_MAXSIZE];
	int (*calculate_offset) (int,int);
	int (*offset_before_twodots) (int);
	int (*offset_after_twodots) (int);
	const int font_height;
	const int font_width;  // these values are magic constants - they are obtained by visually inspecting every width of every font in the debug executable, using font_width variable.
} font;

// compile fonts without font_name field, let this field be only in the debug build
// make sure, while testing new fonts, to keep values of correct_offset of both DEBUG_MODE build and release build the same.

const font font_standard_font       = {"standard"       ,&font_standard        ,&calculate_offset_standard        ,&offset_before_twodots_standard       ,&offset_after_twodots_standard        ,7  ,STANDARD_FONT_WIDTH};
const font font_mono9_font          = {"mono9"          ,&font_mono9           ,&calculate_offset_mono9           ,&offset_before_twodots_mono9          ,&offset_after_twodots_mono9           ,6  ,MONO9_FONT_WIDTH};
const font font_mini_font           = {"mini"           ,&font_mini            ,&calculate_offset_mini            ,&offset_before_twodots_mini           ,&offset_after_twodots_mini            ,4  ,MINI_FONT_WIDTH};
const font font_lean_font           = {"lean"           ,&font_lean            ,&calculate_offset_lean            ,&offset_before_twodots_lean           ,&offset_after_twodots_lean            ,6  ,LEAN_FONT_WIDTH};
const font font_mono12_font         = {"mono12"         ,&font_mono12          ,&calculate_offset_mono12          ,&offset_before_twodots_mono12         ,&offset_after_twodots_mono12          ,8  ,MONO12_FONT_WIDTH};
const font font_smmono12_font       = {"smmono12"       ,&font_smmono12        ,&calculate_offset_smmono12        ,&offset_before_twodots_smmono12       ,&offset_after_twodots_smmono12        ,8  ,SMMONO12_FONT_WIDTH};
const font font_smscript_font       = {"smscript"       ,&font_smscript        ,&calculate_offset_smscript        ,&offset_before_twodots_smscript       ,&offset_after_twodots_smscript        ,5  ,SMSCRIPT_FONT_WIDTH};
const font font_smshadow_font       = {"smshadow"       ,&font_smshadow        ,&calculate_offset_smshadow        ,&offset_before_twodots_smshadow       ,&offset_after_twodots_smshadow        ,4  ,SMSHADOW_FONT_WIDTH};
const font font_smslant_font        = {"smslant"        ,&font_smslant         ,&calculate_offset_smslant         ,&offset_before_twodots_smslant        ,&offset_after_twodots_smslant         ,5  ,SMSLANT_FONT_WIDTH};
const font font_eftitalic_font      = {"eftitalic"      ,&font_eftitalic       ,&calculate_offset_eftitalic       ,&offset_before_twodots_eftitalic      ,&offset_after_twodots_eftitalic       ,5  ,EFTITALIC_FONT_WIDTH};
const font font_larry3d_font        = {"larry3d"        ,&font_larry3d         ,&calculate_offset_larry3d         ,&offset_before_twodots_larry3d        ,&offset_after_twodots_larry3d         ,8  ,LARRY3D_FONT_WIDTH};
const font font_graffiti_font       = {"graffiti"       ,&font_graffiti        ,&calculate_offset_graffiti        ,&offset_before_twodots_graffiti       ,&offset_after_twodots_graffiti        ,7  ,GRAFFITI_FONT_WIDTH};
const font font_madrid_font         = {"madrid"         ,&font_madrid          ,&calculate_offset_madrid          ,&offset_before_twodots_madrid         ,&offset_after_twodots_madrid          ,4  ,MADRID_FONT_WIDTH};
const font font_5lineoblique_font   = {"5lineoblique"   ,&font_5lineoblique    ,&calculate_offset_5lineoblique    ,&offset_before_twodots_5lineoblique   ,&offset_after_twodots_5lineoblique    ,6  ,LINEOBLIQUE_FONT_WIDTH};
const font font_acrobatic_font      = {"acrobatic"      ,&font_acrobatic       ,&calculate_offset_acrobatic       ,&offset_before_twodots_acrobatic      ,&offset_after_twodots_acrobatic       ,11 ,ACROBATIC_FONT_WIDTH};
const font font_avatar_font         = {"avatar"         ,&font_avatar          ,&calculate_offset_avatar          ,&offset_before_twodots_avatar         ,&offset_after_twodots_avatar          ,5  ,AVATAR_FONT_WIDTH};
const font font_chunky_font         = {"chunky"         ,&font_chunky          ,&calculate_offset_chunky          ,&offset_before_twodots_chunky         ,&offset_after_twodots_chunky          ,4  ,CHUNKY_FONT_WIDTH};
const font font_cricket_font        = {"cricket"        ,&font_cricket         ,&calculate_offset_cricket         ,&offset_before_twodots_cricket        ,&offset_after_twodots_cricket         ,7  ,CRICKET_FONT_WIDTH};
const font font_cursive_font        = {"cursive"        ,&font_cursive         ,&calculate_offset_cursive         ,&offset_before_twodots_cursive        ,&offset_after_twodots_cursive         ,4  ,CURSIVE_FONT_WIDTH};
const font font_doom_font           = {"doom"           ,&font_doom            ,&calculate_offset_doom            ,&offset_before_twodots_doom           ,&offset_after_twodots_doom            ,6  ,DOOM_FONT_WIDTH};
const font font_drpepper_font       = {"drpepper"       ,&font_drpepper        ,&calculate_offset_drpepper        ,&offset_before_twodots_drpepper       ,&offset_after_twodots_drpepper        ,4  ,DRPEPPER_FONT_WIDTH};
const font font_eftifont_font       = {"eftifont"       ,&font_eftifont        ,&calculate_offset_eftifont        ,&offset_before_twodots_eftifont       ,&offset_after_twodots_eftifont        ,4  ,EFTIFONT_FONT_WIDTH};
const font font_fourtops_font       = {"fourtops"       ,&font_fourtops        ,&calculate_offset_fourtops        ,&offset_before_twodots_fourtops       ,&offset_after_twodots_fourtops        ,3  ,FOURTOPS_FONT_WIDTH};
const font font_kban_font           = {"kban"           ,&font_kban            ,&calculate_offset_kban            ,&offset_before_twodots_kban           ,&offset_after_twodots_kban            ,7  ,KBAN_FONT_WIDTH};
const font font_serifcap_font       = {"serifcap"       ,&font_serifcap        ,&calculate_offset_serifcap        ,&offset_before_twodots_serifcap       ,&offset_after_twodots_serifcap        ,4  ,SERIFCAP_FONT_WIDTH};
const font font_short_font          = {"short"          ,&font_short           ,&calculate_offset_short           ,&offset_before_twodots_short          ,&offset_after_twodots_short           ,2  ,SHORT_FONT_WIDTH};
const font font_slscript_font       = {"slscript"       ,&font_slscript        ,&calculate_offset_slscript        ,&offset_before_twodots_slscript       ,&offset_after_twodots_slscript        ,4  ,SLSCRIPT_FONT_WIDTH};
const font font_twopoint_font       = {"twopoint"       ,&font_twopoint        ,&calculate_offset_twopoint        ,&offset_before_twodots_twopoint       ,&offset_after_twodots_twopoint        ,2  ,TWOPOINT_FONT_WIDTH};
const font font_usaflag_font        = {"usaflag"        ,&font_usaflag         ,&calculate_offset_usaflag         ,&offset_before_twodots_usaflag        ,&offset_after_twodots_usaflag         ,5  ,USAFLAG_FONT_WIDTH};
const font font_wavy_font           = {"wavy"           ,&font_wavy            ,&calculate_offset_wavy            ,&offset_before_twodots_wavy           ,&offset_after_twodots_wavy            ,3  ,WAVY_FONT_WIDTH};
const font font_straight_font       = {"straight"       ,&font_straight        ,&calculate_offset_straight        ,&offset_before_twodots_straight       ,&offset_after_twodots_straight        ,3  ,STRAIGHT_FONT_WIDTH};
const font font_weird_font          = {"weird"          ,&font_weird           ,&calculate_offset_weird           ,&offset_before_twodots_weird          ,&offset_after_twodots_weird           ,5  ,WEIRD_FONT_WIDTH};
const font font_thin_font           = {"thin"           ,&font_thin            ,&calculate_offset_thin            ,&offset_before_twodots_thin           ,&offset_after_twodots_thin            ,4  ,THIN_FONT_WIDTH};
const font font_gothic_font         = {"gothic"         ,&font_gothic          ,&calculate_offset_gothic          ,&offset_before_twodots_gothic         ,&offset_after_twodots_gothic          ,7  ,GOTHIC_FONT_WIDTH};

#else

typedef struct font {
	const char* const (*pfont)[NUM_OF_SYMBOLS][VEC_MAXSIZE];
	int (*calculate_offset) (int,int);
	int (*offset_before_twodots) (int);
	int (*offset_after_twodots) (int);
	const int font_height;
	const int font_width;
} font;

const font font_standard_font       = {&font_standard       ,&calculate_offset_standard        ,&offset_before_twodots_standard       ,&offset_after_twodots_standard        ,7  ,STANDARD_FONT_WIDTH};
const font font_mono9_font          = {&font_mono9          ,&calculate_offset_mono9           ,&offset_before_twodots_mono9          ,&offset_after_twodots_mono9           ,6  ,MONO9_FONT_WIDTH};
const font font_mini_font           = {&font_mini           ,&calculate_offset_mini            ,&offset_before_twodots_mini           ,&offset_after_twodots_mini            ,4  ,MINI_FONT_WIDTH};
const font font_lean_font           = {&font_lean           ,&calculate_offset_lean            ,&offset_before_twodots_lean           ,&offset_after_twodots_lean            ,6  ,LEAN_FONT_WIDTH};
const font font_mono12_font         = {&font_mono12         ,&calculate_offset_mono12          ,&offset_before_twodots_mono12         ,&offset_after_twodots_mono12          ,8  ,MONO12_FONT_WIDTH};
const font font_smmono12_font       = {&font_smmono12       ,&calculate_offset_smmono12        ,&offset_before_twodots_smmono12       ,&offset_after_twodots_smmono12        ,8  ,SMMONO12_FONT_WIDTH};
const font font_smscript_font       = {&font_smscript       ,&calculate_offset_smscript        ,&offset_before_twodots_smscript       ,&offset_after_twodots_smscript        ,5  ,SMSCRIPT_FONT_WIDTH};
const font font_smshadow_font       = {&font_smshadow       ,&calculate_offset_smshadow        ,&offset_before_twodots_smshadow       ,&offset_after_twodots_smshadow        ,4  ,SMSHADOW_FONT_WIDTH};
const font font_smslant_font        = {&font_smslant        ,&calculate_offset_smslant         ,&offset_before_twodots_smslant        ,&offset_after_twodots_smslant         ,5  ,SMSLANT_FONT_WIDTH};
const font font_eftitalic_font      = {&font_eftitalic      ,&calculate_offset_eftitalic       ,&offset_before_twodots_eftitalic      ,&offset_after_twodots_eftitalic       ,5  ,EFTITALIC_FONT_WIDTH};
const font font_larry3d_font        = {&font_larry3d        ,&calculate_offset_larry3d         ,&offset_before_twodots_larry3d        ,&offset_after_twodots_larry3d         ,8  ,LARRY3D_FONT_WIDTH};
const font font_graffiti_font       = {&font_graffiti       ,&calculate_offset_graffiti        ,&offset_before_twodots_graffiti       ,&offset_after_twodots_graffiti        ,7  ,GRAFFITI_FONT_WIDTH};
const font font_madrid_font         = {&font_madrid         ,&calculate_offset_madrid          ,&offset_before_twodots_madrid         ,&offset_after_twodots_madrid          ,4  ,MADRID_FONT_WIDTH};
const font font_5lineoblique_font   = {&font_5lineoblique   ,&calculate_offset_5lineoblique    ,&offset_before_twodots_5lineoblique   ,&offset_after_twodots_5lineoblique    ,6  ,LINEOBLIQUE_FONT_WIDTH};
const font font_acrobatic_font      = {&font_acrobatic      ,&calculate_offset_acrobatic       ,&offset_before_twodots_acrobatic      ,&offset_after_twodots_acrobatic       ,10 ,ACROBATIC_FONT_WIDTH};
const font font_avatar_font         = {&font_avatar         ,&calculate_offset_avatar          ,&offset_before_twodots_avatar         ,&offset_after_twodots_avatar          ,5  ,AVATAR_FONT_WIDTH};
const font font_chunky_font         = {&font_chunky         ,&calculate_offset_chunky          ,&offset_before_twodots_chunky         ,&offset_after_twodots_chunky          ,4  ,CHUNKY_FONT_WIDTH};
const font font_cricket_font        = {&font_cricket        ,&calculate_offset_cricket         ,&offset_before_twodots_cricket        ,&offset_after_twodots_cricket         ,7  ,CRICKET_FONT_WIDTH};
const font font_cursive_font        = {&font_cursive        ,&calculate_offset_cursive         ,&offset_before_twodots_cursive        ,&offset_after_twodots_cursive         ,4  ,CURSIVE_FONT_WIDTH};
const font font_doom_font           = {&font_doom           ,&calculate_offset_doom            ,&offset_before_twodots_doom           ,&offset_after_twodots_doom            ,6  ,DOOM_FONT_WIDTH};
const font font_drpepper_font       = {&font_drpepper       ,&calculate_offset_drpepper        ,&offset_before_twodots_drpepper       ,&offset_after_twodots_drpepper        ,4  ,DRPEPPER_FONT_WIDTH};
const font font_eftifont_font       = {&font_eftifont       ,&calculate_offset_eftifont        ,&offset_before_twodots_eftifont       ,&offset_after_twodots_eftifont        ,4  ,EFTIFONT_FONT_WIDTH};
const font font_fourtops_font       = {&font_fourtops       ,&calculate_offset_fourtops        ,&offset_before_twodots_fourtops       ,&offset_after_twodots_fourtops        ,3  ,FOURTOPS_FONT_WIDTH};
const font font_kban_font           = {&font_kban           ,&calculate_offset_kban            ,&offset_before_twodots_kban           ,&offset_after_twodots_kban            ,7  ,KBAN_FONT_WIDTH};
const font font_serifcap_font       = {&font_serifcap       ,&calculate_offset_serifcap        ,&offset_before_twodots_serifcap       ,&offset_after_twodots_serifcap        ,4  ,SERIFCAP_FONT_WIDTH};
const font font_short_font          = {&font_short          ,&calculate_offset_short           ,&offset_before_twodots_short          ,&offset_after_twodots_short           ,2  ,SHORT_FONT_WIDTH};
const font font_slscript_font       = {&font_slscript       ,&calculate_offset_slscript        ,&offset_before_twodots_slscript       ,&offset_after_twodots_slscript        ,4  ,SLSCRIPT_FONT_WIDTH};
const font font_twopoint_font       = {&font_twopoint       ,&calculate_offset_twopoint        ,&offset_before_twodots_twopoint       ,&offset_after_twodots_twopoint        ,2  ,TWOPOINT_FONT_WIDTH};
const font font_usaflag_font        = {&font_usaflag        ,&calculate_offset_usaflag         ,&offset_before_twodots_usaflag        ,&offset_after_twodots_usaflag         ,5  ,USAFLAG_FONT_WIDTH};
const font font_wavy_font           = {&font_wavy           ,&calculate_offset_wavy            ,&offset_before_twodots_wavy           ,&offset_after_twodots_wavy            ,3  ,WAVY_FONT_WIDTH};
const font font_straight_font       = {&font_straight       ,&calculate_offset_straight        ,&offset_before_twodots_straight       ,&offset_after_twodots_straight        ,3  ,STRAIGHT_FONT_WIDTH};
const font font_weird_font          = {&font_weird          ,&calculate_offset_weird           ,&offset_before_twodots_weird          ,&offset_after_twodots_weird           ,5  ,WEIRD_FONT_WIDTH};
const font font_thin_font           = {&font_thin           ,&calculate_offset_thin            ,&offset_before_twodots_thin           ,&offset_after_twodots_thin            ,4  ,THIN_FONT_WIDTH};
const font font_gothic_font         = {&font_gothic         ,&calculate_offset_gothic          ,&offset_before_twodots_gothic         ,&offset_after_twodots_gothic          ,7  ,GOTHIC_FONT_WIDTH};


#endif

font fonts[] =
{font_standard_font ,font_mono9_font		,font_mini_font         ,font_lean_font			,font_mono12_font   ,font_smmono12_font	,
 font_smscript_font ,font_smshadow_font		,font_smslant_font      ,font_eftitalic_font	,font_larry3d_font  ,font_graffiti_font	,
 font_madrid_font   ,font_5lineoblique_font ,font_acrobatic_font    ,font_avatar_font       ,font_chunky_font   ,font_cricket_font  ,
 font_cursive_font  ,font_doom_font         ,font_drpepper_font     ,font_eftifont_font     ,font_fourtops_font ,font_kban_font     ,
 font_serifcap_font ,font_short_font        ,font_slscript_font     ,font_twopoint_font     ,font_usaflag_font  ,font_wavy_font     ,
 font_straight_font ,font_weird_font        ,font_thin_font         ,font_gothic_font};

void print_0(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[0][i]);
	}
}

void print_1(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[1][i]);
	}
}

void print_2(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[2][i]);
	}
}
void print_3(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[3][i]);
	}
}
void print_4(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[4][i]);
	}
}
void print_5(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[5][i]);
	}
}
void print_6(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[6][i]);
	}
}
void print_7(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[7][i]);
	}
}

void print_8(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[8][i]);
	}
}

void print_9(struct ncplane* plane, int offset, int y_offset, font current_font){

	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[9][i]);
	}
}

void two_dot(struct ncplane* plane, int offset, int y_offset, font current_font){
	for (int i = 0; i < current_font.font_height; i++ ){
    ncplane_putstr_yx(plane,1+i+y_offset, offset, (*current_font.pfont)[10][i]);
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
