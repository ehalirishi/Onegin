#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "my_sorts.hpp"
#include "cmp_swap_func.hpp"
#include "input_output.hpp"

int main(int argc, const char** argv)
{
    if (argc != 2) 
    {
        printf("Error, please enter \"Onegin <file_name>.txt\"\n");
        return 1;
    } 
    else
    {
    text_t book = {};
    book.file_name = argv[1];
    
    book.copied_text_len = get_file_size(&book);
    book.copied_text = safe_calloc_for_copy(&book);
    FILE* original_text = open_file_safely(&book);
    
    copy_text_from_file(&book, original_text);

    fclose(original_text); // We won't need it anymore 

    printf(">>>     copied_text = %p\n",     book.copied_text);
    printf(">>> copied_text_len = %zd\n", book.copied_text_len);

    size_t string_num = num_of_strings(&book);

    printf(">>> string_num = %zd\n", string_num);
    getchar();

    char** str_addresses = (char**) calloc(string_num, sizeof(char*));

    find_str_addresses(book.copied_text, str_addresses, book.copied_text_len); // пусть это функция возвращает char**
    
    /*size_t i = 0;
    for (i = 0; i < string_num; i++)
        my_puts(str_addresses[i]);*/

    my_str_bubble_sort(str_addresses, string_num);

    free(book.copied_text);
    free(str_addresses);

    return 0;
    }
}