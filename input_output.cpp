#include <stdio.h>
#include <assert.h>
#include "input_output.h"

void print_arr(int arr[], size_t arr_size)
{
    size_t i = 0;
    for (i = 0; i < arr_size; i++)
    {
        assert (i < arr_size);
        printf("% 5d ", arr[i]);
    }
    putchar('\n');
}