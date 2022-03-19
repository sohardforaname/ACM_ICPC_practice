#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define ll long long
struct Edge
{
	int u, v;
	long long w;
	Edge(int a, int b, long long c)
	{
		u = a, v = b, w = c;
	}
	bool operator<(const Edge &a) const
	{
		return w > a.w;
	}
};
vector<Edge> Eo[MAXN];
long long diss[MAXN];
bool vis[MAXN];
void dijkstra()
{
	memset(diss, inf, sizeof(diss));
	memset(vis, 0, sizeof(vis));
	priority_queue<Edge> que;
	diss[1] = 0;
	que.push(Edge(1, 1, 0));
	while (!que.empty())
	{
		auto tmp = que.top();
		que.pop();
		if (vis[tmp.v])
			continue;
		vis[tmp.v] = 1;
		for (auto &e : Eo[tmp.v])
		{
			if (diss[e.v] > diss[tmp.v] + e.w)
			{
				diss[e.v] = diss[tmp.v] + e.w;
				if (!vis[e.v])
					que.push(Edge(tmp.v, e.v, diss[e.v]));
			}
		}
	}
}

int sp, tp;
struct node
{
	int v, next;
	ll cap;
} mp[MAXN * 4];
int pre[MAXN], dis[MAXN], cur[MAXN];
int cnt = 0;
void init()
{
	cnt = 0;
	memset(pre, -1, sizeof(pre));
}
void add(int u, int v, int w)
{
	mp[cnt].v = v;
	mp[cnt].cap = w;
	mp[cnt].next = pre[u];
	pre[u] = cnt++;
}
bool bfs()
{
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	while (!q.empty())
		q.pop();
	q.push(sp);
	dis[sp] = 0;
	int u, v;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = pre[u]; i != -1; i = mp[i].next)
		{
			v = mp[i].v;
			if (dis[v] == -1 && mp[i].cap > 0)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
				if (v == tp)
					break;
			}
		}
	}
	return dis[tp] != -1;
}
ll dfs(int u, ll cap)
{
	if (u == tp || cap == 0)
		return cap;
	ll res = 0, f;
	for (int &i = cur[u]; i != -1; i = mp[i].next)
	{
		int v = mp[i].v;
		if (dis[v] == dis[u] + 1 && (f = dfs(v, min(cap - res, mp[i].cap))) > 0)
		{
			mp[i].cap -= f;
			mp[i ^ 1].cap += f;
			res += f;
			if (res == cap)
				return cap;
		}
	}
	if (!res)
		dis[u] = -1;
	return res;
}
ll dinic(int n)
{
	ll ans = 0;
	while (bfs())
	{
		for (int i = 1; i <= n; i++)
			cur[i] = pre[i];
		ans += dfs(sp, inf);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, a, b, c;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			Eo[i].clear();
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			Eo[a].push_back(Edge(a, b, c));
		}
		dijkstra();
		sp = 1, tp = n;
		init();
		//cout<<endl;
		for (int i = 1; i <= n; ++i)
			for (auto &e : Eo[i])
				if (diss[e.v] - diss[e.u] == e.w)
				{
					add(e.u, e.v, e.w);
					add(e.v, e.u, 0);
				}
		cout << dinic(n) << endl;
	}
	return 0;
}
