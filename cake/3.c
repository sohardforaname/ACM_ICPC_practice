#include <stdio.h>
#include <stdlib.h>
float comp(float *a, int n)
{
    if (n == 1)
        return 0;
    a[1] += a[0];
    comp(a + 1, n - 1);
    return a[n - 1] / n;
}