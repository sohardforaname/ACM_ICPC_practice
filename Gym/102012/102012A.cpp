#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef unsigned long long ull;
const ull mod = 1e9 + 7;
struct edge
{
    int u, v;
    ull w;
    bool operator<(const edge &a) const
    {
        return w < a.w;
    }
};
edge e[N];
int fa[N];
int n, m;
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
int find(int x)
{
    int p = x;
    while (fa[p] != p)
        p = fa[p];
    while (x != p)
    {
        int tmp = fa[x];
        fa[x] = p;
        x = tmp;
    }
    return p;
}
void join(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx ^ fy)
        fa[fx] = fy;
}
ull k1, k2;
ull xorShift128Plus()
{
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
void gen()
{
    scanf("%d%d%llu%llu", &n, &m, &k1, &k2);
    for (int i = 1; i <= m; ++i)
    {
        e[i].u = xorShift128Plus() % n + 1;
        e[i].v = xorShift128Plus() % n + 1;
        e[i].w = xorShift128Plus();
    }
}
bool same(int i, int j)
{
    return e[i].u == e[j].u && e[i].v == e[j].v && e[i].w == e[j].w;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        gen();
        init(n);
        sort(e + 1, e + m + 1);
        ull ans = 0, anst = 1;
        int ecnt = 0;
        for (int i = 1; i <= m; ++i)
            if (find(e[i].u) != find(e[i].v))
            {
                ans = (ans + e[i].w) % mod;
                join(e[i].u, e[i].v);
                int cnt = 1;
                ++ecnt;
                while (i < m && same(i, i + 1))
                {
                    ++cnt;
                    ++i;
                }
                anst = (anst * cnt) % mod;
            }
        int cnt = 1;
        if (ecnt == n - 1)
            printf("%llu\n", ans * anst % mod);
        else
            printf("0\n");
    }
    return 0;
}