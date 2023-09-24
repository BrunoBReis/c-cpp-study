#include <iostream>
#include <cstdlib>
#include <ctime>    

using namespace std;

int main()
{
    cout << "*************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivihacao! *" << endl;
    cout << "*************************************" << endl;

    cout << "Choose difficult" << endl;
    cout << "Easy (1) Medium(2) Hard(3) Very Hard(4) GOD (5)" << endl;

    int choose_difficult;
    cin >> choose_difficult;

    int number_of_tries;
    float multiplier;

    if (choose_difficult == 1)
    {
        number_of_tries = 15;
        multiplier = 1.0;
    }
    else if (choose_difficult == 2)
    {
        number_of_tries = 10;
        multiplier = 1.5;
    }
    else if (choose_difficult == 3)
    {
        number_of_tries = 5;
        multiplier = 2.0;
    }
    else if (choose_difficult == 4)
    {
        number_of_tries = 3;
        multiplier = 2.5;
    }
    else
    {
        number_of_tries = 2;
        multiplier = 3.5;
    }

    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;

    // cout << "The secret number is " << SECRET_NUMBER << ". Don't tell anybody." << endl;

    int tries = 0;

    double points = 1000.0;
    bool unfinished = true;

    cout << "You now have " << number_of_tries << " avaliable." << endl;

    while (unfinished)
    {
        tries++;
        if (number_of_tries >= tries)
        {
            int guess;

            int guess_left = number_of_tries - tries;

            cout << "Try " << tries << endl;
            cout << "Wich number do you guess? ";

            cin >> guess;

            double lost_points = abs(guess - SECRET_NUMBER) / 2.0;
            points -= lost_points;

            cout << "Your guess is " << guess << "." << endl;

            bool right_answer = (guess == SECRET_NUMBER);

            if (right_answer)
            {
                cout << "Congrats! You guess the right number!" << endl;
                cout << "You guessed in " << tries << " trys." << endl;

                cout.precision(2); // specifing de cout with a presecion
                cout << fixed;
                cout << "Your score: " << points * multiplier << endl;
                unfinished = false;
            }
            else // with this else the code was reduced
            {
                cout << "The secret number" << " is ";
                if (guess < SECRET_NUMBER)
                {
                    cout << "higher then";
                }
                else
                {
                    cout << "lower then";
                }
                cout << " your guess." << endl;
                cout << "----------------" << endl;
            }
        }
        else
        {
            unfinished = false;
            cout << "End game." << endl;
        }
    }
    cout << "Thanks for playing" << endl;
}
