#include <ctype.h>
#include <stdio.h>

#include "pangram.h"

#define ALPHABET_SIZE 26

bool
is_pangram (const char* sentence)
{
    if (sentence == NULL)
        return false;

    int alpha_occurence[ALPHABET_SIZE] = {0};

    for (const char* p = sentence; *p; p++)
        if (isalpha (*p))
            alpha_occurence[tolower (*p) - 'a']++;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (alpha_occurence[i] == 0)
            return false;

    return true;
}
