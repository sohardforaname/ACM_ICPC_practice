#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
char map[15][15];
int dep1[105], dep2[105], d[105];
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
bool check(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	if (map[x][y] == '.')
		return false;
	return true;
}
void bfs(int s, int *dep)
{
	queue<int> que;
	dep[s] = 1;
	que.push(s);
	while (!que.empty())
	{
		int u = que.front();
		//cout<<u<<endl;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = u / m, y = u % m;
			int v = (x + dir[i][0]) * m + y + dir[i][1];
			if (!dep[v] && check(x + dir[i][0], y + dir[i][1]))
			{
				dep[v] = dep[u] + 1;
				que.push(v);
			}
		}
	}
	int ans = 0;
	//	for(int i=0;i<n*m;++i)
	//		cout<<dep[i]<<" ";
	//	cout<<endl;
}
int solve()
{
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n * m; ++i)
		for (int j = i; j < n * m; ++j)
		{
			//cout<<map[i/m][i%m]<<" "<<map[j/m][j%m]<<endl;
			if (map[i / m][i % m] == '#' && map[j / m][j % m] == '#')
			{
				int b = 0;
				bool flag = 0;
				memset(dep1, 0, sizeof(dep1));
				memset(dep2, 0, sizeof(dep2));
				bfs(i, dep1), bfs(j, dep2);
				for (int k = 0; k < n * m; ++k)
				{
					if (dep1[k] && dep2[k])
						d[k] = min(dep2[k], dep1[k]);
					else
						d[k] = dep1[k] + dep2[k];
				}
				for (int k = 0; k < n * m; ++k)
					if (d[k])
						b = max(b, d[k]);
				//cout<<b<<endl;
				//cout<<endl;
				for (int k = 0; k < n * m; ++k)
					if (map[k / m][k % m] == '#' && !dep1[k] && !dep2[k])
						flag = 1;
				//cout<<"ok1"<<endl;
				if (!flag)
					ans = min(ans, b);
			}
		}
	//cout<<"ok2"<<endl;
	return ans - 1;
}
int main()
{
	int c;
	cin >> c;
	for (int ca = 0; ca < c; ++ca)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> map[i][j];
		/*for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)	
				cout<<map[i][j];
			cout<<endl;	
		}*/
		//cout<<"ok"<<endl;
		int s = solve();
		cout << "Case " << ca + 1 << ": ";
		if (s >= 0x3f3f3f)
			cout << -1 << endl;
		else
			cout << s << endl;
	}
	return 0;
}
