#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int pos;
char s[N];
void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (pos = 1; pos <= n && s[pos] != '1'; ++pos)
        ;
    if (pos == n + 1)
    {
        for (int i = 1; i <= n; ++i)
            putchar((s[i] - '0') / 2 + '0');
        putchar('\n');
        for (int i = 1; i <= n; ++i)
            putchar((s[i] - '0') / 2 + '0');
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i < pos)
            putchar((s[i] - '0') / 2 + '0');
        else if (i == pos)
            putchar(s[i]);
        else
            putchar('0');
    }
    putchar('\n');
    for (int i = 1; i <= n; ++i)
    {
        if (i < pos)
            putchar((s[i] - '0') / 2 + '0');
        else if (i == pos)
            putchar('0');
        else
            putchar(s[i]);
    }
    putchar('\n');
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}