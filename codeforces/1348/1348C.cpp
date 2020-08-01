#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[30];
char s[N];
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    sort(s + 1, s + n + 1);
    if (s[1] != s[k])
        putchar(s[k]);
    else if (s[k + 1] != s[n])
        printf("%c%s", s[1], s + k + 1);
    else
        for (int i = 1; i <= n; i += k)
            putchar(s[i]);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}