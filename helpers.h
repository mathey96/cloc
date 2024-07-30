#include <stdio.h>

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

int calculate_offset(int digit_1, int digit_2);
int offset_before_twodots(int num);
int offset_after_twodots(int num_after_dots);
