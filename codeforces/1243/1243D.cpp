#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int>G[MAXN];
struct node
{
	int pre, nxt;
};
node l[MAXN];
queue<int>q;
bool vis1[MAXN], vis2[MAXN];
int top = 0;
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
void bfs()
{
	while (l[0].nxt)
	{
		int now = l[0].nxt;
		vis2[now] = 1;
		q.push(now);
		del(now);
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			for (auto i : G[now])
				vis1[i] = 1;
			for (int i = l[0].nxt; i; i = l[i].nxt)
				if (!vis1[i] && !vis2[i])
				{
					q.push(i);
					del(i);
					vis2[i] = 1;
				}
			for (auto i : G[now])
				vis1[i] = 0;
		}
		++top;
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
	printf("%d\n", top - 1);
	return 0;
}