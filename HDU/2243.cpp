#include <bits/stdc++.h>
using namespace std;
const int N = 35, M = 26;
typedef unsigned long long ull;
int cnt;
bool f[N];
int trie[N][M], fail[N];
void insert(char *str)
{
    int root = 0;
    for (int i = 0; str[i]; ++i)
    {
        int ch = str[i] - 'a';
        if (!trie[root][ch])
            trie[root][ch] = ++cnt;
        root = trie[root][ch];
    }
    f[root] = 1;
}
void getfail()
{
    queue<int> q;
    for (int i = 0; i < M; ++i)
        if (trie[0][i])
        {
            q.push(trie[0][i]);
            fail[trie[0][i]] = 0;
        }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (f[fail[now]])
            f[now] = 1;
        for (int i = 0; i < M; ++i)
        {
            if (trie[now][i])
            {
                fail[trie[now][i]] = trie[fail[now]][i];
                q.push(trie[now][i]);
            }
            else
                trie[now][i] = trie[fail[now]][i];
        }
    }
}
struct Mat
{
    ull m[N << 1][N << 1];
    Mat()
    {
        memset(m, 0, sizeof(m));
    }
};
void get_mat(Mat &mat)
{
    for (int i = 0; i <= cnt; ++i)
        if (!f[i])
            for (int j = 0; j < M; ++j)
                if (!f[trie[i][j]])
                    ++mat.m[i][trie[i][j]];
}
Mat mul(const Mat &a, const Mat &b, int n)
{
    Mat res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                res.m[i][j] += a.m[i][k] * b.m[k][j];
    return res;
}
Mat pow(Mat a, ull b, int n)
{
    Mat res;
    for (int i = 0; i < n; ++i)
        res.m[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, n);
        a = mul(a, a, n);
        b >>= 1;
    }
    return res;
}
Mat mulmat;
void init()
{
    cnt = 0;
    memset(trie, 0, sizeof(trie));
    memset(f, 0, sizeof(f));
    memset(fail, 0, sizeof(fail));
    mulmat.m[0][0] = 1, mulmat.m[0][1] = 26;
    mulmat.m[1][0] = 0, mulmat.m[1][1] = 26;
}
char s[N];
int main()
{
    int n;
    ull m;
    while (~scanf("%d%llu", &n, &m))
    {
        init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", s);
            insert(s);
        }
        getfail();
        mulmat = pow(mulmat, m, 2);
        Mat mat;
        get_mat(mat);
        for (int i = cnt + 1; i <= cnt * 2 + 1; ++i)
        {
            mat.m[i][i] = 1;
            for (int j = 0; j <= cnt; ++j)
                mat.m[j][i] = mat.m[j][i - cnt - 1];
        }
        mat = pow(mat, m, cnt * 2 + 2);
        ull ans = 0;
        for (int i = cnt + 1; i <= cnt * 2 + 1; ++i)
            ans += mat.m[0][i];
        printf("%llu\n", mulmat.m[0][1] - ans);
    }
    return 0;
}