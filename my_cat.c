// Description: This program reads a file and prints its content to the screen.
//              It is similar to the cat command in Linux.

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if a file name was provided
    if (argc == 1) {
            printf("No file name was provided.\n");
            exit(EXIT_FAILURE);
    }

    // Variable to store if the user wants to print the line numbers
    // If the user wants to print the line numbers, the value is 1
    // If the user does not want to print the line numbers, the value is 0
    int line_number = (strcmp(argv[1], "-n") == 0) ? 1 : 0;

    // Variable to store the index of the first file
    // If the user wants to print the line numbers, the index is 2
    int i = (line_number == 1) ? 2 : 1;

    // Read the file(s) provided
    for (; i < argc; i++) {
        // Open the file
        FILE* fp = fopen(argv[i], "r");

        // Check if current file exists
        if (fp == NULL) {
            printf("File %s does not exist\n", argv[i]);
            exit(EXIT_FAILURE);
        }       
        
        // Variable to store the current character
        int c;

        // Reset the line number if the user wants to print the line numbers for each file
        line_number = (line_number >= 1) ? 1 : 0; 

        // Print the the first line number if the user wants to print the line numbers
        if (line_number == 1) {
            printf("1 ");
        }
        
        // Read the file character by character
        while ((c = fgetc(fp)) != EOF) {
            // Check for errors
            if (ferror(fp)) {
                printf("Error while reading file\n");
                exit(EXIT_FAILURE);
            }

            // Print the character
            putchar(c);      

            // Print the line number if the user wants to print the line numbers
            if (c == '\n' && line_number >= 1) {
                printf("%d ", ++line_number);
            }

        }          
        
        printf("\r");

        // Close the file
        fclose(fp);
    }


    // Exit the program
    exit(EXIT_SUCCESS);
}
