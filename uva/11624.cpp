#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool G[N][N];
int jdep[N][N], fdep[N][N];
int n, m;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<pair<int, int> >p;
bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m && G[x][y];
}
void bfs()
{
	int x, y;
	queue<pair<int, int> >q;
	for (int i = 0; i < p.size(); ++i)
	{
		x = p[i].first, y = p[i].second;
		q.push({ x,y });
		fdep[x][y] = 1;
	}
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		x = now.first, y = now.second;
		for (int i = 0; i < 4; ++i)
		{
			int dx = x + dir[i][0], dy = y + dir[i][1];
			if (check(dx, dy) && !fdep[dx][dy])
				q.push({ dx,dy }), fdep[dx][dy] = fdep[x][y] + 1;
		}
	}
}
int find(int x, int y)
{
	queue<pair<int, int> >q;
	q.push({ x,y });
	jdep[x][y] = 1;
	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		x = now.first, y = now.second;
		if (x == 1 || x == n || y == 1 || y == m)
			return jdep[x][y];
		for (int i = 0; i < 4; ++i)
		{
			int dx = x + dir[i][0], dy = y + dir[i][1];
			if (check(dx, dy) && !jdep[dx][dy])
			{
				jdep[dx][dy] = jdep[x][y] + 1;
				if (!fdep[dx][dy] || jdep[dx][dy] < fdep[dx][dy])
					q.push({ dx,dy });
			}
		}
	}
	return -1;
}
void init(int n, int m)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			jdep[i][j] = fdep[i][j] = 0;
	p.clear();
}
char s[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int jx = 0, jy = 0;
		scanf("%d%d", &n, &m);
		init(n, m);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", s + 1);
			for (int j = 1; j <= m; ++j)
			{
				G[i][j] = s[j] == '#' ? 0 : 1;
				if (s[j] == 'J')
					jx = i, jy = j;
				else if (s[j] == 'F')
					p.push_back({ i,j });
			}
		}
		bfs();
		int ans = find(jx, jy);
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}