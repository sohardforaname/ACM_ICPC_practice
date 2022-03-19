#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

bool multi = 1;
typedef long long ll;

const ll maxn = 1000000;
ll prime[maxn + 5]; //就是个素数表
bool sf[maxn + 5];
ll num; //判断这个数是不是素数，sf[i]中的i是从1到maxn的数
void sushu()
{
    //核心 欧拉筛代码
    //num 用来记筛到第几个质数
    memset(sf, true, sizeof(sf));
    sf[1] = false;
    sf[0] = false; //1 0 特判
    for (int i = 2; i <= maxn; i++)
    { //外层枚举1~maxn
        if (sf[i])
            prime[++num] = i; //如果是质数就加入素数表
        for (int j = 1; j <= num; j++)
        { //内层枚举num以内的质数
            if (i * prime[j] > maxn)
                break;                //筛完结束
            sf[i * prime[j]] = false; //筛掉...
            if (i % prime[j] == 0)
                break; //避免重复筛
        }
    }
}

void solve()
{
    int d;
    scanf("%d", &d);
    ll ans = 1;
    ll a = ans + d;
    a = *lower_bound(prime + 1, prime + num + 1, a);
    ans *= a;
    a += d;
    a = *lower_bound(prime + 1, prime + num + 1, a);
    ans *= a;
    printf("%lld\n", ans);
}
int main()
{
    sushu();
    int t;
    if (multi)
        scanf("%d", &t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}