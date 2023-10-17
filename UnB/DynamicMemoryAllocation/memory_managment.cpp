#include <iostream>
using namespace std;

int main()
{
    // ptam = how many elements does  *pVector have
    int pind, ptam;
    // creating a pointer
    float *pVector;

    cout << "How many elements" << endl;
    cin >> ptam;
    // alocating pointer in vector
    pVector = new float[ptam];

    for (pind = 0; pind < ptam; pind++)
        pVector[pind] = ((float)pind) / ptam;

    for (pind = 0; pind < ptam; pind++)
        cout << pVector[pind] << endl;

    // desalocing pointer in vector
    delete[] pVector;

    return 0;
}