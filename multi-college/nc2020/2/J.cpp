#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
vector<int> v;
bool vis[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            v.clear();
            int x = a[i];
            while (!vis[x])
            {
                vis[x] = 1;
                v.push_back(x);
                x = a[x];
            }
            int inv, r = v.size();
            for (int i = 0; i < r; ++i)
                if (1ll * m * i % r == 1)
                    inv = i;
            for (int i = 0; i < r; ++i)
                b[v[i]] = v[(i + inv) % r];
        }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}