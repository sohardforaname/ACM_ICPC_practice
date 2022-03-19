#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
struct node
{
    ll sum;
    double avg;
    int cnt, fa;
};
node a[N];
int n, rt;
int find()
{
    double avg = 0;
    int pos = 0;
    for (int i = 1; i <= n; ++i)
        if (i != rt && a[i].avg > avg)
            pos = i, avg = a[i].avg;
    return pos;
}
ll ans = 0;
int main()
{
    scanf("%d%d", &n, &rt);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i].sum);
        a[i].avg = a[i].sum;
        a[i].cnt = 1;
        ans += a[i].sum;
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[v].fa = u;
    }
    for (int i = 1; i <= n; ++i)
    {
        int now = find(), fa = a[now].fa;
        for (int j = 1; j <= n; ++j)
            if (a[j].fa == now)
                a[j].fa = fa;
        ans += a[now].sum * a[fa].cnt;
        a[now].avg = 0;
        a[fa].cnt += a[now].cnt;
        a[fa].sum += a[now].sum;
        a[fa].avg = (1.0 * a[fa].sum) / a[fa].cnt;
    }
    printf("%lld\n", ans);
    return 0;
}