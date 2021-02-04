#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

bool multi = 1;
char a[N], b[N];
void solve()
{
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(char) * (n + 2));
    memset(b, 0, sizeof(char) * (n + 2));
    scanf("%s", b + 1);
    int cur = 0;
    if (b[1] == '0')
        cur = 1;
    else if (b[1] == '1')
        cur = 2;
    a[1] = '1';
    for (int i = 2; i <= n; ++i)
    {
        if (cur == 2 && b[i] == '0')
            a[i] = '1', cur = 1;
        else if (cur == 2 && b[i] == '1')
            a[i] = '0', cur = 1;
        else if (cur == 1 && b[i] == '1')
            a[i] = '1', cur = 2;
        else if (cur == 1 && b[i] == '0')
            a[i] = '0', cur = 0;
        else if (cur == 0)
            a[i] = '1', cur = 1 + b[i] - '0';
    }
    printf("%s\n", a + 1);
}
int main()
{
    int t;
    if (multi)
        scanf("%d", &t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}