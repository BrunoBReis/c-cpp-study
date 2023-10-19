#include <stdio.h>
int main()
{
    // file is a pointer that keeps all information
    // that fopen has
    FILE *file_contents;
    char letter_in_file;

    // opens a file in read-only
    // and stores all informations abou this file
    file_contents = fopen("prog1.txt", "r");
    if (file_contents != NULL)
    {
        while (1)
        {
            // reads in file_contents file char
            letter_in_file = fgetc(file_contents);
            if (letter_in_file == EOF)
                break;
            printf("%c", letter_in_file);
        }
        // after reading and find an EOF's file stop it.
        printf("\n");
        fclose(file_contents);
    }
    else
    {
        printf("Unable to find a file.\n");
        // system("pause");
        // exit(0);
    }
    
    return 0;
}