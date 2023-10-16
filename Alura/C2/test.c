#include <stdio.h>

int sum(int numbers[10]);

int main()
{
    int number[10];
    number[0] = 10;
    number[1] = 10;
    number[2] = 10;
    number[3] = 10;
    number[4] = 10;
    number[5] = 10;
    number[6] = 10;
    number[7] = 10;
    number[8] = 10;
    number[9] = 10;

    int reslut = sum(number);
    printf("%d", reslut);


    return 0;
}

int sum(int numbers[10])
{
    int total;
    for (int i = 0; i < 10; i++)
    {
        total += numbers[i];
    }

    return total;
}