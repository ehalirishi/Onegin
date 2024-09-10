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



