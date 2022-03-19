#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
char s1[N], s2[N];
void solve()
{
    int n;
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    int r = 0, b = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s1[i] > s2[i])
            ++r;
        else if (s1[i] < s2[i])
            ++b;
    }
    if (r == b)
        puts("EQUAL");
    else if (r < b)
        puts("BLUE");
    else
        puts("RED");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}