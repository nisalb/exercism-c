#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "isogram.h"

#define TABSIZE 26

void
bitmap_toggle(int bitmap, int pos) {

}

bool
is_isogram(const char phrase[]) {
    if (!phrase)
        return false;

    bool chartab[TABSIZE];
    for (int i = 0; i < TABSIZE; i++) {
        chartab[i] = false;
    }

    const char *pp = phrase;
    while (*pp) {
        unsigned idx = tolower(*pp) - 'a';
        if (idx <= TABSIZE) {
            if (chartab[idx])
                return false;
            else
                chartab[idx] = true;
        }
        pp++;
    }

    return true;
}
