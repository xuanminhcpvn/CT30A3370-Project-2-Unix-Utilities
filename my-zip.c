#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // Exit(1) if no input files are provided.
    if (argc < 2)
    {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        exit(1);
    }
    FILE *f_ptr = NULL;
    int iCurrent, iCount = 0;
    int iPrevious = EOF;
    for (int i = 1; i < argc; i++)
    {
        f_ptr = fopen(argv[i], "r");

        if (f_ptr == NULL)
        {
            fprintf(stderr, "my-zip: cannot open file\n");
            exit(1);
        }

        /* So the program logic is like: 
        read character
        compare with previous
        update counter
        write (count, character)
        */
        while ((iCurrent = fgetc(f_ptr)) != EOF) //Here iCurrent is updated
        {
            /* Matching a character first time*/
            if (iPrevious == EOF)
            {
                iPrevious = iCurrent;
                iCount = 1;
            }
            /* Same character: increase count*/
            else if (iCurrent == iPrevious)
            {
                iCount++;
            }
            /* Different character => save previous character result*/
            else
            {
                fwrite(&iCount, sizeof(int), 1, stdout);

                char cCharacter = (char)iPrevious;
                fwrite(&cCharacter, sizeof(char), 1, stdout);

                iPrevious = iCurrent;
                iCount = 1;
            }
        }

        fclose(f_ptr);
    }

    /* As usual when using while: Running last run*/
    if (iPrevious != EOF)
    {
        fwrite(&iCount, sizeof(int), 1, stdout);

        char cCharacter = (char)iPrevious;
        fwrite(&cCharacter, sizeof(char), 1, stdout);
    }

    //printf("\n");
    return 0;
}