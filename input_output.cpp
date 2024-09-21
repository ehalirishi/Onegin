#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "input_output.hpp"

void copy_text_from_file(text_t* book, FILE* original_text)
{
    fread(book->copied_text, sizeof(char), book->copied_text_len, original_text);

    book->copied_text[book->copied_text_len] = '\n'; // We add '\n' to the end of the string to ensure safety
}

size_t num_of_strings(text_t* book)
{
    size_t string_num = 0;

    for (size_t i = 0; i < book->copied_text_len; i++)
        if (book->copied_text[i] == '\n')
            string_num++;

    return string_num + 1;
}

void find_str_addresses(const char copied_text[], char* str_address[], size_t copied_text_len)
{
    size_t address_i = 0;
    str_address[address_i] = (char*) &copied_text[0];
    for (size_t i = 0; i < copied_text_len; i++) {
        if (copied_text[i] == '\n')
        {
            address_i++;
            str_address[address_i] = (char*) &copied_text[i + 1];
        }
    }
} // EOF праверь

void my_puts(const char str[])
{
    for (size_t i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

size_t get_file_size(text_t* book)
{
    struct stat bin_info = {};
    stat(book->file_name, &bin_info); // We get info about file size (in binary mode)

    printf(">>> File size in binary mode is %ld\n", bin_info.st_size);

    return bin_info.st_size;
}

// I know that this function is not really "safe" because of exit, but that's temporary
FILE* open_file_safely(text_t* book)
{
    FILE* file_text = fopen(book->file_name, "rb");
    if (!file_text)
    {
        perror("open_file_safely()");
        exit(errno);
    }

    return file_text;
}

// I know that this function is not really "safe" because of exit, but that's temporary
char* safe_calloc_for_copy(text_t* book)
{
    book->copied_text_len++; // We make string a bit bigger for safety 
    
    char* buf = (char*) calloc(book->copied_text_len, sizeof(char));
    if (!buf)
    {
        perror("safe_calloc()");
        exit(errno);
    }

    printf(">>> %d bytes allocated for address %p\n", book->copied_text_len, buf);

    return buf;
}