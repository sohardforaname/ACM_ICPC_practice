#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], fa[N];
bool vis[N];
int top;
pair<int, int> p[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &fa[i]);
    for (int i = 1; i <= n; ++i)
        if (fa[i] != i && a[i] <= b[fa[i]])
            return printf("-1\n"), 0;

    b[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        vector<int> v;
        int cur = i;
        while (!vis[cur])
        {
            vis[cur] = 1;
            v.push_back(cur);
            cur = fa[cur];
        }

        int minn = 0;
        for (int j = 0; j < v.size(); ++j)
            if (b[fa[v[minn]]] > b[fa[v[j]]])
                minn = j;

        for (int j = 1; j < v.size(); ++j)
        {
            int l = (minn - j + v.size()) % v.size();
            int r = (l + 1) % v.size();
            p[++top] = {v[l], v[r]};
        }
    }
    printf("%d\n", top);

    for (int i = 1; i <= top; ++i)
        printf("%d %d\n", p[i].first, p[i].second);
    return 0;
}