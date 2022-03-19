/*暂时不太会，先记下来*/
/*三角剖分+分治*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
struct node
{
	int u, v, id;
};
vector<int>vc[N][2], ee[N];
vector<pii>e[N][2];
vector<node>q[N][2];
int ans[N], pos[N], num[N];
int lf[N], rt[N], ok[N];
int d[N][2];
queue<int>que;
void bfs(int s, int id)
{
	d[s][id] = 0;
	que.push(s);
	while (que.size())
	{
		int u = que.front();
		que.pop();
		for (auto i : ee[u])
			if (d[i][id] > d[u][id] + 1)
			{
				d[i][id] = d[u][id] + 1;
				que.push(i);
			}
	}
}
void solve(int k, int op)
{
	if (vc[k][op].size() <= 3 || q[k][op].size() == 0)//没有询问
		return;
	int nodes = vc[k][op].size();
	for (int i = 0; i < nodes; ++i)
	{
		ee[i].clear();
		pos[vc[k][op][i]] = i;
		d[i][0] = d[i][1] = inf;
		ee[i].push_back((i + 1) % nodes);
		ee[i].push_back((i - 1 + nodes) % nodes);
	}
	int maxn = inf, id = 0;
	for (int i = 0; i < e[k][op].size(); ++i)
	{
		int u = e[k][op][i].first, v = e[k][op][i].second;
		int tmp = max(pos[v] - pos[u], nodes - pos[v] + pos[u]);
		if (tmp < maxn)
		{
			id = i;
			maxn = tmp;
		}
		ee[pos[u]].push_back(pos[v]);
		ee[pos[v]].push_back(pos[u]);
	}
	vc[k + 1][0].clear();
	vc[k + 1][1].clear();
	q[k + 1][0].clear();
	q[k + 1][1].clear();
	e[k + 1][0].clear();
	e[k + 1][1].clear();
	int u = e[k][op][id].first, v = e[k][op][id].second;
	for (int i = 0; i < nodes; ++i)
	{
		if (vc[k][op][i] == u || vc[k][op][i] == v)
		{
			vc[k + 1][0].push_back(vc[k][op][i]);
			vc[k + 1][1].push_back(vc[k][op][i]);
		}
		else if (vc[k][op][i] < u || vc[k][op][i] > v)
		{
			vc[k + 1][0].push_back(vc[k][op][i]);
			lf[vc[k][op][i]] = 1;
		}
		else
		{
			vc[k + 1][1].push_back(vc[k][op][i]);
			rt[vc[k][op][i]] = 1;
		}
	}
	bfs(pos[u], 0);
	bfs(pos[v], 1);
	for (int i = 0; i < e[k][op].size(); ++i)
	{
		u = e[k][op][i].first, v = e[k][op][i].second;
		if (lf[u] || lf[v])
			e[k + 1][0].push_back(e[k][op][i]);
		else if (rt[u] || rt[v])
			e[k + 1][1].push_back(e[k][op][i]);
	}
	for (int i = 0; i < q[k][op].size(); ++i)
	{
		u = q[k][op][i].u, v = q[k][op][i].v;
		int aid = q[k][op][i].id;
		if (lf[u] && lf[v])
		{
			q[k + 1][0].push_back(q[k][op][i]);
			continue;
		}
		else if (rt[u] && rt[v])
		{
			q[k + 1][1].push_back(q[k][op][i]);
			continue;
		}
		u = pos[u], v = pos[v];
		ans[aid] = min(d[u][1] + d[v][1], d[u][0] + d[v][0]);
	}
	for (auto v : vc[k][op])
	{
		lf[v] = rt[v] = 0;
		ok[v] = 0;
	}
	solve(k + 1, 0);
	solve(k + 1, 1);
}
int main()
{
#ifndef _Aya
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
#endif // !_Aya
	int n, m, u, v;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		vc[0][0].push_back(i);//加入所有的点
	for (int i = 1; i <= n - 3; ++i)
	{
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		e[0][0].push_back({ u,v });//加入n-3条边
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		if (u == v)
			continue;
		q[0][0].push_back({ u,v,i });//加入询问的点对
	}
	solve(0, 0);
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
