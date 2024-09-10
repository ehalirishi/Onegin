#include <stdio.h>
#include <assert.h>
#include "my_sorts.h"
#include "input_output.h"
#include "cmp_swap_func.h"

void my_int_bubble_sort(int arr[], size_t arr_size)
{
    printf("Your array before sorting is: ");
    print_arr(arr, arr_size);
    
    size_t i = 0, j = 0;
    for (i = 0; i < arr_size - 1; i++)
        for (j = 0; j < arr_size - i - 1; j++)
        {    
            assert (j < arr_size);
            assert (j + 1 < arr_size);
            
            if (int_cmp(arr[j], arr[j + 1]) > 0)
                int_swap(&arr[j], &arr[j + 1]);
        }

    printf("Your array after sorting is: ");
    print_arr(arr, arr_size);
}

void my_str_bubble_sort(char text[][NUM_OF_SYMBOLS])
{    
    size_t i = 0, j = 0;
    printf("Your text before sorting:\n");
    for (i = 0; i < NUM_OF_STRINGS; i++)
        puts(text[i]);
    
    
    for (i = 0; i < NUM_OF_STRINGS - 1; i++)
        for (j = 0; j < NUM_OF_STRINGS - i - 1; j++)
        {    
            assert (j < NUM_OF_STRINGS);
            assert (j + 1 < NUM_OF_STRINGS);
            
            if (str_order(text[j], text[j + 1]) > 0)
                str_swap(text[j], text[j + 1]);
        }

    printf("Your text after sorting:\n");
    for (i = 0; i < NUM_OF_STRINGS; i++)
        puts(text[i]);
}



