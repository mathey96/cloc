#include <time.h>
#include "digits.h"
#include <pthread.h>
#include "stopwatch.h"


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

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mutex_tick = PTHREAD_MUTEX_INITIALIZER;

static pthread_mutex_t mutex_reset = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

bool tick_thread_done = true;
bool tick_thread_reset = false;
bool tick_thread_started = false;

static pthread_t thread_id_input;
static pthread_t thread_id_tick;


long long current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long) ( (tv.tv_usec / 1000));
}

int current_ms_twodigits = 0;
int tick_counter = 0;

void* current_tick (void* arg){
	long long tick = 0;
	while(1){
		if(tick != current_time_millis()){
			pthread_mutex_lock(&mutex_tick);
			tick = current_time_millis();
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

			pthread_cond_signal(&cond);  // Signal the condition variable
			pthread_mutex_unlock(&mutex_tick);
		}
		if(tick_thread_done == true){
			tick_thread_started = false;
			pthread_exit(NULL);
		}
	}
}

enum MODE {
	CLOCK_MODE = 0,
	STOPWATCH_MODE
};

int PREV_MODE = CLOCK_MODE;
int CUR_MODE = CLOCK_MODE;

bool thread_done = false;
static int font_number = 0;

static void *
handle_input(void* arg){
	ncinput ni;
    struct notcurses* nc = (struct notcurses*)arg;
	uint32_t id;
	struct ncplane* stdplane = notcurses_stdplane(nc);

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
				current_min = 0;

				if(pthread_create(&thread_id_tick, NULL, &current_tick, NULL) != 0){
					exit(-1);
				}
				tick_thread_done = false;

			}
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


void display_cloc(struct notcurses* nc, struct ncplane* stdplane,int x_offset, int y_center, int hour, int minute, int second, font cur_font) {
		x_offset = x_offset + cur_font.correct_offset;
		table[first_digit((hour))](stdplane, x_offset , y_center, cur_font);
		x_offset = cur_font.calculate_offset(first_digit(hour),last_digit(hour)) + x_offset;
		table[last_digit((hour))] (stdplane, x_offset, y_center, cur_font);

		x_offset = x_offset + cur_font.offset_before_twodots(last_digit(hour));
		table[TWO_DOTS](stdplane, x_offset, y_center,cur_font );
		x_offset = x_offset + cur_font.offset_after_twodots(first_digit(minute));

		table[first_digit((minute))](stdplane, x_offset , y_center, cur_font);
		x_offset = x_offset + cur_font.calculate_offset(first_digit(minute),last_digit(minute));
		table[last_digit((minute))] (stdplane, x_offset, y_center, cur_font);

		x_offset = x_offset + cur_font.offset_before_twodots(last_digit(last_digit(minute)));;
		table[TWO_DOTS](stdplane, x_offset, y_center, cur_font);
		x_offset = x_offset + cur_font.offset_after_twodots(first_digit(second));;

		table[first_digit((second))](stdplane, x_offset , y_center, cur_font);
		x_offset = x_offset + cur_font.calculate_offset(first_digit(second),last_digit(second));
		table[last_digit((second))] (stdplane,  x_offset , y_center, cur_font);
}

int main(){
	struct tm* local;
	/* time_t t = time(NULL); */

	struct notcurses_options opts = {0}; // man notcurses_init(3)
	struct notcurses* nc = notcurses_init(&opts, stdout);
	if(nc == NULL){
		return EXIT_FAILURE;
	}
	struct ncplane* stdplane = notcurses_stdplane(nc);

	ncplane_cursor_move_yx(stdplane, 50, 0);
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


		if ( x <= 60) // handling windows resizing
			x_center = 0;
		else if ( y < 25)
			y_center = 0;

		ncplane_erase(stdplane);

		int x_offset = x_center; /// beggining

		if(CUR_MODE == CLOCK_MODE){
		display_cloc(nc, stdplane, x_offset, y_center,
					 local->tm_hour, local->tm_min, local->tm_sec, fonts[font_number]);
		}
		else if(CUR_MODE == STOPWATCH_MODE){
		display_cloc(nc, stdplane, x_offset, y_center,
				     current_min, current_sec, current_ms_twodigits, fonts[font_number]);
		}


		// uncomment these macros and comment out display_cloc call if you want to debug and display
		// offset (spacing) before two dots, offset between numbers and offset after two dots by passing TWO_DOTS
		// to first argument of  OFFSET_DEBUG

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
