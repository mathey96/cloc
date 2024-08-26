#include <time.h>
#include "digits.h"
#include <pthread.h>

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

	ncplane_cursor_move_yx(stdplane, 50, 0);
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
					local->tm_hour, local->tm_min, local->tm_sec, fonts[1]);


		notcurses_render(nc);
	}

}
