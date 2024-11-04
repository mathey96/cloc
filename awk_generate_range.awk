# run with awk -f awk_generate_range.awk -F "_" range_test_sorted
BEGIN {
    # Initialize the previous digit as empty
    prev_digit_return = ""
	prev_digit_range = ""
	range_lower = ""
	range_upper = ""
	in_range = 1;
	delete stack #initialize stack
	top = 0

}

function print_stack() {
    print "Stack contents:"
    for (i = 1; i <= top; i++) {
        print stack[i]
    }
}
function push(element) {
    top += 1                # Move the top pointer up
    stack[top] = element    # Add the new element to the stack
}

{
	if(NR == 1){
		prev_digit_range = $3 # initialize
		stack[0] = $3
		push(prev_digit_range)
	}
    # Extract the first digit (field 1) from the line
    current_digit_return = $1
    current_digit_range = $3

    # Compare current digit with the previous digit
    if (prev_digit_return != "" && current_digit_return != prev_digit_return) {
        print "Digit changed from", prev_digit_return, "to", current_digit_return
    }
	if ( prev_digit_range + 1 == current_digit_range){
		print "Digit range:", current_digit_range
		in_range = 1
		}
	else {
		in_range = 0

		}

	if(in_range == 1){
		push(current_digit_range)
		for (key in stack){
			print_stack()

		   }
	}

    # Update the previous digit to the current one
		 prev_digit_range = current_digit_range
		 prev_digit_return = current_digit_return
}
