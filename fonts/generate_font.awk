#!/usr/bin/awk -f
# -e " 1\n2" | parallel awk -v var1={} -f awktry awktest
# Initialize a line counter
function num_to_string(arguments) {
	if(current_number == 0){
		return number_string = "zero"}
	else if(current_number == 1){
		return number_string = "one"}
	else if(current_number == 2){
		return number_string = "two"}
	else if(current_number == 3){
		return number_string = "three"}
	else if(current_number == 4){
		return number_string = "four"}
	else if(current_number == 5){
		return number_string = "five"}
	else if(current_number == 6){
		return number_string = "six"}
	else if(current_number == 7){
		return number_string = "seven"}
	else if(current_number == 8){
		return number_string = "eight"}
	else if(current_number == 9){
		return number_string = "nine"}
	else if(current_number == 10){
		return number_string = "twodots"}
}

BEGIN {
    line_number = 1
	{print ""} {print}
	max_vector_size = 0;
	current_number = -1
	flag = 0
}



# Process each line
{
	number = 0
    # If the line is not blank, prepend the line number
    if (length($0) > 0) {
		if( flag_still_parsing_digit == 0 && current_number < 10){
			current_number = current_number +1
			flag_still_parsing_digit = 1
		}
			flag_still_parsing_digit = 1
			max_vector_size = (line_number > max_vector_size) ? line_number : max_vector_size
			printf "const char* const %s_%s_%d = \"%s\\n\";\n",var1, num_to_string(current_number), line_number, $0, max_vector_size
			line_number++
    }
    # For blank lines, just print them as they are
    else {
		if(current_number < 10){
		flag_still_parsing_digit = 0
		print ""
        line_number = 1
		}
		else if (current_number >= 10 && line_number <= max_vector_size){
			printf "const char* const %s_%s_%d = \"%s\\n \";\n",var1, num_to_string(current_number), line_number, $0, max_vector_size
			line_number++
		}
    }
}
