#include "../base.h"

bool multi = 0;
const int N = 1e5 + 5;
vector<int> G[N], lay[N], laysiz[N];
bool dp[2][N];
int pre[N], f[N], num[N];
int dep[N], siz[N], maxdep;

void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    util.cmax(maxdep, dep[u]);
    siz[u] = 1;
    for (auto i : G[u]) {
        dfs(i, u);
        siz[u] += siz[i];
    }
}

vector<pair<int, int>> laycnt;
bool sel[N];

void solve()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 2; i <= n; ++i) {
        int fa;
        scanf("%d", &fa);
        G[fa].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        lay[dep[i]].push_back(i);
    }
    for (int i = 1; i <= maxdep; ++i) {
        laysiz[lay[i].size()].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (laysiz[i].size()) {
            laycnt.push_back({ i, laysiz[i].size() });
        }
    }
    //reverse(laycnt.begin(), laycnt.end());
    dp[laycnt.size() & 1][0] = 1;
    int cur = (laycnt.size() - 1) & 1;
    for (int i = laycnt.size() - 1; i >= 0; --i) {
        int val, freq;
    std:
        tie(val, freq) = laycnt[i];
        f[0] = 0;
        for (int j = 1; j <= x; ++j) {
            f[j] = -1;
        }
        for (int j = 0; j <= x; ++j) {
            dp[cur][j] = 0;
        }
        for (int j = 0; j <= x; ++j) {
            if (j >= val && !dp[cur ^ 1][j]) {
                dp[cur][j] = (f[j % val] != -1 && (j - f[j % val]) / val <= freq);
                if (dp[cur][j])
                    num[j] = val, pre[j] = f[j % val];
            }
            dp[cur][j] |= dp[cur ^ 1][j]; // the last status ok, obvious it's ok.
            if (dp[cur ^ 1][j])
                f[j % val] = j;
        }
        cur ^= 1;
    }
    if (dp[0][x]) {
        printf("%d\n", maxdep);
        while (x) {
            int t = (x - pre[x]) / num[x];
            for (int i = 0; i < t; ++i) {
                sel[laysiz[num[x]][i]] = 1;
            }
            x = pre[x];
        }
        for (int i = 1; i <= n; ++i) {
            putchar(sel[dep[i]] ? 'a' : 'b');
        }
    } else {
        printf("%d\n", maxdep + 1);
        int a = x, b = n - x;
        int tagdep, minc, cnt;
        for (int i = 1; i <= maxdep; ++i) {
            if (lay[i].size() <= a) {
                sel[i] = 1, a -= lay[i].size();
            } else if (lay[i].size() <= b) {
                b -= lay[i].size();
            } else {
                tagdep = i;
                minc = a < b;
                cnt = lay[i].size() - (minc ? b : a);
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dep[i] < tagdep) {
                putchar(sel[dep[i]] ? 'a' : 'b');
            } else if (dep[i] > tagdep) {
                putchar(minc ? 'a' : 'b');
            } else if (!G[i].size() && cnt) {
                putchar(minc ? 'a' : 'b');
                --cnt;
            } else {
                putchar(minc ? 'b' : 'a');
            }
        }
    }
}

MAIN_FUNC