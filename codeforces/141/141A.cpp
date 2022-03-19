#include <bits/stdc++.h>
using namespace std;
int num1[128], num2[128];
char a[105], b[105], c[105];
int main()
{
    scanf("%s%s%s", a, b, c);
    int lena = strlen(a), lenb = strlen(b), lenc = strlen(c);
    for (int i = 0; i < lena; ++i)
        ++num1[a[i]];
    for (int i = 0; i < lenb; ++i)
        ++num1[b[i]];
    for (int i = 0; i < lenc; ++i)
        ++num2[c[i]];
    for (int i = 0; i < 128; ++i)
        if (num2[i] != num1[i])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}