#include <stdio.h>
#include <ctype.h>
#include "cmp_swap_func.h"

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
    printf("Comparing \"%35s\" and \"%35s\": ", first_str, second_str);
    
    size_t i = 0;
    for (i = 0; first_str[i] != '\0' && second_str[i] != '\0'; i++)
        if (are_symb_inequal(first_str[i], second_str[i]))
        {
            printf("str_order = %5d\n", toupper(first_str[i]) - toupper(second_str[i]));
            return toupper(first_str[i]) - toupper(second_str[i]);
        }

    printf("str_order = %5d\n", first_str[i] - second_str[i]);
    return first_str[i] - second_str[i];
}

int are_symb_inequal(char first_symb, char second_symb)
{
    if (first_symb != second_symb)
        if (toupper(first_symb) != toupper(second_symb))                
            return true;
    
    return false;
}