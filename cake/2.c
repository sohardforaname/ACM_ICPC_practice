#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define bool _Bool
bool cmpstr(char *s)
{
    int i, len;
    for (len = 0; s[len]; ++len)
        ;
    for (i = 0; i < len / 2; ++i)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}