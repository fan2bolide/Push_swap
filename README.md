# Push_swap

Here is a new 42 project : Push_swap

Disclaimer : This project is not finished yet

here you can try it for now by doing make in the repo and ./push_swap <int args>.
	Example : ./push_swap 1 2 3 4 5
That command will give you the instructions to follow to get the stack sorted.

If you're putting less than 10 numbers, it will apply a quick sort for little sizes.

If the number of arguments you give to the program is 10 or greater,
my program will apply a radix sort based on binary digits.
This sorting algorithm is efficient for high number of argument, and is an easy way
to implement a sort based on two stacks with limited instruction set.

This project comes with a visualizer so you could be testing an algorithm written
with the instruction set of push_swap. (not working for now)

ERROR CHECK : 
The program will check your entries and display 'error' if : 
- the entry cant go into an int (4B);
- the entry is not convertible into a number (ex : ./push_swap 1 2 three 4);
- the entry contains other symbols than '0' '1' '2' '3' '4' '5' '6' '7' '8' '9' ' ' '+' '-';