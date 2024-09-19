#include <stdio.h>
#include <stdlib.h>
#include "my_sorts.hpp"
#include "cmp_swap_func.hpp"
#include "input_output.hpp"

#define ONEGIN "Onegin_original.txt"

typedef struct text_t 
{
    char* copied_text;
    size_t copied_text_len;
    const char* file_name;
} text_t;

int main(void)
{
    text_t Onegin;
    Onegin.file_name = "Onegin_original.txt";
    
    Onegin.copied_text_len = get_file_size(Onegin.file_name);
    Onegin.copied_text = safe_calloc(Onegin.copied_text_len);
    FILE* original_text = open_file_safely(Onegin.file_name);
    
    copy_text_from_file(Onegin.copied_text, Onegin.copied_text_len, original_text);
    
    fclose(original_text); // We won't need it anymore  

    printf(">>>     copied_text = %p\n",     Onegin.copied_text);
    printf(">>> copied_text_len = %zd\n", Onegin.copied_text_len);

    size_t string_num = num_of_strings(Onegin.copied_text, Onegin.copied_text_len);

    printf(">>> string_num = %zd\n", string_num);

    char** str_addresses = (char**) calloc(string_num, sizeof(char*)); // а где free?

    find_str_addresses(Onegin.copied_text, str_addresses, Onegin.copied_text_len); // пусть это функция возвращает char**
    
    /*size_t i = 0;
    for (i = 0; i < string_num; i++)
        my_puts(str_addresses[i]);*/

    my_str_bubble_sort(str_addresses, string_num);

    free(Onegin.copied_text);
    free(str_addresses);

    return 0;
}