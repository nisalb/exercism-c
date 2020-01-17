#include <ctype.h>

#include "isogram.h"

#define TABSIZE 26

unsigned bitmap_toggle(unsigned, unsigned);
bool bitmap_isset(unsigned, unsigned);

unsigned
bitmap_toggle(unsigned bitmap, unsigned pos)
{
    return bitmap ^ ((unsigned) 1 << pos);
}

bool
bitmap_isset(unsigned bitmap, unsigned pos)
{
    return (bitmap & ((unsigned) 1 << pos)) > 0;
}

bool
is_isogram(const char phrase[])
{
    if (!phrase)
        return false;

//    bool chartab[TABSIZE];
    unsigned bitmap = 0;

    const char* pp = phrase;
    while (*pp) {
        unsigned idx = tolower(*pp) - 'a';
        if (idx <= TABSIZE) {
            if (bitmap_isset(bitmap, idx))
                return false;
            else
                bitmap = bitmap_toggle(bitmap, idx);
        }
        pp++;
    }

    return true;
}
