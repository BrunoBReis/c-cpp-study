#include <stdio.h>
#include <string.h>

void opening();
void guessing(char guesses[], int *tries);
int already_guess(int tries, char *guesses, char letter);
void prints_hangman(char *secret_words, char *guesses, int tries);
void set_word();

int main()
{

    opening();

    char secret_word[20];
    set_word(secret_word);

    // conditionals to play the game
    int guessed_right = 0;
    int hangued = 0;

    // creating an array of guess (26 all characters in alfabet)
    char guesses[26];
    
    // number of tries
    int tries = 0;

    do
    {
        prints_hangman(secret_word, guesses, tries);
        printf("\n");

        // both guesses and tries are pointeres. But an array this is automatic
        guessing(guesses, &tries);
    } while (!guessed_right && !hangued);

    return 0;
}

void opening()
{
    printf("/****************/\n");
    printf("/* Hangman game */\n");
    printf("/****************/\n\n");
}

void guessing(char *guesses, int *tries)
{
    char guess;
    scanf(" %c", &guess); // space before %c ignores enter output

    guesses[*tries] = guess;
    (*tries)++;
}

int already_guess(int tries, char *guesses, char letter)
{
    // creating an flag to every time there is a guess in guesses words
    int found = 0;

    // loop to all guesses words (if it is the first time running the program this loop doesn't go)
    for (int j = 0; j < tries; j++)
    {
        if (guesses[j] == letter)
        {
            // if one word was found that's enough
            found = 1;
            break;
        }
    }

    return found;
}

void prints_hangman(char *secret_word, char *guesses, int tries)
{

    // loop to all characters in secret_word
    for (int i = 0; i < strlen(secret_word); i++)
    {

        int found = already_guess(tries, guesses, secret_word[i]);

        if (found)
        {
            printf("%c ", secret_word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

void set_word(char *secret_word)
{

    // this functions does a loop for each char until finds EOF
    // and returns MELANCIA to secret_word;
    sprintf(secret_word, "MELANCIA");
}