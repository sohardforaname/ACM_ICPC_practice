#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
struct edge {
    int to;
    ll w;
    bool operator<(const edge& e) const
    {
        return w > e.w;
    }
};
vector<edge> G[N];
ll dis[N];
bool vis[N];
int n, m;
const ll INF = 0x3f3f3f3f3f3f3f3f;
void dijkstra(int s)
{
    fill(dis + 1, dis + n + 1, INF);
    fill(vis + 1, vis + n + 1, 0);
    priority_queue<edge> q;
    q.push({ s, 0 });
    dis[s] = 0;
    while (q.size()) {
        edge e = q.top();
        q.pop();
        if (vis[e.to])
            continue;
        vis[e.to] = 1;
        for (auto i : G[e.to])
            if (dis[i.to] > dis[e.to] + i.w) {
                dis[i.to] = dis[e.to] + i.w;
                q.push({ i.to, dis[i.to] });
            }
    }
}

void init(int n)
{
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
    }
}

int main()
{
    int ts;
    scanf("%d", &ts);
    while (ts--) {
        int s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);
        init(n);
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({ v, w });
            G[v].push_back({ u, w });
        }
        dijkstra(s);
        printf("%lld\n", dis[t] == INF ? -1 : dis[t]);
    }
    return 0;
}

#include <pthread.h>

typedef struct para {
    int n, a, b, c;
} para;

void* f(void* p)
{
    pthread_t t1, t2;
    para* pp = (para*)p;
    if (pp->n == 1) {
        int ans = 1;
        return (void*)(&ans);
    }
    para p1;
    p1.n = (pp->n) - 1;
    p1.a = pp->a;
    p1.b = pp->b;
    p1.c = pp->c;
    pthread_create(&t1, NULL, f, (void*)(&p1));
    p1.n = (pp->n) - 1;
    p1.a = pp->b;
    p1.b = pp->c;
    p1.c = pp->a;
    pthread_create(&t1, NULL, f, (void*)(&p1));
    int ans = 1;
    void* a;
    pthread_join(t1, &a);
    ans += *(int*)a;
    pthread_join(t2, &a);
    ans += *(int*)a;
    return (void*)(&ans);
}