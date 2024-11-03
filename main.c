#include <time.h>
#include "digits.h"
#include <pthread.h>
#include "stopwatch.h"
#include <unistd.h>

static int current_ms = 0;
static int current_sec = 0;
static int current_min = 0;

size_t color_index = 0;
unsigned colors[] = {0x000000, 0xffffff, 0x282828, 0xcc241d, 0x98971a, 0xd79921, 0x458688, 0xb16286, 0x89d6a,
					 0xe0b0b0, 0xa0ffff, 0xe0a0a0, 0x0a0a0a, 0x11ffff, 0x80d0ff, 0xbde8f6, 0x40d0d0, 0x40d040,
					 0xd4af37, 0xf0f0a0, 0xd78700, 0x40f040, 0xcccbbb, 0xbbbbbb, 0x014dd3, 0x00dddd, 0x00bcaa,
					 0xff5349, 0xf2f2f2, 0xffd700, 0x44488f, 0x884448, 0x222222, 0xff00ff, 0x00ff00, 0x808080,
					 0x444444, 0x888888, 0x4f4f4f, 0xf4f4f4, 0xfcfcfc, 0x00ffb0, 0x00b0b0, 0xe0f0ff, 0xff6a00};

#define TWO_DOTS 10

#define MAX_FONT_NUM sizeof(fonts) / sizeof(fonts[0]) - 1
#define SIZEOFARRAY(array) (sizeof(array) / sizeof(array[0]) - 1)


#define OFFSET_DEBUG(NUM, FONTNUM, OFFSET0, OFFSET1, OFFSET2, OFFSET3, OFFSET4, OFFSET5, OFFSET6, OFFSET7, OFFSET8, OFFSET9) do{ \
		table[(NUM)](stdplane, 0 + x_center, y_center - 10, fonts[(FONTNUM)]);	\
		table[0](stdplane, 0 + (OFFSET0) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(NUM)](stdplane, 30 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[1](stdplane, 30 + (OFFSET1) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(NUM)](stdplane, 50 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[2](stdplane, 50 + (OFFSET2) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 70 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[3] (stdplane, 70 + (OFFSET3) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 0 + x_center, y_center , fonts[(FONTNUM)]);\
		table[4] (stdplane, 0 + (OFFSET4) + x_center, y_center, fonts[(FONTNUM)]);	\
\
		table[(NUM)](stdplane, 30 + x_center, y_center , fonts[(FONTNUM)]);\
		table[5] (stdplane, 30 + (OFFSET5) + x_center, y_center , fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 50 + x_center, y_center, fonts[(FONTNUM)]);\
		table[6] (stdplane, 50 + (OFFSET6) + x_center, y_center, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 0 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[7] (stdplane, 0 + (OFFSET7) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 30 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[8] (stdplane, 30 + (OFFSET8) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 50 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[9] (stdplane, 50 + (OFFSET9) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
}while(0) \


#define OFFSET_BEFORE_TWODOTS(FONTNUM, OFFSET0, OFFSET1, OFFSET2, OFFSET3, OFFSET4, OFFSET5, OFFSET6, OFFSET7, OFFSET8, OFFSET9) do{ \
		table[(0)](stdplane, 0 + x_center, y_center - 10, fonts[(FONTNUM)]);	\
		table[TWO_DOTS](stdplane, 0 + (OFFSET0) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(1)](stdplane, 30 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS](stdplane, 30 + (OFFSET1) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(2)](stdplane, 50 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS](stdplane, 50 + (OFFSET2) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(3)](stdplane, 70 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 70 + (OFFSET3) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(4)](stdplane, 0 + x_center, y_center , fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 0 + (OFFSET4) + x_center, y_center, fonts[(FONTNUM)]);	\
\
		table[(5)](stdplane, 30 + x_center, y_center , fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 30 + (OFFSET5) + x_center, y_center , fonts[(FONTNUM)]); \
\
		table[(6)](stdplane, 50 + x_center, y_center, fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 50 + (OFFSET6) + x_center, y_center, fonts[(FONTNUM)]); \
\
		table[(7)](stdplane, + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 0 + (OFFSET7) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(8)](stdplane, 30 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 30 + (OFFSET8) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(9)](stdplane, 50 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[TWO_DOTS] (stdplane, 50 + (OFFSET9) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
}while(0) \



#if defined(DEBUG_MODE) || defined(DEBUG_OFFSET)
#define SCREENSIZE do{							              \
	 char xchar[100] ;							              \
	 char ychar[100] ;							              \
	 char color[100] ;										  \
	 char colorindex[100] ;									  \
	 snprintf(xchar, 100, "%d", xstd);						  \
	 snprintf(ychar, 100, "%d", ystd);						  \
	 snprintf(color, 100, "%x", colors[color_index]);		  \
	 snprintf(colorindex, 100, "%ld", color_index);			  \
	 ncplane_cursor_move_yx(stdplane,0, 0);					  \
	 ncplane_putstr(stdplane,"X:");							  \
	 ncplane_putstr(stdplane,xchar);						  \
	 ncplane_putstr(stdplane,"Y:");						      \
	 ncplane_putstr(stdplane,ychar);						  \
	 ncplane_cursor_move_yx(stdplane, 1, 0);				  \
	 ncplane_putstr(stdplane,"current font is: ");			  \
	 ncplane_putstr(stdplane,fonts[font_number].font_name);	  \
	 ncplane_cursor_move_yx(stdplane, 2, 0);				  \
	 ncplane_putstr(stdplane,"current color is: 0x");		  \
	 ncplane_putstr(stdplane, color);						  \
	 ncplane_cursor_move_yx(stdplane, 3, 0);				  \
	 ncplane_putstr(stdplane,"current color index is: ");	  \
	 ncplane_putstr(stdplane,colorindex);			          \
	 }while(0)
#endif

#ifdef DEBUG_OFFSET
int dig_0 = 5, dig_1 = 5, dig_2 = 5, dig_3 = 5, dig_4 = 5,
dig_5 = 5, dig_6 = 5, dig_7 = 5, dig_8 = 5, dig_9 = 5; // let default offset in DEBUG_OFFSET build be 5

	 char dig0[100];
	 char dig1[100];
	 char dig2[100];
	 char dig3[100];
	 char dig4[100];
	 char dig5[100];
	 char dig6[100];
	 char dig7[100];
	 char dig8[100];
	 char dig9[100];
#define DEBUG_OFFSET_PRINT do{                                \
	 snprintf(dig0, 100, "%d", dig_0);						  \
	 snprintf(dig1, 100, "%d", dig_1);						  \
	 snprintf(dig2, 100, "%d", dig_2);						  \
	 snprintf(dig3, 100, "%d", dig_3);						  \
	 snprintf(dig4, 100, "%d", dig_4);						  \
	 snprintf(dig5, 100, "%d", dig_5);						  \
	 snprintf(dig6, 100, "%d", dig_6);				          \
	 snprintf(dig7, 100, "%d", dig_7);				          \
	 snprintf(dig8, 100, "%d", dig_8);				          \
	 snprintf(dig9, 100, "%d", dig_9);				          \
	 ncplane_cursor_move_yx(stdplane, 0, 0);		          \
	 ncplane_putstr(stdplane,"0-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig0);					          \
	 ncplane_cursor_move_yx(stdplane, 1, 0);		          \
	 ncplane_putstr(stdplane,"1-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig1);					          \
	 ncplane_cursor_move_yx(stdplane, 2, 0);		          \
	 ncplane_putstr(stdplane,"2-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig2);					          \
	 ncplane_cursor_move_yx(stdplane, 3, 0);		          \
	 ncplane_putstr(stdplane,"3-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig3);					          \
	 ncplane_cursor_move_yx(stdplane, 4, 0);		          \
	 ncplane_putstr(stdplane,"4-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig4);					          \
	 ncplane_cursor_move_yx(stdplane, 5, 0);		          \
	 ncplane_putstr(stdplane,"5-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig5);					          \
	 ncplane_cursor_move_yx(stdplane, 6, 0);		          \
	 ncplane_putstr(stdplane,"6-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig6);					          \
	 ncplane_cursor_move_yx(stdplane, 7, 0);		          \
	 ncplane_putstr(stdplane,"7-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig7);					          \
	 ncplane_cursor_move_yx(stdplane, 8, 0);		          \
	 ncplane_putstr(stdplane,"8-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig8);					          \
	 ncplane_cursor_move_yx(stdplane, 9, 0);		          \
	 ncplane_putstr(stdplane,"9-digit offset is:");	          \
	 ncplane_putstr(stdplane,dig9);					          \
	 ncplane_cursor_move_yx(stdplane, 10, 0);		          \
	 ncplane_putstr(stdplane,"current font is: ");			  \
	 ncplane_putstr(stdplane,fonts[font_number].font_name);	  \
	 } while(0)
#endif



static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex_tick = PTHREAD_MUTEX_INITIALIZER;

static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

bool tick_thread_done = true;
bool tick_thread_reset = false;
bool tick_thread_started = false;
bool paused = false;

static pthread_t thread_id_input;
static pthread_t thread_id_tick;
static pthread_t animation;

int x_center = 0;
int y_center = 0;
unsigned xstd,ystd;

struct ncplane* stdplane;
struct ncplane* clockplane;
struct notcurses* nc;

long long current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long) ( (tv.tv_usec / 1000));
}

int current_ms_twodigits = 0;
int tick_counter = 0;

void* current_tick (void* ){
	long long tick = 0;
	while(1){
		if(tick != current_time_millis() ){
			pthread_mutex_lock(&mutex_tick);
			tick = current_time_millis();
			if (paused == false){
				current_ms++;
				current_ms_twodigits = current_ms / 10;
				tick_counter++;
			if(current_ms == 999){
				current_ms = 0;
				current_ms_twodigits = 0;
			}
			if( tick_counter == 1000){
				current_sec++;
				tick_counter = 0;
			}
			if(current_sec == 60){
				current_ms = 0;
				current_ms_twodigits = 0;
				current_sec = 0;
				current_min++;
			}
			}

			pthread_cond_signal(&cond);  // Signal the condition variable
			pthread_mutex_unlock(&mutex_tick);
		}
		if(tick_thread_done == true){
			tick_thread_started = false;
			pthread_exit(NULL);
		}
	}
}

bool animation_thread_on = false;

void*
animation_thread (void* ){
	while(animation_thread_on == true){
		ncplane_move_yx(clockplane, ystd/3 + 1, -15);
		for (int i = 0; i < 200; i++){
			if( animation_thread_on == false)
				pthread_exit(NULL);
			usleep(20000);
			ncplane_move_rel(clockplane, 0, 1);
		}
		ncplane_move_yx(clockplane, ystd/3 + 1, -30);
	}
	pthread_exit(NULL);
}

void
fix_offset(struct ncplane* plane, int offset){
	ncplane_move_yx(plane, ystd/3 + 1, xstd/3);
	ncplane_move_rel(plane, 0, offset);
}


typedef enum MODE {
	CLOCK_MODE = 0,
	STOPWATCH_MODE,
	HELP_MODE
} MODE;

MODE PREV_MODE = CLOCK_MODE;
MODE CUR_MODE = CLOCK_MODE;

bool thread_done = false;
static unsigned font_number = 0;


int offset_fix_event = 1;

#if defined(DEBUG_OFFSET) || defined(DEBUG_BEFORE_TWODOTS)

int displayed_num = 0;
int prev_key = 0;
int twodots_debug_on = 0;

static void*
handle_input(void* arg){
	ncinput ni;
    struct notcurses* nc = (struct notcurses*)arg;
	uint32_t id;

	while((id = notcurses_get_blocking(nc, &ni)) != (uint32_t)-1){
		if(id == 0){
			continue;
		}
		if(id == 'q'){
            pthread_mutex_lock(&mutex);
			thread_done = true;
			tick_thread_done = true;
            pthread_cond_signal(&cond);  // Signal the condition variable
            pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
			break;
		}
		if(id == 'i'){
			if (displayed_num < 9) displayed_num ++;
			else displayed_num = 0;
			continue;
		}
		if(id == 'd'){
			if (displayed_num > 0) displayed_num --;
			else displayed_num = 9;
			continue;
		}
		if(id == 'n'){
			if(font_number < MAX_FONT_NUM ) font_number++;
			else font_number = 0;
		}
		if(id == 'p'){
			if(font_number > 0) font_number--;
			else font_number = MAX_FONT_NUM;
		}
		if(id == '0') prev_key = 0;
		if(id == '1') prev_key = 1;
		if(id == '2') prev_key = 2;
		if(id == '3') prev_key = 3;
		if(id == '4') prev_key = 4;
		if(id == '5') prev_key = 5;
		if(id == '6') prev_key = 6;
		if(id == '7') prev_key = 7;
		if(id == '8') prev_key = 8;
		if(id == '9') prev_key = 9;
		if(id == '>'){
		switch(prev_key){
			case 0: dig_0 ++; break;
			case 1: dig_1 ++; break;
			case 2: dig_2 ++; break;
			case 3: dig_3 ++; break;
			case 4: dig_4 ++; break;
			case 5: dig_5 ++; break;
			case 6: dig_6 ++; break;
			case 7: dig_7 ++; break;
			case 8: dig_8 ++; break;
			case 9: dig_9 ++; break;
			}
		}
		if(id == '<'){
		switch(prev_key){
			case 0: dig_0 --; break;
			case 1: dig_1 --; break;
			case 2: dig_2 --; break;
			case 3: dig_3 --; break;
			case 4: dig_4 --; break;
			case 5: dig_5 --; break;
			case 6: dig_6 --; break;
			case 7: dig_7 --; break;
			case 8: dig_8 --; break;
			case 9: dig_9 --; break;
			}
		}
		if(id == 'h'){
			if(CUR_MODE != HELP_MODE) CUR_MODE = HELP_MODE;
			else CUR_MODE = CLOCK_MODE;
			}
		if(id == 't'){
			if (twodots_debug_on == 0) twodots_debug_on = 1;
			else twodots_debug_on = 0;
		}
	  if(id == 'r'){
		  dig_0 = 5; dig_1 = 5; dig_2 = 5; dig_3 = 5; dig_4 = 5; dig_5 = 5; dig_6 = 5; dig_7 = 5; dig_8 = 5, dig_9 = 5;
		}
	  if(id == 's'){
		  FILE* fp = fopen("./offset_debug_info","a");
		  fputs("saved values of offsets for font [",fp);
		  fputs(fonts[font_number].font_name,fp);
		  fputs("]\n",fp);
		  fprintf(fp, "with first digit: %d\n", displayed_num);
		  fprintf(fp,"\
					   zero is	: %s	\n \
					   one is	: %s	\n \
					   two is	: %s	\n \
					   three is	: %s	\n \
					   four is	: %s	\n \
					   five is	: %s	\n \
					   six is	: %s	\n \
					   seven is	: %s	\n \
					   eight is	: %s	\n \
					   nine is	: %s	\n", dig0, dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8 , dig9);
		  fclose(fp);
	  }

	}
}

#endif

#ifndef DEBUG_OFFSET

static void*
handle_input(void* arg){
	ncinput ni;
    struct notcurses* nc = (struct notcurses*)arg;
	uint32_t id;

	while((id = notcurses_get_blocking(nc, &ni)) != (uint32_t)-1){
		if(id == 0){
			continue;
		}
		if(id == 'q'){
            pthread_mutex_lock(&mutex);
			thread_done = true;
			tick_thread_done = true;
            pthread_cond_signal(&cond);  // Signal the condition variable
            pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
			break;
		}
		if(id == 'n'){
			if(font_number < MAX_FONT_NUM ){
				font_number++;
			}

			else
				font_number = 0;

			offset_fix_event = 1;
		}
		if(id == 'p'){
			if(font_number > 0)
				font_number--;
			else
				font_number = MAX_FONT_NUM;

			offset_fix_event = 1;
		}
		if(id == 's'){
			if(CUR_MODE != STOPWATCH_MODE) {
				if(tick_thread_started == false){
					tick_thread_done = false;
					tick_thread_started = true;
					if(pthread_create(&thread_id_tick, NULL, &current_tick, NULL) != 0){
						exit(-1);
					}
				}
				PREV_MODE = CUR_MODE;
				CUR_MODE = STOPWATCH_MODE;
			}
		}
		if(id == 'r'){
			if(CUR_MODE == STOPWATCH_MODE){
				tick_thread_done = true;
				if(pthread_join(thread_id_tick, NULL) != 0){
					exit(-1);
				}
				current_sec = 0;
				current_ms = 0;
				current_ms_twodigits = 0;
				current_min = 0;

				if(pthread_create(&thread_id_tick, NULL, &current_tick, NULL) != 0){
					exit(-1);
				}
				tick_thread_done = false;

			}
		}
		if(id == ' '){
			if (paused == false) paused = true;
			else paused = false;
		}

		if(id == 'c'){
			if(CUR_MODE != CLOCK_MODE){
				PREV_MODE = CUR_MODE;
				CUR_MODE = CLOCK_MODE;
			}
		}

		if(id == NCKEY_UP){
			ncplane_move_rel(clockplane, -1, 0);
		}
		if(id == NCKEY_DOWN){
			ncplane_move_rel(clockplane, 1, 0);
		}
		if(id == NCKEY_LEFT){
			ncplane_move_rel(clockplane, 0, -1);
		}
		if(id == NCKEY_RIGHT){
			ncplane_move_rel(clockplane, 0, 1);
		}
		if (id == 'l'){
			if(color_index < SIZEOFARRAY(colors)){
					ncplane_set_fg_rgb(clockplane, colors[color_index]);
					color_index++;
			}
			else if(color_index == SIZEOFARRAY(colors)){
					ncplane_erase(clockplane);
					color_index = 0;
			}
						// gotta find a way to restore to default colors,
				        // supposedly with notcurses_default_foreground(nc,&fg);
						// or reset_term_attributes(ti, f); ?
		}
		if(id == 'h'){
			if(CUR_MODE != HELP_MODE){
				PREV_MODE = CUR_MODE;
				CUR_MODE = HELP_MODE;
			}
			else CUR_MODE = PREV_MODE;
		}
		if(id == 'a'){
			if(animation_thread_on == false){
				animation_thread_on = true;
				if(pthread_create(&animation, NULL, &animation_thread, NULL) != 0){
					exit(-1);
				}
			}
			else{
				animation_thread_on = false;
				if(pthread_join(animation, NULL) != 0){
					notcurses_stop(nc);
					exit(-1);
				}
				fix_offset(clockplane, 0);

			}
		}
	}
	return NULL;
}
#endif


#ifdef DEBUG_OFFSET
void display_help(struct ncplane* plane){

	ncplane_putstr_yx(plane, 1, 1, "this is the help menu. Press h again to resume to normal application\n");
	ncplane_putstr_yx(plane, 2, 1, "🕛🕧🕐🕜🕑🕝🕒🕞🕓🕟🕔🕠🕕🕡🕖🕢🕗🕣🕘🕤🕙");
	ncplane_putstr_yx(plane, 4, 1, "q - quit\n");
	ncplane_putstr_yx(plane, 5, 1, "n - to change to next font \n");
	ncplane_putstr_yx(plane, 6, 1, "d - decrement a number");
	ncplane_putstr_yx(plane, 7, 1, "i - increment a number");
	ncplane_putstr_yx(plane, 8, 1, "r - reset all offsets to 5");
	ncplane_putstr_yx(plane, 9, 1, "0-9 - choose from 0 to 9 which number's offset to change");
	ncplane_putstr_yx(plane, 10, 1, "> - increment chosen number's offset");
	ncplane_putstr_yx(plane, 11, 1, "< - decrement chosen number's offset");
	ncplane_putstr_yx(plane, 12, 1, "t - toggle between twodots offset and offset between digits");
	ncplane_putstr_yx(plane, 13, 1, "h - help menu");

};
#else

void display_help(struct ncplane* plane){

	ncplane_putstr_yx(plane, 1, 1, "this is the help menu. Press h again to resume to normal application\n");
	ncplane_putstr_yx(plane, 2, 1, "🕛🕧🕐🕜🕑🕝🕒🕞🕓🕟🕔🕠🕕🕡🕖🕢🕗🕣🕘🕤🕙");
	ncplane_putstr_yx(plane, 4, 1, "q - quit\n");
	ncplane_putstr_yx(plane, 5, 1, "n - to change to next font \n");
	ncplane_putstr_yx(plane, 6, 1, "p - to change to previous font \n");
	ncplane_putstr_yx(plane, 7, 1, "s - stopwatch mode");
	ncplane_putstr_yx(plane, 8, 1, "r - reset stopwatch");
	ncplane_putstr_yx(plane, 9, 1, "SPACE - pause stopwatch");
	ncplane_putstr_yx(plane, 10, 1, "c - clock mode");
	ncplane_putstr_yx(plane, 11, 1, "h - help menu");
	ncplane_putstr_yx(plane, 12, 1, "⬆️ ➡️ ⬇️ ⬅️ - move the clock plane");

};
#endif

void display_cloc(struct ncplane* plane, int x_offset, int y_center, int hour, int minute, int second, font cur_font) {

		if(offset_fix_event == 1 && xstd > 100){ // not the most elegant solution, but kinda works
			offset_fix_event = 0;                // visually recentering clock plane whenever the font is changed or resize_cb event happens
			fix_offset(plane, fonts[font_number].correct_offset);
		}
		x_offset = x_offset;
		table[first_digit((hour))](plane, x_offset , y_center, cur_font);
		x_offset = cur_font.calculate_offset(first_digit(hour),last_digit(hour)) + x_offset;
		table[last_digit((hour))] (plane, x_offset, y_center, cur_font);

		x_offset = x_offset + cur_font.offset_before_twodots(last_digit(hour));
		table[TWO_DOTS](plane, x_offset, y_center,cur_font );
		x_offset = x_offset + cur_font.offset_after_twodots(first_digit(minute));

		table[first_digit((minute))](plane, x_offset , y_center, cur_font);
		x_offset = x_offset + cur_font.calculate_offset(first_digit(minute),last_digit(minute));
		table[last_digit((minute))] (plane, x_offset, y_center, cur_font);

		x_offset = x_offset + cur_font.offset_before_twodots(last_digit(last_digit(minute)));;
		table[TWO_DOTS](plane, x_offset, y_center, cur_font);
		x_offset = x_offset + cur_font.offset_after_twodots(first_digit(second));;

		table[first_digit((second))](plane, x_offset , y_center, cur_font);
		x_offset = x_offset + cur_font.calculate_offset(first_digit(second),last_digit(second));
		table[last_digit((second))] (plane,  x_offset , y_center, cur_font);
}


int resize_cb(struct ncplane* plane){
	offset_fix_event = 1;
	notcurses_stddim_yx(nc, &ystd, &xstd);
	x_center = xstd/3 ;
	y_center = ystd/3 + 1;
	if( ystd > 15 && xstd > 70)
		ncplane_move_yx(plane, y_center, x_center);
	if(xstd < 70 )
		ncplane_move_yx(plane, y_center, 0);
	if( ystd < 15 && xstd > 70)
		ncplane_move_yx(plane, 0, x_center);
	if( ystd < 15 && xstd < 70)
		ncplane_move_yx(plane, 0, 0);

	return 0;
}

int main(){
	struct tm* local;

	struct notcurses_options opts = {0}; // man notcurses_init(3)
	nc = notcurses_init(&opts, stdout);
	if(nc == NULL){
		return EXIT_FAILURE;
	}
	stdplane = notcurses_stdplane(nc);

	notcurses_stddim_yx(nc, &ystd, &xstd);
	struct ncplane_options nopts = {
		.y = ystd/3 +1,
		.x = xstd/3 +1,
		.rows = 150,
		.cols = 150,
		.name = "plot",
		.resizecb = resize_cb,
		/* .flags = NCPLANE_OPTION_FIXED, */
		.margin_b = 0,
		.margin_r = 0,
	};
	clockplane = ncplane_create(stdplane, &nopts);

    if(pthread_create(&thread_id_input, NULL, &handle_input, nc)){
		exit(-1);
		return -1;
	}

	while(thread_done == false){
		time_t t = time(NULL);
		local = localtime(&t);
		if(CUR_MODE == STOPWATCH_MODE)
			pthread_cond_wait(&cond, &mutex);  // Wait until the condition variable is signaled

		ncplane_erase(stdplane);
		ncplane_erase(clockplane);

#ifndef DEBUG_OFFSET
		if(CUR_MODE == CLOCK_MODE){
		display_cloc(clockplane, 0, 0,
					 local->tm_hour, local->tm_min, local->tm_sec, fonts[font_number]);
		}
		else if(CUR_MODE == STOPWATCH_MODE){
		display_cloc(clockplane, 0, 0,
				     current_min, current_sec, current_ms_twodigits, fonts[font_number]);
		}
		else if( CUR_MODE == HELP_MODE)
			display_help(clockplane);
#endif

#ifdef DEBUG_MODE
		SCREENSIZE;
#endif

		// executable build in between this macro is for debugging font offset values
		// - shoulda probably been a separate source from the main application, but alas
#ifdef DEBUG_OFFSET
		y_center = ystd/3 + 1;
		x_center = xstd/3 + 1;
		if(twodots_debug_on && CUR_MODE != HELP_MODE){
			OFFSET_BEFORE_TWODOTS(font_number,
			    dig_0, dig_1, dig_2, dig_3, dig_4, dig_5, dig_6, dig_7, dig_8, dig_9);
		}
		else if(CUR_MODE == CLOCK_MODE && !twodots_debug_on){
				OFFSET_DEBUG(displayed_num,
							 font_number,
				dig_0, dig_1, dig_2, dig_3, dig_4, dig_5, dig_6, dig_7, dig_8, dig_9);

		}
		else if(CUR_MODE == HELP_MODE){
				display_help(clockplane);
		}
		DEBUG_OFFSET_PRINT;


#endif
		notcurses_render(nc);
	}
		if(pthread_join(thread_id_input, NULL) == 0){
			notcurses_stop(nc);
			return 1;
		}
}
