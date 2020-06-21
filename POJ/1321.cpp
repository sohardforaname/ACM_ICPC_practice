#include <iostream>
#include <cstring>
using namespace std;
int n, k, cnt;
bool g[20][20];
bool ocp[20];
void dfs(int dep, int s) //在第dep层的第pos个位置放下第s个
{
	if (s >= k)
	{
		//cout<<dep<<endl;
		++cnt;
		return;
	}
	//if(dep==n)
	//return;
	for (int i = dep; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (ocp[j] == 0 && g[i][j])
			{
				ocp[j] = 1;
				dfs(i + 1, s + 1);
				ocp[j] = 0;
			}
		}
	}
	return;
}
int main()
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		memset(g, 0, sizeof(g));
		memset(ocp, 0, sizeof(ocp));
		cnt = 0;
		char ch;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				cin >> ch;
				if (ch == '.')
					g[i][j] = 0;
				else if (ch == '#')
					g[i][j] = 1;
			}
		dfs(0, 0);
		cout << cnt << endl;
	}
	return 0;
}
