#include "cutFuncs.h"

// Function to check if a string contains only digit or not
// Loop through each character and use isdigit() function to verify for digit.
int isDigit(const char *s)
{
		while (*s) {
			if (isdigit(*s++) == 0) { 
				return 0;
			}
		}
		return 1;
}

// Function to check the input field
int fieldCheck (int argc, char *argv[]) {
	int num[argc];		// Array of integers, used to check if the input field is repeated or not
	
	// Loop through each input field in the arguments
	for (int i = 3; i < argc; i++) {
	
		// Get the value of the current field and the next field
		char* value = argv[i];
		char* nextValue = argv[i+1];
		
		
		// Check if the input field is a number or not (Input field must be a number)
		if (!isDigit(value)) {
			return 1;
		}

		// Check if the input field is in ascending order or not (Input field must be in ascending order)
		// Convert the values of fields that we got above into integers to compare
		if (i < argc-1) {
			int intValue = atoi(value);
			int intNextValue = atoi(nextValue);
			if (intValue > intNextValue) {
				return 1;

			// Check if the input field is repeated or not (Input field cannot be repeated)
			// Loop through the int array num[] declared above to see if the current field is already in the array or not
			// If found an equal value => Repeated value => error 1. Otherwise, no error and append the value into the array
			} else {
				for (int j = 0; j <= argc; j++) {
					if (num[j] == intValue) {
						return 1;
					}
				}
				num[i] = intValue;
			}
		}
	}
	return 0;
}

// Main input error checking function
int inputError (int argc, char *argv[]) {
	// Error checking:
	// Case 1: the number of argument must be >= 4 and <= 103.
	if (argc > 103 || argc < 4) {
		return 1;

	// Case 2: The length of the input and output delimiter should be 1.
	} else if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1) {
		return 1;

	// Case 3: The input and output delimiter must be a character (cannot be a digit).
	} else if (isDigit(argv[1]) || isDigit(argv[2])) {
		return 1;

	// Case 4: All the fields must be number, not char.
	// Case 5: All the fields must be in increasing order.
	// Case 6: All the fields cannot be repeated.
	} else if (fieldCheck(argc, argv) == 1) {
		return 1;
	} else {
		return 0;
	}

}

// Main read file and cut command function
int cutCommand (int argc, char *argv[]) {
	// Declare all the necessary variables
	char line[10000];					// contain the line to be processed for each loop
	char first_field[10000];				// contain of the first field
	char output[10000];					// selected field for the output result
	char input_delimeter = *argv[1];			// input delimeter
	char output_delimeter = *argv[2];			// output delimter
	int fields[argc - 3];					// contain all fields position to be printed out
	int field = 1;						// field always starting from 1
	int index = 0;						// index starts at 0
	int start = 3;						// starting postition to look for fields from *argv[]
	bool check = false;					// the status, true if getting char from desired field and vice versa
	bool firstTime[10000];					// check if this is the first time printing the char

	// get all fields to printed out and store it in fields array
	int temp = 0;
	for (int i = 3; i < argc; i++) {
		fields[temp] = atoi(argv[i]);
		temp++;
	}
	int size = sizeof(fields)/sizeof(fields[0]);

	//process each line of input for each loop
	while (fgets(line, 1000, stdin) != NULL) {
		// initialize the arrays
		temp = sizeof(first_field)/sizeof(first_field[0]);
		for (int i = 0; i < temp; i++){
			first_field[i] = 0;
		}
		temp = sizeof(output)/sizeof(output[0]);
		for (int i = 0; i < temp; i++) {
			output[i] = 0;
		}
		temp = sizeof(firstTime)/sizeof(firstTime[0]);
		for (int i = 0; i < temp; i++) {
			firstTime[i] = false;
		}

		// values to be reseted every new line
		field = 1;
		index = 0;
		check = false;
		start = 3;
		// loop through each character of a line
		for (int i = 0; i < strlen(line) + 1; i++) {
			// loop starting at 3 or last field postion
			for (int j = start; j < argc; j++) {
				// check if this is the field the user want to printed out
				if (field == atoi(argv[j])) {
					// check if there is any char at the current position 
					// if not, store the output delimeter here
					if (firstTime[j] == false && check){
						// set the start point of the loop at the current field position where all char in the field has been obtained
						start = j;
						output[index] = output_delimeter;
						index += 1;
					}
					// check if the character in this desired file is input delimeter
					// if not, store the char in the output array
					if (line[i] != input_delimeter) {
						output[index] = line[i];
						index += 1;
					}
					// set to true if we are in the middle between input delimeter and collecting char
					check = true;
					// set to true if there is no char at this position before
					firstTime[j] = true;
				}
			}
			// special case
			// stores the char in the first field
			if (field == 1) {
				first_field[i] = line[i];
			}
			// if meet the input delimeter, move on to next field
			if (line[i] == input_delimeter) {
				field += 1;
				// if field position has surpassed the max field provided by the user
				// then stop
				if (field > fields[size - 1]) {
					break;
				}
			}
		}
		// print out the string collected for the desired field
		printf("%s", output);
		if (field == 1 && fields[0] != 1) {
			printf("%s", first_field);
		}
		if (field != 1 && output[strlen(output) - 1] != '\n') {
			printf ("\n");
		}
	}
	exit(0);
}