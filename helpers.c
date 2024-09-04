#include "helpers.h"


int calculate_offset_mono9(int digit_1, int digit_2){
		switch(digit_1){
			case (0):
					return 8;
			case (1):
				if ( digit_2 == 7)
					return 5;
				else return 6;
			case (2):
				if(digit_2 == 0 || digit_2 == 8 || digit_2 == 9)
					return 8;
				else return 7;
			case (3):
				if (digit_2 == 0 || digit_2 == 1 || digit_2 == 9)
					return 8;
				else return 7;
			case (4):
				if(digit_2 == 0 || digit_2 == 1 || digit_2 == 9)
					return 8;
				else return 7;
			case (5):
				if(digit_2 == 2 || digit_2 == 4 || digit_2 == 7)
					return 7;
				else return 8;
			case (6):
				if(digit_2 == 2 || digit_2 == 4 || digit_2 == 7)
					return 7;
				else return 8;
			case (7):
				if(digit_2 == 2 || digit_2 == 4 || digit_2 == 7)
					return 7;
				else return 8;
			case (8):
				if(digit_2 == 2 || digit_2 == 7)
					return 7;
				else return 8;
			case (9):
				if(digit_2 == 2 || digit_2 == 7)
					return 7;
				else return 8;

		default:
			return 0;
		}
}


int offset_before_twodots_mono9(int num){
	switch(num){
	case 0:
		return 7;
		break;
	case 1:
		return 5;
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

int offset_after_twodots_mono9(int num_after_dots){
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

int calculate_offset_standard(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
			if(digit_2 >= 0 || digit_2 < 10)
				return 7;
		case 1:
			if((digit_2 >= 2 && digit_2 < 10) || digit_2 == 0)
				return 4;
			else if(digit_2 == 1)
				return 4;
		case 2:
			if((digit_2 >= 2 && digit_2 < 10) || digit_2 == 0)
				return 7;
	    case 3:
			 if((digit_2 >= 0 && digit_2 < 4) || (digit_2 >4 && digit_2 < 10))
				 return 7;
			 else if(digit_2 == 4)
				 return 8;
	    case 4:
			return 8;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			return 7;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}


int offset_before_twodots_standard(int num){
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

int offset_after_twodots_standard(int num_after_dots){
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


int calculate_offset_mini(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
		case 1:
				return 3;
		case 2:
			if((digit_2 >= 2 && digit_2 < 10) || digit_2 == 0)
				return 3;
	    case 3:
			 if(digit_2 >= 0  )
				 return 3;
	    case 4:
			return 3;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			return 3;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}



int offset_before_twodots_mini(int num){
	switch(num){
	case 1:
		return 3;
		break;
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 4;
		break;
	case 4:
		return 3;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_mini(int num_after_dots){
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
		return 2;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_lean(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
		case 1:
				return 7;
		case 2:
			if((digit_2 >= 2 && digit_2 < 10) || digit_2 == 0)
				return 7;
	    case 3:
			 if(digit_2 >= 0  )
				 return 7;
	    case 4:
			return 7;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			return 7;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}



int offset_before_twodots_lean(int num){
	switch(num){
	case 1:
		return 6;
		break;
	case 0:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 9;
		break;
	case 4:
		return 8;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_lean(int num_after_dots){
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
		return 10;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}
