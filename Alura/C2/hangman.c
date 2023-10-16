#include <stdio.h>
#include <string.h>

int main()
{
    char secret_word[20];

    // this functions does a loop for each char until finds EOF
    sprintf(secret_word, "MELANCIA");

    int guessed_right = 0;
    int hangued = 0;

    char guesses[26];
    int trys = 0;

    do
    {
        for (int i = 0; i < strlen(secret_word); i++)
        {
            int found = 0;
            for (int j = 0; j < trys; j++)
            {
                if (guesses[j] == secret_word[i])
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                printf("%c ", secret_word[i]);
            }
            else
            {
                printf("_ ");
            }
        }

        printf("\n");

        char guess;
        // space before %c ignores enter output
        scanf(" %c", &guess);

        guesses[trys] = guess;
        trys++;

    } while (!guessed_right && !hangued);

    return 0;
}
