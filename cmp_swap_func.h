#define NUM_OF_STRINGS 14
#define NUM_OF_SYMBOLS 56

void int_swap(int* first_num, int* second_num);
int int_cmp(int first_num, int second_num);

int str_order(const char first_str[], const char second_str[]);
int are_symb_inequal(char first_symb, char second_symb);
int need_to_skip(char symb);
//void str_swap(char first_str[], char second_str[]);
void str_swap(char** first_string, char** second_string);
void copy_str(char* receiving_str, const char* copied_str);