#include <time.h>
#include "digits.h"
#include "helpers.h"

#define TWO_DOTS 10


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
