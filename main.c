#include <time.h>
#include "digits.h"
#include <pthread.h>
#include "stopwatch.h"

static int current_ms = 0;
static int current_sec = 0;
static int current_min = 0;

#define TWO_DOTS 10

#define MAX_FONT_NUM sizeof(fonts) / sizeof(fonts[0]) - 1
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

#ifdef DEBUG_MODE

#define SCREENSIZE do{							\
	 char xchar[100] ;							\
	 char ychar[100] ;							\
	 snprintf(xchar, 100, "%d", x);			\
	 snprintf(ychar, 100, "%d", y);			\
	 ncplane_cursor_move_yx(stdplane,0, 0);		\
	 ncplane_putstr(stdplane,"X:");				\
	 ncplane_putstr(stdplane,xchar);			\
	 ncplane_putstr(stdplane,"Y:");				\
	 ncplane_putstr(stdplane,ychar);			\
	 ncplane_cursor_move_yx(stdplane, 1, 0);					\
	 ncplane_putstr(stdplane,"current font is: ");			\
	 ncplane_putstr(stdplane,fonts[font_number].font_name);	\
	 ncplane_cursor_move_yx(stdplane, 0, 0);				 \
	 }while(0)									\

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

typedef enum MODE {
	CLOCK_MODE = 0,
	STOPWATCH_MODE
} MODE;

MODE PREV_MODE = CLOCK_MODE;
MODE CUR_MODE = CLOCK_MODE;

bool thread_done = false;
static unsigned font_number = 0;

static void *
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
			if(font_number < MAX_FONT_NUM )
				font_number++;
			else
				font_number = 0;
		}
		if(id == 'p'){
			if(font_number > 0)
				font_number--;
			else
				font_number = MAX_FONT_NUM;
		}
		if(id == 's'){
			if(CUR_MODE == CLOCK_MODE) {
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
			if(CUR_MODE == STOPWATCH_MODE){
				PREV_MODE = CUR_MODE;
				CUR_MODE = CLOCK_MODE;
			}
		}
	}
	return NULL;
}


void display_cloc(struct ncplane* plane, int x_offset, int y_center, int hour, int minute, int second, font cur_font) {

		x_offset = x_offset + cur_font.correct_offset;
		if(x_offset < 0)
			x_offset = 0; // some fonts have negative correct_offsets, which will cause unwanted graphical problems. This is a tiny fix.
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

int screen_adjust(font* cur_font, int x_size, int y_size, unsigned* x_center, unsigned* y_center) {
	if ( y_size < cur_font->y_screen_size){
		*y_center = *y_center/5;
	}
	if ( x_size < cur_font->x_screen_size){
		*x_center = *x_center/5;
	}
	return 0;
}


int x_center_std = 0;
int y_center_std = 0;
unsigned xstd,ystd;

struct ncplane* stdplane;
struct notcurses* nc;

int resize_cb(struct ncplane* plane){
	notcurses_stddim_yx(nc, &ystd, &xstd);
	x_center_std = xstd/3 + 1;
	y_center_std = ystd/3 + 1;
	if( ystd > 15 && xstd > 70)
		ncplane_move_yx(plane, y_center_std, x_center_std);
	if(xstd < 70 )
		ncplane_move_yx(plane, y_center_std, 0);
	if( ystd < 15 && xstd > 70)
		ncplane_move_yx(plane, 0, x_center_std);
	if( ystd < 15 && xstd < 70)
		ncplane_move_yx(plane, 0, 0);

	return 0;
}

int main(){
	struct tm* local;
	/* time_t t = time(NULL); */

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
	struct ncplane* clockplane = ncplane_create(stdplane, &nopts);

    if(pthread_create(&thread_id_input, NULL, &handle_input, nc)){
		exit(-1);
		return -1;
	}

	while(thread_done == false){
		time_t t = time(NULL);
		local = localtime(&t);
		/* sleep(1); */
		unsigned int y = 0 , x =0;
		if(CUR_MODE == STOPWATCH_MODE)
			pthread_cond_wait(&cond, &mutex);  // Wait until the condition variable is signaled

		// take dimensions of the screen, and third of the screen, to be used to center the output
		notcurses_stddim_yx(nc, &y, &x);
		unsigned y_center = y / 3 + 1;
		unsigned x_center = x / 3;

		screen_adjust(&fonts[font_number], x, y, &x_center, &y_center);

		ncplane_erase(stdplane);
		ncplane_erase(clockplane);
		/* fprintf(stderr, "ovo je x_offset: %d, y_offset: %d\n", x_center, y_center); */

		if(CUR_MODE == CLOCK_MODE){
		display_cloc(clockplane, 0, 0,
					 local->tm_hour, local->tm_min, local->tm_sec, fonts[font_number]);
		}
		else if(CUR_MODE == STOPWATCH_MODE){
		display_cloc(clockplane, 0, 0,
				     current_min, current_sec, current_ms_twodigits, fonts[font_number]);
		}



		// uncomment these macros and comment out display_cloc call if you want to debug and display
		// offset (spacing) before two dots, offset between numbers and offset after two dots by passing TWO_DOTS
		// to first argument of  OFFSET_DEBUG

		// MACRO THAT IS USED TO DEBUG SCREEN RESIZE EVENTS. UNCOMMENT IF YOU'RE WORKING ON THIS

#ifdef DEBUG_MODE
		SCREENSIZE;
#endif

	   /* 	OFFSET_BEFORE_TWODOTS(8, */
       /* 7,  6, 7, 7, 7, 7, 7, 6, 7, 7); */

		/* OFFSET_DEBUG(9, */
		/* 			 8, */
        /* 6,  6,  6,  6,  6,  6,  6,   6,   6,  6); */

		notcurses_render(nc);
	}
		if(pthread_join(thread_id_input, NULL) == 0){
			notcurses_stop(nc);
			return 1;
		}
}
