#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 1005;
map<int, int>mp;
queue<int>q1, q2[MAXN];
int main()
{
#ifdef _Aya
	freopen("D:\\out.txt", "w", stdout);
#endif
	int n, m, t, c = 0;
	string str;
	while (cin >> n && n)
	{
		cout << "Scenario #" << ++c << endl;
		for (int i = 0; i < n; ++i)
		{
			cin >> m;
			for (int j = 0; j < m; ++j)
			{
				cin >> t;
				mp[t] = i;
			}
		}
		while (q1.size())
			q1.pop();
		for (int i = 0; i < n; ++i)
			while (q2[i].size())
				q2[i].pop();
		while (cin >> str && str[0] != 'S')
		{
			if (str[0] == 'E')
			{
				cin >> t;
				int g = mp[t];
				if (!q2[g].size())
					q1.push(g);
				q2[g].push(t);
			}
			else
			{
				int g = q1.front();
				cout << q2[g].front() << endl;
				if (q2[g].size() <= 1)
					q1.pop();
				q2[g].pop();
			}
		}
		cout << endl;
	}
	return 0;
}
