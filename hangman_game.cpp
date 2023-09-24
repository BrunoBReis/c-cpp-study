#include <iostream>
#include <string>
#include <map>      // dictionary library
#include <vector>   // dinamic list library
#include <fstream>  // files library
#include <ctime>    // seed for random
#include <cstdlib>  // random 
using namespace std;

// global variables
const string SECRET_WORD = "MELANCIA";
map<char, bool> guessed;
vector<char> wrong_guess;

bool word_verify(char guess);
bool word_verify_new(char guess);
bool verify_vector(char guess, vector<char> name);
bool dont_get_right();
bool dont_hangman();
void screen_game();
void show_wrong_guesses();
void show_word_size();
void get_word();
void end_game_message();
void read_file();
void randomize_words();

int main()
{

    screen_game();

    read_file("words.txt");

    cout << SECRET_WORD << endl;

    // bool dont_get_right = true;
    // bool dont_hangman = true;

    // creating a loop for the game
    while (dont_get_right() && dont_hangman())
    {

        // print wrong letters

        show_wrong_guesses();

        cout << endl;

        // print word's size and letters complete

        show_word_size();

        cout << endl;

        cout << "What is your guess? ";

        get_word();
    }

    cout << "End game." << endl;

    end_game_message();

    return 0;
}

bool word_verify(char guess)
{
    // verify input letter in SECRET_WORD
    for (int i = 0; i < SECRET_WORD.size(); i++)
    {
        if (guess == SECRET_WORD[i])
        {
            return true;
        }
    }
    return false;
}

bool word_verify_new(char guess)
{
    // verify input letter in SECRET_WORD with new formatation
    for (char letter : SECRET_WORD)
    {
        if (guess == letter)
        {
            return true;
        }
    }
    return false;
}

bool verify_vector(char guess, vector<char> name)
{
    // verify if letter was alredy store in vector
    for (int i = 0; i < name.size(); i++)
    {
        if (guess == name[i])
        {
            return false;
        }
    }
    return true;
}

bool dont_get_right()
{
    // verify if all word was written
    for (int i = 0; i < SECRET_WORD.size(); i++)
    {
        if (!guessed[SECRET_WORD[i]])
        {
            return true;
        }
    }
    return false;
}

bool dont_hangman()
{
    // verify all tries
    if (wrong_guess.size() < 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void screen_game()
{
    // print screen game note
    cout << "********************" << endl;
    cout << "*** Hangman game ***" << endl;
    cout << "********************" << endl;
    cout << endl;
}

void show_wrong_guesses()
{
    // show all wrong guesses
    cout << "Wrong guesses: " << endl;
    for (int i = 0; i < wrong_guess.size(); i++)
    {
        cout << wrong_guess[i] << " ";
    }
}

void show_word_size()
{
    // show word's size
    for (int i = 0; i < SECRET_WORD.size(); i++)
    {
        if (guessed[SECRET_WORD[i]])
        {
            cout << SECRET_WORD[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
}

void get_word()
{
    // get word from user and verifies it
    char guess;
    cin >> guess;

    guess = toupper(guess);

    guessed[guess] = true;

    cout << "Your guess was " << guess << endl;

    // verify input letter
    if (word_verify_new(guess))
    {
        cout << "You guessed right!" << endl;
    }
    else
    {
        cout << "You guessed wrong." << endl;
        if (verify_vector(guess, wrong_guess))
        {
            wrong_guess.push_back(guess);
        }
        else
        {
            cout << "This letter was already used. " << endl;
        }
    }
    cout << endl;
}

void end_game_message()
{
    // end game message
    if (dont_get_right())
    {
        cout << "Try again" << endl;
        cout << "The secret word is " << SECRET_WORD << "!" << endl;
    }
    else
    {
        cout << "Congrats! The secret word is " << SECRET_WORD << "." << endl;
    }
}

vector<string> read_file(string file_name)
{
    ifstream file;

    file.open(file_name);

    int count_words;
    file >> count_words;


    vector<string> words;

    for (int i = 0; i < count_words; i++)
    {
        string word;
        file >> word;
        words.push_back(word);
    }
    return words;
}

void randomize_words()
{
    vector<string> words = read_file("words.txt"); // is this some kind of polimorfism?

    srand(time(NULL));

    int sort;
    sort = rand() % words.size();
    

}