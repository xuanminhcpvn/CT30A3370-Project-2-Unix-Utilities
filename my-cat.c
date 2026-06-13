/* Requirement: 
    exit(0) for non-error cases either exit(0) or return 0 from main.c
    if no files are specified => exit + return 0;
    if 1 file = read 1 
    If multiple files are specified on the command line, the files should be printed out in order until the end of the file list is reached or an error opening a file is reached (at which point the error message is printed and my-cat exits).
    If fopen() fails, => message "my-cat: cannot open file\n", exit(1).   
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //No file => success
    if (argc == 1){
        return 0;
    }
    
    char buffer[1024];
    //We don't seem to need dynamic memory allocation since we are not storing any input and we outputted immediately anyway
    //start from 1 since 0 => executable file
    //Repeat line by line read for each file 
    for (int i = 1;i < argc; i++){
        FILE *f_ptr = fopen(argv[i],"r");

        if (f_ptr == NULL) {
            printf("my-cat: cannot open file\n");
            return 1;
        }
        
        while (fgets(buffer, sizeof(buffer), f_ptr) != NULL) {
            printf("%s", buffer);
        }

        fclose(f_ptr);
    }
    

    return 0;
}