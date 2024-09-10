#include <stdio.h>
#include "my_sorts.h"
#include "cmp_swap_func.h"

#define NUM_OF_STRINGS 14
#define NUM_OF_SYMBOLS 50

int main(void)
{
    char text[NUM_OF_STRINGS][NUM_OF_SYMBOLS] = 
                        {"My uncle, what a worthy man,",
                         "Falling ill like that, and dying;",
                         "It summons up respect, one can",
                         "Admire it, as if he were trying.",
                         "Let us all follow his example!",
                         "But, God, what tedium to sample",
                         "That sitting by the bed all day,",
                         "All night, barely a foot away!",
                         "And the hypocrisy, demeaning,",
                         "Of cosseting one who\'s half alive;",
                         "Puffing the pillows, you contrive",
                         "To bring his medicine unsmiling,",
                         "Thinking with a mournful sigh,",
                         "\"Why the devil can\'t you die?\"\'"};

    str_order("Ab//Cd", "A..Bcd");
    str_order("Ab,Cd", "  \tabCD");
    str_order("K{}oTik", "KOTiK");
    str_order("[Dawg", "kotIK");

    return 0;
}