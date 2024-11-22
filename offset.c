#include "offset.h"
#include <stdarg.h>

int
first_digit(int num){
	int digit = num / 10;
	return digit;
}

int
last_digit(int num){
	int digit = num % 10;
	return digit;
}

#define DIG2EQ(DIG) digit_2 == (DIG) // with the introduction of generation of offset functions, this macro and is_in_set should be obsolete

// check if digit num is equal to any of the given variadic args
int is_in_set(int num, int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int current = va_arg(args, int);
        if (current == num) {
            va_end(args);
            return 1;
        }
    }
    va_end(args);
    return 0;
}

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
				return 7;
		case 1:
				return 4;
		case 2:
				return 7;
	    case 3:
			 if(digit_2 == 4) return 8;
			 else return 7;
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
	case 7:
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
			if(digit_2 == 3)
				return 5;
			else return 4;
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
		return 4;
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
	case 7:
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
			if(DIG2EQ(1))
			   return 8;
			   else return 7;
		case 1:
				return 5;
		case 2:
				return 9;
	    case 3:
			 if( DIG2EQ(4) ) return 11;
			 else return 9;
	    case 4:
			if(is_in_set(digit_2, 3,  3, 7,9))
				return 7;
			else return 8;
	    case 5:
			return 10;
	    case 6:
			if(is_in_set(digit_2,3,  2,3,9))
			   return 8;
			else return 9;
	    case 7:
			if(is_in_set(digit_2, 3, 2, 5, 9))
				return 8;
			else if( DIG2EQ(3))
				return 7;
			else return 9;
	    case 8:
			if(is_in_set(digit_2, 2, 3, 9))
			   return 8;
		   else return 9;

	    case 9:
			if(DIG2EQ(2))
				return 9;
			else return 10;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_lean(int num){
	switch(num){
	case 0:
	case 1:
		return 8;
	case 2:
	case 3:
	case 4:
	case 5:
		return 11;
	case 6:
	case 7:
	case 8:
	case 9:
		return 10;
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
	case 7:
	case 8:
	case 9:
		return 6;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_mono12(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
			return 10;
		case 1:
			if(DIG2EQ(9)) return 9;
			else return 10;
		case 2:
	    case 3:
			if(DIG2EQ(9)) return 9;
			else return 10;
	    case 4:
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			if(DIG2EQ(7) || DIG2EQ(9)) return 9;
			else return 10;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_mono12(int num){
	switch(num){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		return 9;
	case 6:
	case 7:
	case 8:
	case 9:
		return 9;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_mono12(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 8;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_smmono12(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
		case 1:
		case 2:
    	case 3:
			return 7;
	    case 4:
			if(DIG2EQ(3)) return 7;
			else return 6;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			return 6;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_smmono12(int num){
	switch(num){
	case 0:
		return 7;
	case 1:
		return 5;
	case 2:
		return 7;
	case 3:
		return 7;
	case 4:
		return 7;
	case 5:
		return 6;
	case 6:
		return 5;
	case 7:
		return 7;
	case 8:
		return 6;
	case 9:
		return 5;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_smmono12(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 7;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_smscript(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
			if(DIG2EQ(6))
				return 6;
			else return 5;
		case 1:
		case 2:
    	case 3:
			return 5;
	    case 4:
			return 6;
	    case 5:
			return 5;
	    case 6:
			return 6;
	    case 7:
	    case 8:
	    case 9:
			return 6;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_smscript(int num){
	switch(num){
	case 0:
		return 7;
	case 1:
		return 6;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 7;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_smscript(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 4;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_smshadow(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
				return 6;
		case 1:
		case 2:
			return 4;
    	case 3:
			if(is_in_set(digit_2, 3, 0, 1, 6))
				return 4;
			else return 5;
	    case 4:
			if(DIG2EQ(3)) return 7;
			else return 6;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
			return 5;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_smshadow(int num){
	switch(num){
	case 0:
		return 7;
	case 1:
		return 6;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 7;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_smshadow(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 4;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_smslant(int digit_1, int digit_2){
	switch(digit_1){
		case 0:
		case 1:
			if (DIG2EQ(3)) return 5;
			else return 6;
		case 2:
			if(is_in_set(digit_2, 5, 0, 2, 3, 4 ,5))
				return 7;
    	case 3:
			return 7;
	    case 4:
			return 6;
	    case 5:
			return 7;
	    case 6:
			return 6;
	    case 7:
			return 5;
	    case 8:
			return 6;
	    case 9:
			return 6;
	}
		fprintf(stderr,"error, no value is returned\n");
		return 0;
}

int offset_before_twodots_smslant(int num){
	switch(num){
	case 0:
		return 7;
	case 1:
		return 6;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		return 7;
	case 7:
		return 6;
	case 8:
	case 9:
		return 7;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int offset_after_twodots_smslant(int num_after_dots){
	switch(num_after_dots){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 6;
	default:
		fprintf(stderr, " wrong digit");
		return -1;
	}
}

int calculate_offset_eftitalic(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 1:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 7; case 1: return 6; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 4:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 9:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}

int offset_before_twodots_eftitalic(int num){
    switch(num){
        case 0: return 5; case 1: return 5; case 2: return 6; case 3: return 7; case 4: return 7; case 5: return 5;case 6: return 4; case 7: return 4; case 8: return 5; case 9: return 5;
    }
}

int offset_after_twodots_eftitalic(int num){
    switch(num){
        case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;
    }
}

int calculate_offset_larry3d(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 1:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 2:
              switch(digit_2){
                case 0: return 11; case 1: return 11; case 2: return 11; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;         }
        case 3:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 4:
              switch(digit_2){
                case 0: return 12; case 1: return 12; case 2: return 12; case 3: return 12; case 4: return 12; case 5: return 12;case 6: return 12; case 7: return 12; case 8: return 12; case 9: return 12;         }
        case 5:
              switch(digit_2){
                case 0: return 11; case 1: return 11; case 2: return 11; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;         }
        case 6:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10 ; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 7:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 8:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 9:
              switch(digit_2){
                case 0: return 11; case 1: return 11; case 2: return 11; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;         }
    }
}

int offset_before_twodots_larry3d(int num){
    switch(num){
        case 0: return 10; case 1: return 8; case 2: return 11; case 3: return 10; case 4: return 12; case 5: return 11;case 6: return 10; case 7: return 11; case 8: return 10; case 9: return 10;
    }
}

int offset_after_twodots_larry3d(int num){
    switch(num){
        case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;
    }
}

int calculate_offset_graffiti(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 1:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 3:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 4:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 5:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 6:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 7:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 8:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 9:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
	    default: return 10;
    }

}

int offset_before_twodots_graffiti(int num){
    switch(num){
        case 0: return 10; case 1: return 6; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;
    }
}

int offset_after_twodots_graffiti(int num){
    switch(num){
        case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 5; case 7: return 4; case 8: return 4; case 9: return 4;
    }
}

int calculate_offset_madrid(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 3:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 4:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 5:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 6:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 3; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 5; case 8: return 4; case 9: return 4;         }
    }
}

int offset_before_twodots_madrid(int num){
    switch(num){
        case 0: return 4; case 1: return 3; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;
    }
}

int offset_after_twodots_madrid(int num){
    switch(num){
        case 0: return 3; case 1: return 2; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;
    }
}


int calculate_offset_5lineoblique(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 11; case 1: return 11; case 2: return 11; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;         }
        case 1:
              switch(digit_2){
                case 0: return 6; case 1: return 7; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 9; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 3:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 4:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 5:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 6:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 7:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 8:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 9:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
    }
}

int offset_before_twodots_5lineoblique(int num){
    switch(num){
        case 0: return 11; case 1: return 6; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 11;case 6: return 10; case 7: return 9; case 8: return 10; case 9: return 11;
    }
}

int offset_after_twodots_5lineoblique(int num){
    switch(num){
        case 0: return 5; case 1: return 4; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 4; case 9: return 5;
    }
}

int calculate_offset_acrobatic(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 17; case 1: return 18; case 2: return 18; case 3: return 18; case 4: return 18; case 5: return 18;case 6: return 18; case 7: return 18; case 8: return 18; case 9: return 18;         }
        case 1:
              switch(digit_2){
                case 0: return 5; case 1: return 7; case 2: return 8; case 3: return 7; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 11; case 1: return 12; case 2: return 11; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;         }
        case 3:
              switch(digit_2){
                case 0: return 13; case 1: return 13; case 2: return 13; case 3: return 13; case 4: return 13; case 5: return 13;case 6: return 13; case 7: return 13; case 8: return 13; case 9: return 13;         }
        case 4:
              switch(digit_2){
                case 0: return 10; case 1: return 12; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 5:
              switch(digit_2){
                case 0: return 13; case 1: return 14; case 2: return 13; case 3: return 13; case 4: return 13; case 5: return 13;case 6: return 13; case 7: return 13; case 8: return 13; case 9: return 13;         }
        case 6:
              switch(digit_2){
                case 0: return 14; case 1: return 15; case 2: return 14; case 3: return 14; case 4: return 14; case 5: return 14;case 6: return 14; case 7: return 14; case 8: return 14; case 9: return 14;         }
        case 7:
              switch(digit_2){
                case 0: return 12; case 1: return 13; case 2: return 12; case 3: return 12; case 4: return 12; case 5: return 12;case 6: return 12; case 7: return 12; case 8: return 12; case 9: return 12;         }
        case 8:
              switch(digit_2){
                case 0: return 13; case 1: return 14; case 2: return 13; case 3: return 13; case 4: return 13; case 5: return 13;case 6: return 13; case 7: return 13; case 8: return 13; case 9: return 13;         }
        case 9:
              switch(digit_2){
                case 0: return 13; case 1: return 14; case 2: return 13; case 3: return 13; case 4: return 13; case 5: return 13;case 6: return 13; case 7: return 13; case 8: return 13; case 9: return 13;         }
    }
}

int offset_before_twodots_acrobatic(int num){
    switch(num){
        case 0: return 19; case 1: return 9; case 2: return 13; case 3: return 16; case 4: return 14; case 5: return 15;case 6: return 16; case 7: return 16; case 8: return 16; case 9: return 16;
    }
}

int offset_after_twodots_acrobatic(int num){
    switch(num){
        case 0: return 6; case 1: return 8; case 2: return 7; case 3: return 7; case 4: return 6; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;
    }
}

int calculate_offset_avatar(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 1:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 3; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 3:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 4:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 5:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 6:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 7:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 8:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
        case 9:
              switch(digit_2){
                case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 6; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;         }
    }
}

int offset_before_twodots_avatar(int num){
    switch(num){
        case 0: return 8; case 1: return 5; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;
    }
}

int offset_after_twodots_avatar(int num){
    switch(num){
        case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;
    }
}

int calculate_offset_chunky(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 1:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 2:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 3:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 4:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 5:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 6:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 7:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 8:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 9:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
    }
}

int offset_before_twodots_chunky(int num){
    switch(num){
        case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;
    }
}

int offset_after_twodots_chunky(int num){
    switch(num){
        case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;
    }
}

int calculate_offset_cricket(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 1:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 2:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 3:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 4:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 5:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 6:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 7:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 8:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 9:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 10; case 7: return 10; case 8: return 10; case 9: return 10;         }
    }
}

int offset_before_twodots_cricket(int num){
    switch(num){
        case 0: return 11; case 1: return 10; case 2: return 10; case 3: return 11; case 4: return 11; case 5: return 11;case 6: return 11; case 7: return 11; case 8: return 11; case 9: return 11;
    }
}

int offset_after_twodots_cricket(int num){
    switch(num){
        case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7;
    }
}

int calculate_offset_cursive(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 4; case 8: return 3; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 7; case 8: return 6; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 5;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 3; case 3: return 3; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 5; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 5; case 8: return 4; case 9: return 4;         }
    }
}

int offset_before_twodots_cursive(int num){
    switch(num){
        case 0: return 7; case 1: return 5; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 5; case 8: return 7; case 9: return 7;
    }
}

int offset_after_twodots_cursive(int num){
    switch(num){
        case 0: return 4; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;
    }
}

int calculate_offset_doom(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 1:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 3:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 4:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 5:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 6:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 7:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 8:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
        case 9:
              switch(digit_2){
                case 0: return 8; case 1: return 8; case 2: return 8; case 3: return 8; case 4: return 8; case 5: return 8;case 6: return 8; case 7: return 8; case 8: return 8; case 9: return 8;         }
    }
}

int offset_before_twodots_doom(int num){
    switch(num){
        case 0: return 9; case 1: return 7; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;
    }
}

int offset_after_twodots_doom(int num){
    switch(num){
        case 0: return 5; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 5; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;
    }
}

int calculate_offset_drpepper(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 3:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 4:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}
int offset_before_twodots_drpepper(int num){
    switch(num){
        case 0: return 7; case 1: return 5; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7; default: return 5;
    }
}

int offset_after_twodots_drpepper(int num){
    switch(num){
		case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5; default: return 5;
    }
}


int calculate_offset_eftifont(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 3; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 3:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 5; case 9: return 4;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 4; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 5; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 4; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 4; case 9: return 5;         }
    }
}
int offset_before_twodots_eftifont(int num){
    switch(num){
        case 0: return 6; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 6; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 6; case 9: return 6;
    }
}

int offset_after_twodots_eftifont(int num){
    switch(num){
        case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 5;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;
    }
}



int calculate_offset_fourtops(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 3:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 4:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 5:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 6:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
    }
}

int offset_before_twodots_fourtops(int num){
    switch(num){
        case 0: return 8; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 7; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 5; 
    }
}

int offset_after_twodots_fourtops(int num){
    switch(num){
        case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 5; case 7: return 4; case 8: return 5; case 9: return 4; 
    }
}


int calculate_offset_kban(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 4:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 6:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 7:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 8:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 9:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
    }
}

int offset_before_twodots_kban(int num){
    switch(num){
        case 0: return 8; case 1: return 7; case 2: return 7; case 3: return 8; case 4: return 7; case 5: return 8;case 6: return 8; case 7: return 9; case 8: return 8; case 9: return 8; 
    }
}

int offset_after_twodots_kban(int num){
    switch(num){
        case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5; 
    }
}


int calculate_offset_serifcap(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 3:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 4:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}

int offset_before_twodots_serifcap(int num){
    switch(num){
        case 0: return 6; case 1: return 5; case 2: return 6; case 3: return 6; case 4: return 7; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6; 
    }
}

int offset_after_twodots_serifcap(int num){
    switch(num){
        case 0: return 4; case 1: return 5; case 2: return 6; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 5; 
    }
}

int calculate_offset_short(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 3:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 4:
              switch(digit_2){
                case 0: return 4; case 1: return 3; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 3;         }
        case 5:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 6:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 3; case 7: return 4; case 8: return 4; case 9: return 3;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 3; case 7: return 4; case 8: return 4; case 9: return 3;         }
    }
}

int offset_before_twodots_short(int num){
    switch(num){
        case 0: return 3; case 1: return 4; case 2: return 3; case 3: return 3; case 4: return 4; case 5: return 3;case 6: return 3; case 7: return 4; case 8: return 4; case 9: return 3; 
    }
}

int offset_after_twodots_short(int num){
    switch(num){
        case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 4; case 4: return 4; case 5: return 5;case 6: return 5; case 7: return 4; case 8: return 4; case 9: return 4; 
    }
}

int calculate_offset_slscript(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 4;case 6: return 3; case 7: return 4; case 8: return 3; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 5; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 6;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 6; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 5;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 3; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 4; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}

int offset_before_twodots_slscript(int num){
    switch(num){
        case 0: return 7; case 1: return 5; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 6; case 7: return 5; case 8: return 7; case 9: return 5; 
    }
}

int offset_after_twodots_slscript(int num){
    switch(num){
        case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 5; case 7: return 6; case 8: return 5; case 9: return 6; 
    }
}

int calculate_offset_twopoint(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 2; case 7: return 3; case 8: return 2; case 9: return 2;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 3:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 4:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 5:
              switch(digit_2){
                case 0: return 3; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 6:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 7:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 4; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 2; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 3; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 3; case 7: return 4; case 8: return 3; case 9: return 3;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 3; case 7: return 4; case 8: return 3; case 9: return 3;         }
    }
}

int offset_before_twodots_twopoint(int num){
    switch(num){
        case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4; 
    }
}

int offset_after_twodots_twopoint(int num){
    switch(num){
        case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3; 
    }
}

int calculate_offset_usaflag(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 9; case 7: return 9; case 8: return 9; case 9: return 9;         }
        case 1:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 4; case 4: return 4; case 5: return 5;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 10; case 8: return 10; case 9: return 10;         }
        case 3:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 8; case 7: return 9; case 8: return 9; case 9: return 8;         }
        case 4:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 10; case 8: return 10; case 9: return 9;         }
        case 5:
              switch(digit_2){
                case 0: return 9; case 1: return 9; case 2: return 9; case 3: return 9; case 4: return 9; case 5: return 9;case 6: return 8; case 7: return 9; case 8: return 9; case 9: return 8;         }
        case 6:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 9; case 8: return 10; case 9: return 9;         }
        case 7:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 9; case 8: return 10; case 9: return 9;         }
        case 8:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 10; case 8: return 10; case 9: return 9;         }
        case 9:
              switch(digit_2){
                case 0: return 10; case 1: return 10; case 2: return 10; case 3: return 10; case 4: return 10; case 5: return 10;case 6: return 9; case 7: return 10; case 8: return 10; case 9: return 9;         }
    }
}

int offset_before_twodots_usaflag(int num){
    switch(num){
        case 0: return 11; case 1: return 7; case 2: return 12; case 3: return 11; case 4: return 12; case 5: return 11;case 6: return 11; case 7: return 12; case 8: return 11; case 9: return 11; 
    }
}

int offset_after_twodots_usaflag(int num){
    switch(num){
        case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6; 
    }
}

int calculate_offset_wavy(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 4; case 7: return 5; case 8: return 5; case 9: return 4;         }
        case 1:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 4; case 7: return 5; case 8: return 5; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 3:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 3; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 6:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 7:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 3; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 3;         }
        case 9:
              switch(digit_2){
                case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 4; case 5: return 5;case 6: return 4; case 7: return 5; case 8: return 5; case 9: return 4;         }
    }
}

int offset_before_twodots_wavy(int num){
    switch(num){
        case 0: return 6; case 1: return 6; case 2: return 5; case 3: return 4; case 4: return 6; case 5: return 5;case 6: return 6; case 7: return 5; case 8: return 5; case 9: return 6; 
    }
}

int offset_after_twodots_wavy(int num){
    switch(num){
        case 0: return 3; case 1: return 3; case 2: return 4; case 3: return 4; case 4: return 3; case 5: return 4;case 6: return 3; case 7: return 3; case 8: return 4; case 9: return 3; 
    }
}

int calculate_offset_straight(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 1:
              switch(digit_2){
                case 0: return 3; case 1: return 3; case 2: return 3; case 3: return 3; case 4: return 3; case 5: return 3;case 6: return 3; case 7: return 3; case 8: return 3; case 9: return 3;         }
        case 2:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 3:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}

int offset_before_twodots_straight(int num){
    switch(num){
        case 0: return 7; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 7; case 5: return 6;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7; 
    }
}

int offset_after_twodots_straight(int num){
    switch(num){
        case 0: return 2; case 1: return 2; case 2: return 2; case 3: return 2; case 4: return 2; case 5: return 2;case 6: return 2; case 7: return 2; case 8: return 2; case 9: return 2; 
    }
}

int calculate_offset_weird(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 4:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 5:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 6:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 7:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 8:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 9:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 5; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
    }
}

int offset_before_twodots_weird(int num){
    switch(num){
        case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7; 
    }
}

int offset_after_twodots_weird(int num){
    switch(num){
        case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 4; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5; 
    }
}

int calculate_offset_thin(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 1:
              switch(digit_2){
                case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4;         }
        case 2:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 3:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 6:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 7:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 8:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 9:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
    }
}

int offset_before_twodots_thin(int num){
    switch(num){
        case 0: return 7; case 1: return 7; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 7; case 8: return 7; case 9: return 7; 
    }
}

int offset_after_twodots_thin(int num){
    switch(num){
        case 0: return 4; case 1: return 4; case 2: return 4; case 3: return 4; case 4: return 4; case 5: return 4;case 6: return 4; case 7: return 4; case 8: return 4; case 9: return 4; 
    }
}

int calculate_offset_gothic(int digit_1, int digit_2){
    switch(digit_1){
        case 0:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 1:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 2:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 5; case 8: return 5; case 9: return 6;         }
        case 3:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 4:
              switch(digit_2){
                case 0: return 5; case 1: return 5; case 2: return 5; case 3: return 5; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5;         }
        case 5:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 6:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 7:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 8:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
        case 9:
              switch(digit_2){
                case 0: return 6; case 1: return 6; case 2: return 6; case 3: return 6; case 4: return 6; case 5: return 6;case 6: return 6; case 7: return 6; case 8: return 6; case 9: return 6;         }
    }
}

int offset_before_twodots_gothic(int num){
    switch(num){
        case 0: return 8; case 1: return 7; case 2: return 7; case 3: return 7; case 4: return 7; case 5: return 7;case 6: return 7; case 7: return 8; case 8: return 8; case 9: return 8; 
    }
}

int offset_after_twodots_gothic(int num){
    switch(num){
        case 0: return 4; case 1: return 5; case 2: return 5; case 3: return 4; case 4: return 5; case 5: return 5;case 6: return 5; case 7: return 5; case 8: return 5; case 9: return 5; 
    }
}
