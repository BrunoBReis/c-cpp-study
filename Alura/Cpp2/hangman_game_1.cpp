// needs to comment all functions

#include <iostream>
#include <string>
#include <map>     // dictionary library
#include <vector>  // dinamic list library
#include <fstream> // files library
#include <ctime>   // seed for random
#include <cstdlib> // random
using namespace std;

// global variables
string secret_word = "MELANCIA";
map<char, bool> guessed;
vector<char> wrong_guess;
const string file_name = "words.txt";

bool letter_verify(char guess);
bool letter_verify_new(char guess);
bool letter_verify_vector(char guess, vector<char> name);
bool dont_get_right();
bool dont_hangman();
void screen_game();
void show_wrong_guesses();
void show_word_size();
void get_word();
void end_game_message();
vector<string> read_file();
void randomize_words();
void add_word();
string upper_string(string word);
bool word_verifier(string word, string word_to_verify);
bool verify_word_in_database(vector<string> vector, string new_word);
void save_file(vector<string> new_list);

int main()
{

    screen_game();

    read_file();
    randomize_words();

    cout << secret_word << endl;

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

bool letter_verify(char guess)
{
    // verify input letter in secret_word
    for (int i = 0; i < secret_word.size(); i++)
    {
        if (guess == secret_word[i])
        {
            return true;
        }
    }
    return false;
}

bool letter_verify_new(char guess)
{
    // verify input letter in secret_word with new formatation
    for (char letter : secret_word)
    {
        if (guess == letter)
        {
            return true;
        }
    }
    return false;
}

bool letter_verify_vector(char guess, vector<char> name)
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
    for (int i = 0; i < secret_word.size(); i++)
    {
        if (!guessed[secret_word[i]])
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
    for (int i = 0; i < secret_word.size(); i++)
    {
        if (guessed[secret_word[i]])
        {
            cout << secret_word[i] << " ";
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
    if (letter_verify(guess))
    {
        cout << "You guessed right!" << endl;
    }
    else
    {
        cout << "You guessed wrong." << endl;

        // verifies if guess was already in guessed letters
        if (letter_verify_vector(guess, wrong_guess))
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
        cout << "The secret word is " << secret_word << "!" << endl;
    }
    else
    {
        cout << "Congrats! The secret word is " << secret_word << "." << endl;

        cout << "You want to add a new word to database?[y/n]" << endl;

        char answer;
        cin >> answer;
        answer = toupper(answer);

        // adds answer to data base or note
        if (answer == 'Y')
        {
            add_word();
        }
        else
        {
            exit(0);
        }
    }
}

vector<string> read_file()
{
    // opens files and add a string from data base

    ifstream file; // type of variable that reads files

    file.open(file_name);

    if (file.is_open())
    {
        int count_words;
        file >> count_words;

        vector<string> words_file;

        for (int i = 0; i < count_words; i++)
        {
            string word;
            file >> word;
            words_file.push_back(word);
        }

        file.close();
        return words_file;
    }
    else
    {
        cout << "File was not found." << endl;
        exit(0);
    }
}

void randomize_words()
{
    // get all words in read_file() and puts in secret_word

    vector<string> words = read_file(); // is this some kind of polimorfism?

    srand(time(NULL));

    int sort;
    sort = rand() % words.size();

    secret_word = words[sort];
}

void add_word()
{

    vector<string> words = read_file();

    while (true)
    {
        cout << "Type a new word" << endl;
        string new_word;
        cin >> new_word;

        new_word = upper_string(new_word);

        if (verify_word_in_database(words, new_word))
        {
            words.push_back(new_word);
            break;
        }
        else
        {
            continue;
        }
    }
    save_file(words);
}

string upper_string(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    }

    return word;
}

bool word_verifier(string word, string word_to_verify)
{
    word = upper_string(word);
    word_to_verify = upper_string(word_to_verify);

    if (word.length() == word_to_verify.length())
    {
        int words_lenght = word.length();
        int tries;
        for (int i = 0; i < words_lenght; i++)
        {
            if (word[i] != word_to_verify[i])
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool verify_word_in_database(vector<string> name_list, string new_word)
{

    for (int i = 0; i < name_list.size(); i++)
    {
        if (word_verifier(new_word, name_list[i]))
        {
            cout << "Word is already in database" << endl;
            return false;
        }
    }
    return true;
}

void save_file(vector<string> new_list)
{
    ofstream file;
    file.open(file_name);

    if (file.is_open())
    {
        file << new_list.size() << endl;
        for (int i = 0; i < new_list.size(); i++)
        {
            file << new_list[i] << endl;
        }

        file.close();
    }
    else
    {
        cout << "File was not found" << endl;
        exit(0);
    }
}