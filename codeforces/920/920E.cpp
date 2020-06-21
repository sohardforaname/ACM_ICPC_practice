#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> G[MAXN];
struct node
{
	int pre, nxt;
};
node l[MAXN];
queue<int> q;
void init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		l[i - 1].nxt = i;
		l[i].pre = i - 1;
	}
	l[n].nxt = 0;
}
void del(int i)
{
	l[l[i].pre].nxt = l[i].nxt;
	l[l[i].nxt].pre = l[i].pre;
}
int cnt, top = 0;
int ans[MAXN];
bool vis1[MAXN], vis2[MAXN]; //和原图有没有边，是否被访问
void bfs()
{
	while (l[0].nxt)
	{
		cnt = 1;
		int now = l[0].nxt;
		q.push(now);
		del(now);
		vis2[now] = 1;
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			for (auto i : G[now])
				vis1[i] = 1;
			for (int i = l[0].nxt; i; i = l[i].nxt)
				if (!vis1[i] && !vis2[i])
				{
					++cnt;
					q.push(i);
					del(i);
					vis2[i] = 1;
				}
			for (auto i : G[now])
				vis1[i] = 0;
		}
		ans[++top] = cnt;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	int a, b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs();
	printf("%d\n", top);
	sort(ans + 1, ans + top + 1);
	for (int i = 1; i <= top; ++i)
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}