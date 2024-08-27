#include <time.h>
#include "digits.h"
#include <pthread.h>

#define TWO_DOTS 10

#define OFFSET_DEBUG(NUM, FONTNUM, OFFSET0, OFFSET1, OFFSET2, OFFSET3, OFFSET4, OFFSET5, OFFSET6, OFFSET7, OFFSET8, OFFSET9) do{ \
		table[(NUM)](stdplane, 60 + x_center, y_center - 10, fonts[(FONTNUM)]);	\
		table[0](stdplane, 60 + (OFFSET0) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(NUM)](stdplane, 70 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[1](stdplane, 70 + (OFFSET1) + x_center, y_center - 10, fonts[(FONTNUM)]);\
\
		table[(NUM)](stdplane, 30 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[2](stdplane, 30 + (OFFSET2) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 50 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[3] (stdplane, 50 + (OFFSET3) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 0 + x_center, y_center - 10, fonts[(FONTNUM)]);\
		table[3] (stdplane, 0 + (OFFSET3) + x_center, y_center - 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 30 + x_center, y_center , fonts[(FONTNUM)]);\
		table[4] (stdplane, 30 + (OFFSET4) + x_center, y_center, fonts[(FONTNUM)]);	\
\
		table[(NUM)](stdplane, 50 + x_center, y_center , fonts[(FONTNUM)]);\
		table[5] (stdplane, 50 + (OFFSET5) + x_center, y_center , fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 0 + x_center, y_center, fonts[(FONTNUM)]);\
		table[6] (stdplane, 0 + (OFFSET6) + x_center, y_center, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 30 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[7] (stdplane, 30 + (OFFSET7) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 50 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[8] (stdplane, 50 + (OFFSET8) + x_center, y_center + 10, fonts[(FONTNUM)]); \
\
		table[(NUM)](stdplane, 0 + x_center, y_center + 10, fonts[(FONTNUM)]);\
		table[9] (stdplane, 0 + (OFFSET9) + x_center, y_center + 10, fonts[(FONTNUM)]);	\
		}while(0) \


typedef struct nciqueue {
	ncinput ni;
	struct nciqueue *next;
} nciqueue;

static int input_pipefds[2] = {-1, -1};
static pthread_cond_t cond; // use pthread_condmonotonic_init()

static pthread_t tid;
static nciqueue* queue;
static nciqueue** enqueue = &queue;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void
clear_prev_screen(struct ncplane* plane){
	unsigned int x,y;
	// find the dimension of x, and clear the first row with spaces?
	ncplane_dim_yx(plane, &y, &x);
	std::string clear_string(x,' ');
	for(int i=0; i<y; i++){ // fill whole screen with spaces
		ncplane_putstr_yx(plane, i , 0, clear_string.c_str());
	}
}


static int
pass_along(const ncinput* ni){
	pthread_mutex_lock(&lock);
	nciqueue *nq = (nciqueue*) malloc(sizeof(*nq));
	memcpy(&nq->ni, ni, sizeof(*ni));
	nq->next = NULL;
	*enqueue = nq;
	enqueue = &nq->next;
	pthread_mutex_unlock(&lock);
	const uint64_t eventcount = 1;
	int ret = 0;
	if(write(input_pipefds[1], &eventcount, sizeof(eventcount)) < 0){
		ret = -1;
	}
	pthread_cond_signal(&cond);
  return ret;
}

static void *
handle_input(void* vnc){
  ncinput ni;
  struct notcurses* nc = (struct notcurses*) vnc;
  uint32_t id;
  while((id = notcurses_get_blocking(nc, &ni)) != (uint32_t)-1){
    if(id == 0){
      continue;
    }
    if(id == NCKEY_EOF){
      break;
    }
    // go ahead and pass keyboard through to demo, even if it was a 'q' (this
    // might cause the demo to exit immediately, as is desired). we can't just
    // mess with the menu/HUD in our own context, as the demo thread(s) might
    // be rendering, or otherwise fucking with things we musn't fuck with
    // concurrentwise (z-axis manipulations, etc.).
    pass_along(&ni);
  }
  return NULL;
}

/* void */
/* *handle_input(void *arg){ */
/* 	ncinput ni; */
/* 	struct notcurses* nc = (struct notcurses*) arg; */
/* 	uint32_t c; */
/* 	while((c = notcurses_get_blocking(nc, &ni)) != (uint32_t)-1){ */
/* 		if(ni.evtype == NCTYPE_RELEASE){ */
/* 			continue; */
/* 		} else if(c == 'q'){ */
/* 			notcurses_stop(nc); */
/* 			pthread_exit(NULL); */
/* 			break; */
/* 		} */
/* 	} */
/* 		/\* } else if(c == 'j'){  // this whole block needs to be refactored *\/ */
/* 		/\* 	notcurses_render(nc); *\/ */
/* 		/\* } *\/ */
/* 		/\* nc.render(); *\/ */
/*     return NULL; // what dis do */
/* } */

void display_cloc(struct notcurses* nc, struct ncplane* stdplane,int x_offset, int y_center, int hour, int minute, int second,
/* int (*calc_offset)(int, int), int (*offsetbf_dots) (int),int (*offsetaf_dots) (int), */ font cur_font) {
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
		close(input_pipefds[0]);
		close(input_pipefds[1]);
		input_pipefds[0] = input_pipefds[1] = -1;
		return -1;
	}
	while(1){
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

		clear_prev_screen(stdplane);

		int x_offset = x_center; /// beggining

		display_cloc(nc, stdplane, x_offset, y_center,
					local->tm_hour, local->tm_min, local->tm_sec, fonts[0]);
		/* OFFSET_DEBUG(5, 2,    4, 3, 4, 4, 4, 4, 4, 4, 4, 4); */
 	 /*        INDEX(0, 0,    0, 1, 2, 3, 4, 5, 6, 7, 8, 9); */
		/* table[9](stdplane, 0 + x_center, y_center - 0,fonts[2]); */

		/* table[0](stdplane, 70 + x_center, y_center - 10, fonts[2]); */
		/* table[1](stdplane, 78 + x_center, y_center - 10, fonts[2]); */

		/* table[0](stdplane, 30 + x_center, y_center - 10, fonts[2]); */
		/* table[2](stdplane, 38 + x_center, y_center - 10, fonts[2]); */

		/* table[0](stdplane, 50 + x_center, y_center - 10, fonts[2]); */
		/* table[3] (stdplane, 58 + x_center, y_center - 10, fonts[2]); */

		/* table[0](stdplane, 0 + x_center, y_center - 10, fonts[2]); */
		/* table[3] (stdplane, 8 + x_center, y_center - 10, fonts[2]); */

		/* table[0](stdplane, 30 + x_center, y_center , fonts[2]); */
		/* table[4] (stdplane, 38 + x_center, y_center, fonts[2]); */

		/* table[0](stdplane, 50 + x_center, y_center , fonts[2]); */
		/* table[5] (stdplane, 58 + x_center, y_center , fonts[2]); */

		/* table[0](stdplane, 0 + x_center, y_center, fonts[2]); */
		/* table[6] (stdplane, 8 + x_center, y_center, fonts[2]); */

		/* table[0](stdplane, 30 + x_center, y_center + 10, fonts[2]); */
		/* table[7] (stdplane, 38 + x_center, y_center + 10, fonts[2]); */

		/* table[0](stdplane, 50 + x_center, y_center + 10, fonts[2]); */
		/* table[8] (stdplane, 58 + x_center, y_center + 10, fonts[2]); */

		/* table[0](stdplane, 0 + x_center, y_center + 10, fonts[2]); */
		/* table[9] (stdplane, 8 + x_center, y_center + 10, fonts[2]); */

//		table[first_digit((local->tm_hour))](stdplane, x_offset , y_center);

		notcurses_render(nc);
	}

}
