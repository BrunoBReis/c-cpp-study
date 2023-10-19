#include <stdio.h>

// functions
void changing_values(float *ptr1, float *ptr2);

int main()
{
    // creating float numbers
    float a,b;
    a = 3.14, b = 2.07;
    printf("a = %.2f, b = %.2f\n", a, b);
    printf("a = %p, b = %p", &a, &b);
    // get both a and b adress
    changing_values(&a, &b);
    printf("\n");
    printf("a = %.2f, b = %.2f", a, b);
    printf("\n");
    printf("a = %p, b = %p\n", &a, &b);

    return 0;
}

void changing_values(float *ptr1, float *ptr2)
{
    // changes the value of &a and &b
    float temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}