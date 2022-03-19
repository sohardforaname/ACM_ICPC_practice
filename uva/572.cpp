#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
bool G[N][N], vis[N][N];
int dir[8][2] = { 0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,-1,-1,1 };
int cnt = 0;
int n, m;
bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs(int x, int y)
{
	++cnt;
	queue<pair<int, int> >q;
	q.push({ x,y });
	vis[x][y] = 1;
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		x = now.first, y = now.second;
		for (int i = 0; i < 8; ++i)
		{
			int dx = x + dir[i][0], dy = y + dir[i][1];
			if (check(dx, dy) && !vis[dx][dy] && G[dx][dy])
				q.push({ dx,dy }), vis[dx][dy] = 1;
		}
	}
}
char s[N];
int main()
{
	while (scanf("%d%d", &n, &m) && n + m)
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", s + 1);
			for (int j = 1; j <= m; ++j)
				G[i][j] = s[j] == '@' ? 1 : 0, vis[i][j] = 0;
		}
		cnt = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (G[i][j] && !vis[i][j])
					bfs(i, j);
		printf("%d\n", cnt);
	}
	return 0;
}
