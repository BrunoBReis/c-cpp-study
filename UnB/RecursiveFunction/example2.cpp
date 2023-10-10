#include <iostream>
using namespace std;

void contrario(char s[]);

int main()
{
    char s[30];
    cin >> s;
    contrario(s);
    cout << endl;

    return 0;
}

void contrario(char s[])
{
    if (s[0] != '\0')
    {
        contrario(&s[1]);
        cout << s[0];
    }
}