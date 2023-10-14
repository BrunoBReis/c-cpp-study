#include <stdio.h>

int main()
{
    FILE *file_contents;
    char letter_in_file;

    int space_count = 0;
    int tab_count = 0;
    int new_line_count = 0;
    int character_count = 0;

    file_contents = fopen("prog1.txt", "r");
    if (file_contents != NULL)
    {
        while (1)
        {
            letter_in_file = fgetc(file_contents);
            if (letter_in_file != EOF)
            {
                if (letter_in_file == ' ')
                {
                    space_count++;
                }
                else if (letter_in_file == '\t')
                {
                    tab_count++;
                }
                else if (letter_in_file == '\n')
                {
                    new_line_count++;
                }
                else
                {
                    character_count++;
                }
            }
            else
            {
                break;
            }
        }
        printf("\n");
        fclose(file_contents);
        printf("spaces in file = %d\ntabs in file =  %d\nnew spaces in file = %d\nchar in file = %d\n", space_count, tab_count, new_line_count,
               character_count);
    }
    else
    {
        printf("File was not found.\n");
    }
    return 0;
}
