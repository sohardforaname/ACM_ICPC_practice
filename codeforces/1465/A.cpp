#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char s[N];
void solve()
{
    int n;
    scanf("%d%s", &n, s + 1);
    int cnt = 0;
    for (int i = n; i; --i, ++cnt)
        if (s[i] != ')')
            break;
    if (cnt > n / 2)
        puts("Yes");
    else
        puts("No");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
