#include <stdio.h>
#include <stdlib.h>
int delarr(int *a, int n)
{
    int len = n;
    int i;
    for (i = 0; i < n; ++i)
    {
        int cnt = 0, j, tmp = a[i];
        for (j = 2; j * j <= tmp; ++j)
            if (tmp % j == 0)
            {
                ++cnt;
                while (tmp % j == 0)
                    tmp /= j;
            }
        if (!cnt)
        {
            a[i] = 0;
            --len;
        }
    }
    int pos = 0;
    for (i = 0; i < len; ++i)
    {
        while (!a[pos++])
            ;
        a[i] = a[pos];
    }
    return len;
}