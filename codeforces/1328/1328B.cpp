#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll num[N];
void calc()
{
    for (int i = 1; i < N; ++i)
        num[i] = i * (i - 1ll) / 2;
}
void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int pos = 0;
    for (; num[pos] < k; ++pos)
        ;
    --pos;
    int b1 = n - pos, b2 = n - (k - num[pos]) + 1;
    for (int i = 1; i <= n; ++i)
        printf("%c", (i == b1 || i == b2) ? 'b' : 'a');
    printf("\n");
}
int main()
{
    calc();
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}