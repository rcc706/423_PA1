//----------------Headers and Methods------------------

#include <stdio.h>

// Allows dynamic memory management
#include <stdlib.h>

// Allows isspace() function
#include <ctype.h>

// Node Structure
struct Node {
	int value; 
	struct Node *next; 
} Node;

// insert: inserts the parameter into the linked list
void insert(struct Node *); 

// Initializing Linked List Head as NULL
struct Node * head = NULL; 

// main: driver
void main(int argc, char * argv[]) {
//----------------Variables and Checks-----------------

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

//------------------Memory Allocation------------------

	// Dynamic Memory Allocation
	struct Node * node = (struct Node*) malloc(sizeof(struct Node)); 

	// Checking if memory allocation is successful
	if (node == NULL) {
		printf("Cannot do dynamic memory management\n"); 
		return; 
	}

//-----------------------Sorting-----------------------
	
	// Reading the characters from the input file
	while (hold != EOF) {

		// Checks if the end of the file has been reached
		hold = fgetc(fp_in);
		if (hold == EOF)
			break; 

		// Checks if the read character is NOT a space
		if (!(isspace(hold))) {
			// Set nodes' value to current char
			node->value = (int)hold; 
			
			// Initialize member variable next value to NULL
			node->next = NULL; 

			// Insert node into the list
			insert(node); 

			// Memory Allocation
			node = (struct Node*) malloc(sizeof(struct Node)); 

			// Check if Memory Allocation was successful
			if (node == NULL) {
				printf("Cannot do dynamic memory management\n");
				return; 
			} // nested-if
		} // if
	} // while

	// Free memory space to node
	free(node);

	// Readability in terminal
	printf("\nThe integers in file %s after sorting:\n", argv[1]); 

	// Traverse the linked list until head is NULL
	while (head != NULL) {
		node = head; 
		head = head->next; 

		printf("%c ", node->value); 
		fputc(node->value, fp_out); 
		fputc(' ', fp_out); 

		free(node); 
	}

	// Readability in terminal
	printf("\n"); 

//----------------------Closing Files------------------

	// Closing the Files
	fclose(fp_in);
	fclose(fp_out);
} // main

// insert: inserts the parameter into the linked list
void insert(struct Node * element) {
//-----------------------Variables---------------------
	
	// temp = current : pretemp = before temp
	struct Node * temp = head; 
	struct Node * pretemp = NULL; 

//-----------------Traversing Linked List--------------

	// Reach end of the list or current value <= elements' value
	while (temp != NULL && temp->value < element->value) {
		// Move 2 temp variables to check next char in Linked List
		pretemp = temp;
		temp = temp->next; 
	}

//-----------------------Checking----------------------

	// Check if element can be inserted at the beginning of the Linked List
	if (pretemp == NULL) {
		// Yes: Insert element at beginning of Linked List
		element->next = head;
		head = element; 
	}
	else {
		// No: Insert element between chars pointed by pretemp and temp
		pretemp->next = element;
		element->next = temp; 
	}
} // insert