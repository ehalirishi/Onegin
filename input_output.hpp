#include <stdio.h>

void    print_arr(int arr[], size_t arr_size);
void    copy_text_from_file(char* copied_text, const size_t copied_text_len, FILE* original_text);
size_t  num_of_strings(const char copied_text[], size_t copied_text_len);
void    find_str_addresses(const char copied_text[], char* str_address[], size_t copied_text_len);
void    my_puts(const char str[]);
size_t  get_file_size(const char* file_name);
FILE*   open_file_safely(const char* file_name);
char*   safe_calloc(const size_t buf_len);