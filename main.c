#include <time.h>
#include "digits.h"
#include <pthread.h>

#define TWO_DOTS 10

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

bool thread_done = false;
static int font_number = 0;
#define MAX_FONT_NUM sizeof(fonts) / sizeof(fonts[0]) - 1


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
			thread_done = true;
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
	}
	return NULL;
}

void display_cloc(struct notcurses* nc, struct ncplane* stdplane,int x_offset, int y_center, int hour, int minute, int second,
/* int (*calc_offset)(int, int), int (*offsetbf_dots) (int),int (*offsetaf_dots) (int), */ font cur_font) {
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
	time_t t = time(NULL);

	struct notcurses_options opts = {0}; // man notcurses_init(3)
	struct notcurses* nc = notcurses_init(&opts, stdout);
	if(nc == NULL){
		return EXIT_FAILURE;
	}
	struct ncplane* stdplane = notcurses_stdplane(nc);

    pthread_t thread_id;
	ncplane_cursor_move_yx(stdplane, 50, 0);
    if(pthread_create(&thread_id, NULL, &handle_input, nc)){
		return -1;
	}
	while(thread_done != true){
		time_t t = time(NULL);
		local = localtime(&t);
		/* sleep(1); */
		unsigned int y = 0 , x =0;

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

		display_cloc(nc, stdplane, x_offset, y_center,
					local->tm_hour, local->tm_min, local->tm_sec, fonts[font_number]);
	   /* 	OFFSET_BEFORE_TWODOTS(8, */
       /* 7,  6, 7, 7, 7, 7, 7, 6, 7, 7); */
	/* 0,  1, 2, 3, 4, 5, 6, 7, 8, 9); */

		/* OFFSET_DEBUG(9, */
		/* 			 8, */
        /* 6,  6,  6,  6,  6,  6,  6,   6,   6,  6); */
 	 /* 0,  1,  2,  3,  4,  5,  6,   7,   8,  9); */
     /* 0,   1,   2,   3,   4,   5,   6,   7,    8,  9); */

		notcurses_render(nc);
	}
		if(pthread_join(thread_id, NULL) == 0){
			notcurses_stop(nc);
			return 1;
		}
}
