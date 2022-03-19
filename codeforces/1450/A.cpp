#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
int a[26];
char s[N];
void solve()
{
    int n;
    scanf("%d%s", &n, s + 1);
    sort(s + 1, s + n + 1, greater<char>());
    printf("%s\n", s + 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}