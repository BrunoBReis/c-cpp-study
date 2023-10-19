#include <stdio.h>

int soma(int nums[], int times);

int main()
{
    int nums[3];
    nums[0] = 10;
    nums[1] = 5;
    nums[2] = 0;

    printf("%d", soma(nums, 3));

    return 0;
}

int soma(int nums[], int times)
{
    int result;
    for (int i = 0; i < times; i++)
    {
        result += nums[i];
    }

    return result;
}