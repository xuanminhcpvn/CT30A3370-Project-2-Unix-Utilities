/* Requirement: 
    exit(0) for non-error cases either exit(0) or return 0 from main.c
    if no files are specified => exit + return 0;
    if 1 file = read 1 
    If multiple files are specified on the command line, the files should be printed out in order until the end of the file list is reached or an error opening a file is reached (at which point the error message is printed and my-cat exits).
    If fopen() fails, => message "my-cat: cannot open file\n", exit(1).   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    //Not enough arguments
    char *line_ptr = NULL;
    
    if (argc < 2) {
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        return 1;
    }
    
    const char *search_term = argv[1];

    // input from stdin
    if (argc == 2) {
        //string comparison logic
        return 0;
    }

    // otherwise
    for (int i = 2; i < argc; i++) {
        FILE *f_ptr = fopen(argv[i], "r");
        if (f_ptr == NULL) {
            fprintf(stderr, "my-grep: cannot open file\n");
            exit(1);
        }
        //Some read line and string comparison logic here later
        fclose(f_ptr);
    }
    

    return 0;
}