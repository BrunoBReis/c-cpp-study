#include <iostream>

using namespace std;

// functions
void add_first_vector(char letter);
void reads_all_list();
void removes_an_character(char letter_to_remove);

// global variables
char *pvectar;
int ptammax = 4, pqtde;

int main()
{

    pvectar = new char[ptammax];

    pvectar[0] = 'b';
    pvectar[1] = 'c';
    pvectar[2] = 'd';

    cout << "BEFORE FUNCTION" << endl;

    reads_all_list();

    add_first_vector('a');

    cout << "AFTER FUNCTION" << endl;

    reads_all_list();

    cout << "AFETER REMOVES FUNCTION" << endl;

    removes_an_character('a');
    
    reads_all_list();

    return 0;
}

void add_first_vector(char letter)
{
    for (pqtde = ptammax - 1; pqtde >= 0; pqtde--)
    {
        pvectar[pqtde + 1] = pvectar[pqtde];
    }

    pvectar[0] = letter;
}

void reads_all_list()
{
    for (pqtde = 0; pqtde < ptammax; pqtde++)
    {
        cout << pqtde << ' ' << pvectar[pqtde] << endl;
    }
}

void removes_an_character(char letter_to_remove)
{
    for (pqtde = 0; pqtde < ptammax; pqtde++)
    {
        if (letter_to_remove == pvectar[pqtde])
        {
            pvectar[pqtde] = ' ';
        }
    }

}