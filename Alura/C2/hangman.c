#include <stdio.h>
#include <string.h>

void opening();
void guessing(char guesses[], int tries);

int main()
{

    opening();

    char secret_word[20];

    // this functions does a loop for each char until finds EOF
    // and returns MELANCIA to secret_word;
    sprintf(secret_word, "MELANCIA");

    // conditionals to play the game
    int guessed_right = 0;
    int hangued = 0;

    // creating an array of guess (26 all characters in alfabet)
    char guesses[26];
    // number of tries
    int tries = 0;

    do
    {
        // loop to all characters in secret_word
        for (int i = 0; i < strlen(secret_word); i++)
        {
            // creating an flag to every time there is a guess in guesses words
            int found = 0;
            // loop to all guesses words (if it is the first time running the program this loop doesn't go)
            for (int j = 0; j < tries; j++)
            {
                if (guesses[j] == secret_word[i])
                {
                    // if one word was found that's enough
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
        
        guessing(guesses, tries);

        // adding a new try
        tries++;

    } while (!guessed_right && !hangued);

    return 0;
}

void opening()
{
    printf("/****************/\n");
    printf("/* Hangman game */\n");
    printf("/****************/\n\n");
}

void guessing(char guesses[], int tries)
{
    char guess;
    // space before %c ignores enter output
    scanf(" %c", &guess);

    guesses[tries] = guess;
}