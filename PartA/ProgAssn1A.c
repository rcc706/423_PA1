#include <stdio.h>

// Allows dynamic memory management
#include <stdlib.h>

// Allows isspace() function
#include <ctype.h>

// main: driver
void main(int argc, char * argv[]) {

	// Files
	FILE *fp_in;
	FILE *fp_out; 

	// Holds current character from input file
	char hold; 

	// Checks if the number of arguments is valid
	if (argc != 3) {
		printf("Please provide the input and output text file names as %s inputFileName outputFileName\n", argv[0]);
		return; 
	}

	// Checks if the input file exists
	if ((fp_in = fopen(argv[1], "r")) == NULL) {
		printf("Input file %s cannot be opened\n", argv[1]); 
		return; 
	}

	// Checks if the output file exists
	if ((fp_out = fopen(argv[2], "w")) == NULL) {
		printf("Output file %s cannot be opened\n", argv[2]); 
		return; 
	}
	
	// Reading the characters from the input file
	printf("The integers in file %s:\n", argv[1]);
	while (hold != EOF) {

		// Checks if the end of the file has been reached
		hold = fgetc(fp_in);
		if (hold == EOF)
			break; 

		// Checks if the read character is NOT a space
		// Prints and writes the character to the terminal and the output file respectively
		if (!(isspace(hold))) {
			printf("%c ", hold); 
			fputc(hold, fp_out);
			fputc(' ', fp_out);  
		}
	}
	// Readability in terminal
	printf("\n"); 

	// Closing the Files
	fclose(fp_in); 
	fclose(fp_out); 
} // main