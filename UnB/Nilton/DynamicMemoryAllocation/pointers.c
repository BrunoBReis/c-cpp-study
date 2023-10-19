#include <stdio.h>

int main()
{
    //creating two variabales and one pointer
    int number, number1, *ptr;
    // alocating this values to number and number1
    number = 1234;
    number1 = 1234;
    // alocating numbers's memory to ptr 
    ptr = &number;
    // changing number's value to 4321 because ptr = &number;
    *ptr = 4321;

    printf("Value: %d", number);
    printf("\n");
    printf("Value1: %d", number1);
    printf("\n");
    printf("Memory adress: %p", &number);   
    printf("\n");
    printf("Value*: %p", ptr);
    printf("\n");
    printf("Memory adress: %p", &ptr);   
    printf("\n");
    printf("Value: %d", *ptr);   
    printf("\n");

    return 0;
}