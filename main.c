#include <stdio.h>
#include <time.h>
#include "digits.h"

#define TWO_DOTS 10

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

int calculate_offset(int digit_1, int digit_2){
	if(  // there are a plenty of impossible cases here (e.g. there isn't 85-th minute in 24 - hour clock system
		digit_1 == 0 && digit_2 == 0 ||
		digit_1 == 0 && digit_2 == 1 ||
		digit_1 == 0 && digit_2 == 2 ||
		digit_1 == 0 && digit_2 == 3 ||
		digit_1 == 0 && digit_2 == 4 ||
		digit_1 == 0 && digit_2 == 5 ||
		digit_1 == 0 && digit_2 == 6 ||
		digit_1 == 0 && digit_2 == 7 ||
		digit_1 == 0 && digit_2 == 8 ||
		digit_1 == 0 && digit_2 == 9 ||
		digit_1 == 0 && digit_2 == 0 ||
		digit_1 == 2 && digit_2 == 0 ||
		digit_1 == 2 && digit_2 == 2 ||
		digit_1 == 2 && digit_2 == 3 ||
		digit_1 == 2 && digit_2 == 5 ||
		digit_1 == 2 && digit_2 == 6 ||
		digit_1 == 2 && digit_2 == 7 ||
		digit_1 == 2 && digit_2 == 8 ||
		digit_1 == 2 && digit_2 == 9 ||
		digit_1 == 3 && digit_2 == 0 ||
		digit_1 == 3 && digit_2 == 1 ||
		digit_1 == 3 && digit_2 == 2 ||
		digit_1 == 3 && digit_2 == 3 ||
		digit_1 == 3 && digit_2 == 5 ||
		digit_1 == 3 && digit_2 == 6 ||
		digit_1 == 3 && digit_2 == 7 ||
		digit_1 == 3 && digit_2 == 8 ||
		digit_1 == 3 && digit_2 == 9 ||
		digit_1 == 5 && digit_2 == 0 ||
		digit_1 == 5 && digit_2 == 1 ||
		digit_1 == 5 && digit_2 == 2 ||
		digit_1 == 5 && digit_2 == 3 ||
		digit_1 == 5 && digit_2 == 4 ||
		digit_1 == 5 && digit_2 == 5 ||
		digit_1 == 5 && digit_2 == 6 ||
		digit_1 == 5 && digit_2 == 7 ||
		digit_1 == 5 && digit_2 == 8 ||
		digit_1 == 5 && digit_2 == 9 ||
		digit_1 == 6 && digit_2 == 0 ||
		digit_1 == 6 && digit_2 == 1 ||
		digit_1 == 6 && digit_2 == 2 ||
		digit_1 == 6 && digit_2 == 3 ||
		digit_1 == 6 && digit_2 == 4 ||
		digit_1 == 6 && digit_2 == 5 ||
		digit_1 == 6 && digit_2 == 6 ||
		digit_1 == 6 && digit_2 == 7 ||
		digit_1 == 6 && digit_2 == 8 ||
		digit_1 == 6 && digit_2 == 9 ||
		digit_1 == 7 && digit_2 == 0 ||
		digit_1 == 7 && digit_2 == 1 ||
		digit_1 == 7 && digit_2 == 2 ||
		digit_1 == 7 && digit_2 == 3 ||
		digit_1 == 7 && digit_2 == 4 ||
		digit_1 == 7 && digit_2 == 5 ||
		digit_1 == 7 && digit_2 == 6 ||
		digit_1 == 7 && digit_2 == 7 ||
		digit_1 == 7 && digit_2 == 8 ||
		digit_1 == 7 && digit_2 == 9 ||
		digit_1 == 8 && digit_2 == 0 ||
		digit_1 == 8 && digit_2 == 1 ||
		digit_1 == 8 && digit_2 == 2 ||
		digit_1 == 8 && digit_2 == 3 ||
		digit_1 == 8 && digit_2 == 4 ||
		digit_1 == 8 && digit_2 == 5 ||
		digit_1 == 8 && digit_2 == 6 ||
		digit_1 == 8 && digit_2 == 7 ||
		digit_1 == 8 && digit_2 == 8 ||
		digit_1 == 8 && digit_2 == 9 ||
		digit_1 == 9 && digit_2 == 0 ||
		digit_1 == 9 && digit_2 == 1 ||
		digit_1 == 9 && digit_2 == 2 ||
		digit_1 == 9 && digit_2 == 3 ||
		digit_1 == 9 && digit_2 == 4 ||
		digit_1 == 9 && digit_2 == 5 ||
		digit_1 == 9 && digit_2 == 6 ||
		digit_1 == 9 && digit_2 == 7 ||
		digit_1 == 9 && digit_2 == 8 ||
		digit_1 == 9 && digit_2 == 9)
			return 7;
	else if(digit_1 == 2 && digit_2 == 1 ||
		digit_1 == 2 && digit_2 == 4 ||
		digit_1 == 3 && digit_2 == 4 ||
		digit_1 == 4 && digit_2 == 0 ||
		digit_1 == 4 && digit_2 == 1 ||
		digit_1 == 4 && digit_2 == 2 ||
		digit_1 == 4 && digit_2 == 3 ||
		digit_1 == 4 && digit_2 == 4 ||
		digit_1 == 4 && digit_2 == 5 ||
		digit_1 == 4 && digit_2 == 6 ||
		digit_1 == 4 && digit_2 == 7 ||
		digit_1 == 4 && digit_2 == 8 ||
		digit_1 == 4 && digit_2 == 9)
			return 8;
	else if (
		digit_1 == 1 && digit_2 == 2 ||
		digit_1 == 1 && digit_2 == 3 ||
		digit_1 == 1 && digit_2 == 4 ||
		digit_1 == 1 && digit_2 == 5 ||
		digit_1 == 1 && digit_2 == 0 ||
		digit_1 == 1 && digit_2 == 1 ||
		digit_1 == 1 && digit_2 == 6 ||
		digit_1 == 1 && digit_2 == 7 ||
		digit_1 == 1 && digit_2 == 8 ||
		digit_1 == 1 && digit_2 == 9)
			return 4;
	else
		return 0;
}

int offset_before_twodots(int num){
	switch(num){
	case 0:
		return 7;
		break;
	case 1:
		return 3;
		break;
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 7;
		break;
	case 4:
		return 8;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7: // some cases here are not possible at all ( no 80-th minute or second), but are covered anyway
	case 8:
	case 9:
		return 5;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
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

	ncplane_cursor_move_yx(stdplane, 50, 0);
	ncinput ni;
	uint32_t c;
	while(1){
		time_t t = time(NULL);
		local = localtime(&t);
		/* sleep(1); */
		unsigned int y = 0 , x =0;
		notcurses_stddim_yx(nc, &y, &x);
		unsigned y_center = y / 3 + 1;
		unsigned x_center = x / 3;


		if ( x <= 70){ // handling windows resizing
			x_center = 0;
		}
		if ( y < 15){
			y_center = 0;
		}

		clear_prev_screen(stdplane);

		int x_offset = x_center; /// beggining

		table[first_digit((local->tm_hour))](stdplane, x_offset , y_center);
		x_offset = calculate_offset(first_digit(local->tm_hour),last_digit(local->tm_hour)) + x_center;
		table[last_digit((local->tm_hour))] (stdplane, x_offset, y_center);

		x_offset = x_offset + offset_before_twodots(last_digit(local->tm_hour));
		table[TWO_DOTS](stdplane,x_offset, y_center);
		x_offset = x_offset + offset_after_twodots(first_digit(local->tm_min));

		table[first_digit((local->tm_min))](stdplane, x_offset , y_center);
		x_offset = x_offset + calculate_offset(first_digit(local->tm_min),last_digit(local->tm_min));
		table[last_digit((local->tm_min))] (stdplane, x_offset, y_center);

		x_offset = x_offset + offset_before_twodots(last_digit(last_digit(local->tm_min)));;
		table[TWO_DOTS](stdplane, x_offset, y_center);
		x_offset = x_offset + offset_after_twodots(first_digit(local->tm_sec));;

		table[first_digit((local->tm_sec))](stdplane, x_offset , y_center);
		x_offset = x_offset + calculate_offset(first_digit(local->tm_sec),last_digit(local->tm_sec));
		table[last_digit((local->tm_sec))] (stdplane,  x_offset , y_center);

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
