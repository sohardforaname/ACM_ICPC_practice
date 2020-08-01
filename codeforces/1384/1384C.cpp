#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int fa[N], sum[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        sum[fx] += sum[fy];
    }
}
void init()
{
    for (int i = 1; i <= 1e2; ++i)
        fa[i] = i, sum[i] = 1;
}
char s1[N], s2[N];
void solve()
{
    init();
    int n;
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    bool f = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s1[i] > s2[i])
        {
            f = 1;
            break;
        }
        else if (s1[i] < s2[i])
            join(s1[i] - 'a' + 1, s2[i] - 'a' + 1);
    }
    if (f)
    {
        printf("-1\n");
        return;
    }
    int num = 0;
    for (int i = 1; i <= 1e2; ++i)
        /*find(i)*/;
    for (int i = 1; i <= 1e2; ++i)
        num += sum[i] - 1;
    printf("%d\n", num);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}