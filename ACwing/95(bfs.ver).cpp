#include <bits/stdc++.h>
using namespace std;
int mp[1 << 25];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool check(int x, int y)
{
	if (x < 0 || x > 4 || y < 0 || y > 4)
		return 0;
	return 1;
}
int _hash(int x, int i)
{
	int px = i / 5, py = i % 5;
	for (int i = 0; i < 4; ++i)
		if (check(px + dir[i][0], py + dir[i][1]))
			x ^= 1 << ((px + dir[i][0]) * 5 + py + dir[i][1]);
	x ^= (1 << i);
	return x;
}
void bfs()
{
	queue<int>que;
	mp[(1 << 25) - 1] = 1;
	que.push((1 << 25) - 1);
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		if (mp[u] == 7)
			return;
		for (int i = 0; i < 25; ++i)
		{
			int v = _hash(u, i);
			if (!mp[v])
			{
				mp[v] = mp[u] + 1;
				que.push(v);
			}
		}
	}
}
int main()
{
	bfs();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x = 0, a;
		for (int i = 0; i < 25; ++i)
		{
			scanf("%1d", &a);
			x ^= (a << i);
		}
		printf("%d\n", mp[x] - 1);
	}
	return 0;
}
