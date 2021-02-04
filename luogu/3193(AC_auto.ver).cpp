#include "../base.h"

const int N = 2e1 + 5, M = 1e1;
bool multi = 0;

int trie[N][M], fail[N];
bool f[N];
int cnt;
struct Mat
{
    ll mat[N][N];
    Mat()
    {
        memset(mat, 0, sizeof(mat));
    }
};

void insert(char *s, int len)
{
    int root = 0;
    for (int i = 0; i < len; ++i)
    {
        int nxt = s[i] - '0';
        if (!trie[root][nxt])
            trie[root][nxt] = ++cnt;
        root = trie[root][nxt];
    }
    f[root] = 1;
}
void getfail()
{
    queue<int> q;
    for (int i = 0; i < M; ++i)
        if (trie[0][i])
            q.push(trie[0][i]), fail[trie[0][i]] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (f[fail[now]])
            f[now] = 1;
        for (int i = 0; i < M; ++i)
        {
            if (trie[now][i])
            {
                q.push(trie[now][i]);
                fail[trie[now][i]] = trie[fail[now]][i];
            }
            else
                trie[now][i] = trie[fail[now]][i];
        }
    }
}
ll n, m, mod;
Mat mul(const Mat &a, const Mat &b, int n)
{
    Mat res;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                (res.mat[i][j] += a.mat[i][k] * b.mat[k][j]) %= mod;
    return res;
}
Mat pow(Mat a, int n, ll p)
{
    Mat res;
    for (int i = 0; i <= n; ++i)
        res.mat[i][i] = 1;
    while (p)
    {
        if (p & 1)
            res = mul(res, a, n);
        a = mul(a, a, n);
        p >>= 1;
    }
    return res;
}
char s[N];
void solve()
{
    io(n, m, mod);
    io(s);
    insert(s, strlen(s));
    getfail();
    Mat ans;
    for (int i = 0; i <= cnt; ++i)
    {
        if (f[i])
            continue;
        for (int j = 0; j < M; ++j)
        {
            if (f[trie[i][j]])
                continue;
            ans.mat[i][trie[i][j]] += 1;
        }
    }
    ans = pow(ans, cnt, n);
    ll tot = 0;
    for (int i = 0; i <= cnt; ++i)
        (tot += ans.mat[0][i]) %= mod;
    io(tot, '\n');
}

MAIN_FUNC