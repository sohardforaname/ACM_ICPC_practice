#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool isp[N];
int p[N], ps[N], pm[N];
int tot;
void get_p()
{
    memset(isp, 0xff, sizeof(isp));
    for (int i = 2; i < N; ++i)
    {
        if (isp[i])
            p[++tot] = i;
        for (int j = 1; j <= tot && p[j] * i < N; ++j)
        {
            isp[p[j] * i] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
}

vector<int> ans;
bool vis[N];

int main()
{
    get_p();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int pos = upper_bound(p + 1, p + tot + 1, n) - p - 1;
        memset(vis, 0, sizeof(bool) * (n + 4));
        ans.clear();
        for (int i = pos; i; --i)
        {
            if (p[i] > n / 2)
                continue;
            else
            {
                int cnt = 0;
                for (int j = 1; p[i] * j <= n; ++j)
                {
                    if (j == 2)
                        continue;
                    if (!vis[p[i] * j])
                    {
                        ans.push_back(p[i] * j);
                        vis[p[i] * j] = 1;
                        ++cnt;
                    }
                }
                if (cnt % 2)
                {
                    vis[p[i] << 1] = 1;
                    ans.push_back(p[i] << 1);
                }
            }
        }
        assert(ans.size() % 2 == 0);
        printf("%d\n", ans.size() / 2);
        for (int i = 0; i < ans.size(); i += 2)
            printf("%d %d\n", ans[i], ans[i + 1]);
    }
    return 0;
}
