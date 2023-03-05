# Cat Command

This program is a simplified implementation of the "cat" command found in
 most Linux/Unix systems. It reads one or more files from the command line,
   and outputs their contents to the console. If the -n flag is provided as a
   command line argument, the output will be numbered line by line.
   
   To compile and build this program, use the following command:
   gcc -Wall -Wextra -O2 -g -o my_cat my_cat.c

   Usage: ./my_cat [-n] <filename> [filename2 ...]

   Example: ./my_cat -n myfile.txt myfile2.txt

   Note: This program assumes that the files to be read exist in the current
   directory and are readable by the user running the program. If a file cannot
   be opened or does not exist, an error message will be printed to the console.
