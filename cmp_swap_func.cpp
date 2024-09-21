#include <stdio.h>
#include <ctype.h>
#include "cmp_swap_func.hpp"
#include "input_output.hpp"

// returns > 0 if you need to swap and <= 0 if you don't need to
int str_order(const char first_str[], const char second_str[])
{
    /*printf("Comparing ");
    my_puts(first_str);
    printf("and ");
    my_puts(second_str);*/
    
    size_t first_i = 0, second_i = 0; // Two different counters are needed to ignore punctuation and space symbols
    while (first_str[first_i] != '\n' && second_str[second_i] != '\n')
    {
        skip_to_letter( first_str,  &first_i);
        skip_to_letter(second_str, &second_i);
        
        if (are_symb_inequal(first_str[first_i], second_str[second_i]))
        {            
            //printf("str_order = %5d\n", toupper(first_str[first_i]) - toupper(second_str[second_i]));
            return toupper(first_str[first_i]) - toupper(second_str[second_i]);
        }
        first_i++;
        second_i++;
    }

    //printf("str_order = %5d\n", first_str[first_i] - second_str[second_i]);
    return first_str[first_i] - second_str[second_i];
} // kal

int are_symb_inequal(char first_symb, char second_symb)
{   
    if (first_symb != second_symb)
        if (toupper(first_symb) != toupper(second_symb))                
            return true;
    
    return false;
}

void skip_to_letter(const char str[], size_t* index)
{
    //printf(">>> skip_to_letter(): \n");
    while ((isalpha(str[*index]) == false) && (str[*index] != '\n')) 
    {
        //printf("str[*index] = %c\n", str[*index]);
        (*index)++;
    }
}

void str_p_swap(char** first_string, char** second_string)
{
    char* temporary = *first_string;
    *first_string = *second_string;
    *second_string = temporary;
}