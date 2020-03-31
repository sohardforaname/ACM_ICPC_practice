#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
map<string, int>mp;
map<pair<int, int>, int>pmp;
int table[15][10005];
int cnt = 0;
int getID(string& str)
{
	if (mp.count(str))
		return mp[str];
	return mp[str] = ++cnt;
}
void input(int n, int m)
{
	int pos;
	string str, tmp;
	memset(table, 0, sizeof(table));
	mp.clear();
	cnt = 0;
	getchar();
	for (int i = 1; i <= n; ++i)
	{
		getline(cin, str);
		pos = 0;
		tmp = "";
		for (auto& j : str)
		{
			if (j != ',')
				tmp += j;
			else
				table[++pos][i] = getID(tmp), tmp = "";
		}
		table[++pos][i] = getID(tmp);
	}
}
int main()
{
#ifdef _Aya
	freopen("D:\\out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m)
	{
		input(n, m);
		pair<int, int>ptmp;
		for (int i = 1; i <= m; ++i)
			for (int j = i + 1; j <= m; ++j)
			{
				pmp.clear();
				for (int k = 1; k <= n; ++k)
				{
					ptmp = make_pair(table[i][k], table[j][k]);
					if (!pmp.count(ptmp))
						pmp[ptmp] = k;
					else
					{
						cout << "NO" << endl;
						cout << pmp[ptmp] << " " << k << endl;
						cout << i << " " << j << endl;
						goto lab;
					}
				}
			}
		cout << "YES" << endl;
	lab:;
	}
	return 0;
}
