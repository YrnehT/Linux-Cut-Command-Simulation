#include "cutFuncs.h"
//the first 2 arg should be char
//int with increasing order of size

int main(int argc, char *argv[]){
	// Check to see if there is any input error. If there is an error, exit with exit code 1.
    	if (inputError(argc, argv) == 1) {
        	fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%d fields in order\n", argv[0], arg_limit);
        	exit(1);

	// If there is no error, perform the cut and exit with exit code 0.
    	} else {
		cutCommand(argc, argv);
		exit(0);
    	}
}