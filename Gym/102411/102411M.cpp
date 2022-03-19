#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
typedef long long ll;
unordered_map<int, int> mp;
int a[N];
void solve()
{
    mp.clear();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++mp[a[i]];
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        --mp[a[i]];
        for (int j = 1; j < i; ++j)
            if (mp.count((a[i] << 1) - a[j]))
                sum += mp[(a[i] << 1) - a[j]];
    }
    printf("%d\n", sum);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}