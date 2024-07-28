#include <stdio.h>
#include <time.h>
#include "digits.h"

#define TWO_DOTS 10




/* struct tm { */
/* 	int tm_sec;    /\* Seconds (0-60) *\/ */
/* 	int tm_min;    /\* Minutes (0-59) *\/ */
/* 	int tm_hour;   /\* Hours (0-23) *\/ */
/* 	int tm_mday;   /\* Day of the month (1-31) *\/ */
/* 	int tm_mon;    /\* Month (0-11) *\/ */
/* 	int tm_year;   /\* Year - 1900 *\/ */
/* 	int tm_wday;   /\* Day of the week (0-6, Sunday = 0) *\/ */
/* 	int tm_yday;   /\* Day in the year (0-365, 1 Jan = 0) *\/ */
/* 	int tm_isdst;  /\* Daylight saving time *\/ */
/* }; */

inline int
first_digit(int num){
	int digit = num / 10;
	return digit;
}

inline int
last_digit(int num){
	int digit = num % 10;
	return digit;
}

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

int main(){
	struct tm* local;
	time_t t = time(NULL);

	while(0){
		time_t t = time(NULL);
		local = localtime(&t);
		sleep(1);
		/* printf("sec %d\n", local->tm_sec); */
		/* printf("sec %d %d \n", first_digit(local->tm_sec),last_digit(local->tm_sec)); */
		/* printf("hour %d%d\n", first_digit(local->tm_hour),last_digit(local->tm_hour) ); */
		/* printf("min %d\n", local->tm_min); */
		/* printf("day in month %d\n", local->tm_mday); */
		/* printf("mon %d\n", local->tm_mon + 1); */
		/* printf("%d\n", local->tm_year); */
	}


		/* printf("%s",zero); */
		/* printf("%s",one); */
		/* printf("%s",two); */
		/* printf("%s",three); */
		/* printf("%s",four); */
		/* printf("%s",five); */
		/* printf("%s",six); */
		/* printf("%s",seven); */
		/* printf("%s",eight); */
		/* printf("%s",nine); */
		/* printf("%s",nine); */
	struct notcurses_options opts = {0}; // man notcurses_init(3)
	struct notcurses* nc = notcurses_init(&opts, stdout);
	if(nc == NULL){
		return EXIT_FAILURE;
	}
	struct ncplane* stdplane = notcurses_stdplane(nc);

	ncplane_cursor_move_yx(stdplane, 50, 0);
	ncinput ni;
	uint32_t c;
	while(1){
		time_t t = time(NULL);
		local = localtime(&t);
		/* sleep(1); */
		unsigned int y = 0 , x =0;
		notcurses_stddim_yx(nc, &y, &x);
		unsigned y_center = y / 2 - 5;
		unsigned x_center = 0;
		clear_prev_screen(stdplane);
		table[first_digit((local->tm_hour))](stdplane, 0 + x_center, y_center);
		table[last_digit((local->tm_hour))] (stdplane, 5 + x_center, y_center);
		table[TWO_DOTS](stdplane, 20 + x_center, y_center);
		table[first_digit((local->tm_min))](stdplane, 30 + x_center, y_center);
		table[last_digit((local->tm_min))] (stdplane, 40 + x_center, y_center);
		table[TWO_DOTS](stdplane, 50 + x_center, y_center);
		table[first_digit((local->tm_sec))](stdplane, 60 + x_center, y_center);
		table[last_digit((local->tm_sec))](stdplane,  70 + x_center, y_center);
		notcurses_render(nc);
	}

	while((c = notcurses_get_blocking(nc, &ni)) != (uint32_t)-1){
		if(ni.evtype == NCTYPE_RELEASE){
			continue;
		} else if(c == 'q'){
			notcurses_stop(nc);
			break;
		} else if(c == 'j'){  // this whole block needs to be refactored
			notcurses_render(nc);
		}
				/* nc.render(); */
	}
}
