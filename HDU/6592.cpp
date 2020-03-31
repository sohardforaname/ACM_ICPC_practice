#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int f[MAXN][2], g[MAXN][2], num[MAXN];
//f[i][0]表示选了a[i]之后a[1~i]的最长上升子序列，f[i][1]表示选了a[i]之后a[i~n]的最长单峰子序列
//g[i][0]表示选了a[i]之后a[i~n]的最长下降子序列，g[i][1]表示选了a[i]之后a[i~n]的最长单峰子序列
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
            cin >> num[i];
        f[0][0] = f[0][1] = 0;
        g[n + 1][0] = g[n + 1][1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            f[i][0] = f[i - 1][0];
        }
    }
}
