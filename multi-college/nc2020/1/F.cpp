#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char a[N << 2], b[N << 2];
int main()
{
    while (~scanf("%s%s", a, b))
    {
        int lena = strlen(a), lenb = strlen(b);
        int len = max(lena, lenb);
        for (int i = lena; i <= 2 * len; ++i)
            a[i] = a[i % lena];
        for (int i = lenb; i <= 2 * len; ++i)
            b[i] = b[i % lenb];
        a[len * 2 + 1] = b[len * 2 + 1] = 0;
        //printf("%s\n%s\n", a, b);
        int res = strcmp(a, b);
        if (res < 0)
            printf("<\n");
        else if (res > 0)
            printf(">\n");
        else
            printf("=\n");
    }
    return 0;
}