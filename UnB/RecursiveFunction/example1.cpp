#include <iostream>
using namespace std;

int exop(int x, int y);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <arg1> <arg2>" << endl;
        return 1;
    }

    int e;
    e = exop(atoi(argv[0]), atoi(argv[1]));
    cout << e << endl;

    return 0;
}

int exop(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * exop(x, y - 1);
    }
}
