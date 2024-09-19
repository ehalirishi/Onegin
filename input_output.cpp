#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "input_output.hpp"

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

void copy_text_from_file(char* copied_text, const size_t copied_text_len, FILE* original_text)
{
    fread(copied_text, sizeof(char), copied_text_len, original_text);

    copied_text[copied_text_len] = '\n'; // We add '\n' to the end of the string to ensure safety
}

size_t num_of_strings(const char copied_text[], size_t copied_text_len)
{
    size_t string_num = 0;
    size_t i = 0;
    for (i = 0; i < copied_text_len; i++)
        if (copied_text[i] == '\n')
            string_num++;

    return string_num + 1; // + 1 because in loop we didn't count the last string (it ends with '\0')
}

void find_str_addresses(const char copied_text[], char* str_address[], size_t copied_text_len)
{
    size_t i = 0, address_i = 0;
    str_address[address_i] = (char*) &copied_text[0];
    for (i = 0; i < copied_text_len; i++)
        if (copied_text[i] == '\n')
        {
            address_i++;
            str_address[address_i] = (char*) &copied_text[i + 1];
        }
}

void my_puts(const char str[])
{
    size_t i = 0;
    for (i = 0; str[i] != '\n' && str[i] != '\0'; i++)
        putchar(str[i]);
    putchar('\n');
}

size_t get_file_size(const char* file_name)
{
    struct stat bin_info = {};
    stat(file_name, &bin_info); // We get info about file size (in binary mode)

    printf(">>> File size in binary mode is %ld\n", bin_info.st_size);

    return bin_info.st_size;
}

// I know that this function is not really "safe" because of exit, but that's temporary
FILE* open_file_safely(const char* file_name)
{
    FILE* file_text = fopen(file_name, "rb");
    if (!file_text)
    {
        perror("open_file_safely()");
        exit(errno);
    }

    return file_text;
}

// I know that this function is not really "safe" because of exit, but that's temporary
char* safe_calloc(const size_t buf_len)
{
    char* buf = (char*) calloc(buf_len + 1, sizeof(char)); // We make string a bit bigger for safety 
    if (!buf)
    {
        perror("safe_calloc()");
        exit(errno);
    }

    printf(">>> %d bytes allocated for address %p\n", buf_len + 1, buf);

    return buf;
}