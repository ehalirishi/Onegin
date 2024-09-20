#include <stdio.h>
#include <assert.h>
#include "my_sorts.hpp"
#include "input_output.hpp"
#include "cmp_swap_func.hpp"

void my_str_bubble_sort(char* str_addresses[], size_t string_num)
{    
    size_t i = 0, j = 0;
    printf("\n\nYour text before sorting:\n\n");
    /*for (i = 0; i < string_num; i++)
        my_puts(str_addresses[i]);*/
    
    
    for (i = 0; i < string_num - 1; i++)
        for (j = 0; j < string_num - i - 1; j++)
        {    
            assert (j < string_num);
            assert (j + 1 < string_num);
            
            if (str_order(str_addresses[j], str_addresses[j + 1]) > 0)
                str_swap(&str_addresses[j], &str_addresses[j + 1]);
        }

    printf("\n\nYour text after sorting:\n\n");
    for (i = 0; i < string_num; i++)
        my_puts(str_addresses[i]);
}
