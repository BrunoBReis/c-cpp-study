#include <stdio.h>

int main()
{
    // all built-in data type
    char letter = 'A';
    unsigned char unchar = 200;
    int integer = 42;
    unsigned int uninteger = 1000;
    float floating_number = 3.1415;
    double double_floating_number = 32.1321;

    // representing all data types in prints
    printf("%c", letter);
    printf("\n");
    printf("%u", unchar);
    printf("\n");
    printf("%d", integer);
    printf("\n");
    printf("%u", uninteger);
    printf("\n");
    printf("%f", floating_number);
    printf("\n");
    printf("%.2f", floating_number);
    printf("\n");
    printf("%f", double_floating_number);
    printf("\n");

    // testing scanf
    char letter1;
    scanf("%c", &letter1);
    printf("%c", letter1);
    printf("\n");

    // cleaning buffer
    while (getchar() != '\n')
        ;

    return 0;
}