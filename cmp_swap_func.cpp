#include <stdio.h>

void int_swap(int* first_num, int* second_num)
{
    int temporary = 0;
    printf("Swapping  % 5d and % 5d\n", *first_num, *second_num);
    temporary = *first_num;
    *first_num = *second_num;
    *second_num = temporary;
}


// returns > 0 if you need to swap and <= 0 if you don't need to
int int_cmp(int first_num, int second_num)
{
    printf("Comparing % 5d and % 5d\n", first_num, second_num);
    return first_num - second_num;
}

// returns > 0 if you need to swap and <= 0 if you don't need to
int str_order(const char first_str[], const char second_str[])
{
    size_t i = 0;
    for (i = 0; first_str[i] != '\0' && second_str[i] != '\0'; i++)
        if (first_str[i] != second_str[i])
            return first_str[i] - second_str[i];

    return first_str[i] - second_str[i];
}