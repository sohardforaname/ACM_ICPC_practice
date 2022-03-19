#include <bits\stdc++.h>
using namespace std;
const int N = 500, M = 50;
int tr[N][M], fail[N];
int cnt;
bool f[N];
void insert(int *s, int len)
{
    int root = 0;
    for (int i = 1; i <= len; ++i)
    {
        if (tr[root][s[i]])
            tr[root][s[i]] = ++cnt;
        root = tr[root][s[i]];
    }
    f[root] = 1;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < M; ++i)
        if (tr[0][i])
        {
            q.push(tr[0][i]);
            fail[tr[0][i]] = 0;
        }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (f[fail[now]])
            f[now] = 1;
        for (int i = 0; i < M; ++i)
        {
            if (tr[now][i])
            {
                fail[tr[now][i]] = tr[fail[now]][i];
                q.push(tr[now][i]);
            }
            else
                tr[now][i] = tr[fail[now]][i];
        }
    }
}
pair<int, int> p[N];
double dis[N][N];
double get_dis(pair<int, int> &a, pair<int, int> &b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
void dijkstra()
{
    for (int i = 1; i <= cnt; ++i)
        for (int j = 1; j <= cnt; ++j)
            dis[i][j] = 0x3f3f3f3f;
    dis[1][tr[0][1]] = 0;
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 0; j < M; ++j)
            ;
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        ;
}