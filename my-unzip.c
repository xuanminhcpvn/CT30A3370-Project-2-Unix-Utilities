#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Exit(1) if no input files
    if (argc < 2)
    {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
    FILE *f_ptr = NULL;
    int iCount;
    char cCurrent;
    for (int i = 1; i < argc; i++)
    {
        f_ptr = fopen(argv[i], "rb");  // for .z file
        if (f_ptr == NULL) {
            fprintf(stderr, "my-unzip: cannot open file\n");
            exit(1);
        }
        
        while (fread(&iCount, sizeof(int), 1, f_ptr) == 1 && fread(&cCurrent, sizeof(char), 1, f_ptr) == 1){//Read iCount + cChracter pair
            for (int i = 0; i < iCount; i++){
                printf("%c", cCurrent);
            }
        }
        fclose(f_ptr);
    }
    return 0;
}