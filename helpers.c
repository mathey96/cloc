#include "helpers.h"

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
	case 7: // some cases here are not possible at all ( no 80-th minute or second), but are covered anyway for future possibilities
	case 8:
	case 9:
		return 5;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}
