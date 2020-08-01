#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int mod = 998244353;

ll sum[N];
map<ll, int> num;
int a[N];
int ans, n, m;

int check(int l, int r)
{
    if (l > r)
        return 0;
    num.clear();
    sum[l - 1] = 0;
    for (int i = l; i <= r; i++)
    {
        sum[i] = (sum[i - 1] + a[i]) % m;
        if (num[sum[i]] > 0 || sum[i] == 0)
        {
            ans++;
            check(i + 1, r);
            break;
        }
        num[sum[i]]++;
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        check(1, n);
        printf("%d\n", ans);
    }
    return 0;
}