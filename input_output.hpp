#include <stdio.h>

typedef struct text_t 
{
    char* copied_text;
    size_t copied_text_len;
    const char* file_name;
} text_t;

void    copy_text_from_file(text_t* book, FILE* original_text);
size_t  num_of_strings(text_t* book);
void    find_str_addresses(const char copied_text[], char* str_address[], size_t copied_text_len);
void    my_puts(const char str[]);
size_t  get_file_size(text_t* book);
FILE*   open_file_safely(text_t* book);
char*   safe_calloc_for_copy(text_t* book);