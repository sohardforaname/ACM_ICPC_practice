#include <map>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;
const int M = 2e3 + 5;
map<int, int> mp;
vector<int> G[M];
bool isprime[N];
int prime[N];
int tot;
void get_prime()
{
    for (int i = 0; i < N; ++i)
        isprime[i] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (isprime[i])
            prime[tot++] = i;
        for (int j = 0; j < tot && prime[j] * i < N; ++j)
        {
            isprime[prime[j] * i] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void init()
{
    int cnt = 1;
    for (int i = 1e3; i < 1e4; ++i)
        if (isprime[i])
            mp[i] = cnt++;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        pair<int, int> p = *it;
        int lft = p.first % 1000;
        for (int i = 0; i < 10; ++i)
            if (i * 1000 + lft != p.first && mp.find(i * 1000 + lft) != mp.end())
            {
                int u = mp[p.first], v = mp[i * 1000 + lft];
                G[u].push_back(v);
                G[v].push_back(u);
            }
        lft = p.first / 1000 * 1000 + p.first % 100;
        for (int i = 0; i < 10; ++i)
            if (i * 100 + lft != p.first && mp.find(i * 100 + lft) != mp.end())
            {
                int u = mp[p.first], v = mp[i * 100 + lft];
                G[u].push_back(v);
                G[v].push_back(u);
            }
        lft = p.first / 100 * 100 + p.first % 10;
        for (int i = 0; i < 10; ++i)
            if (i * 10 + lft != p.first && mp.find(i * 10 + lft) != mp.end())
            {
                int u = mp[p.first], v = mp[i * 10 + lft];
                G[u].push_back(v);
                G[v].push_back(u);
            }
        lft = p.first / 10 * 10;
        for (int i = 0; i < 10; ++i)
            if (i + lft != p.first && mp.find(i + lft) != mp.end())
            {
                int u = mp[p.first], v = mp[i + lft];
                G[u].push_back(v);
                G[v].push_back(u);
            }
    }
}
bool vis[M];
int dis[M];
int bfs(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        if (cur == t)
            break;
        for (int i = 0; i < G[cur].size(); ++i)
            if (!vis[G[cur][i]])
            {
                vis[G[cur][i]] = 1;
                dis[G[cur][i]] = dis[cur] + 1;
                q.push(G[cur][i]);
            }
    }
    return dis[t];
}
int main()
{
    get_prime();
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int dis = bfs(mp[u], mp[v]);
        if (dis == 0x3f3f3f3f)
            printf("Impossible\n");
        else
            printf("%d\n", dis);
    }
    return 0;
}