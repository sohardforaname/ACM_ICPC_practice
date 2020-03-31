#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int tag[12][12];
char ch[12][12];
int main()
{
	int n, m, kase = 1;
	while (cin >> n && n)
	{
		memset(tag, 0, sizeof(tag));
		cin >> m;
		string a;
		getchar();
		for (int i = 0; i < n; ++i)
		{
			getline(cin, a);
			for (int j = 0; j < m; ++j)
				ch[i][j] = a[j];
		}
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (ch[i][j] == '*')
					continue;
				if (j - 1 < 0 || ch[i][j - 1] == '*' || i - 1 < 0 || ch[i - 1][j] == '*')
					tag[i][j] = ++index;
			}
		}
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << ch[i][j] << " ";
			cout << endl;
		}*/
		if (kase > 1)
			cout << endl;
		cout << "puzzle #" << kase++ << ":" << endl;
		cout << "Across" << endl;
		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			while (j < m)
			{
				if (tag[i][j] == 0 || ch[i][j] == '*')
				{
					++j;
					continue;
				}
				printf("%3d.%c", tag[i][j], ch[i][j]);
				++j;
				while (j < m && ch[i][j] != '*')
				{
					cout << ch[i][j];
					++j;
				}
				cout << endl;
			}
		}
		cout << "Down" << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (tag[i][j] == 0 || ch[i][j] == '*')
				{
					continue;
				}
				printf("%3d.%c", tag[i][j], ch[i][j]);
				int k = i + 1;
				tag[i][j] = 0;
				while (k < n && ch[k][j] != '*')
				{
					cout << ch[k][j];
					tag[k][j] = 0;
					++k;
				}
				cout << endl;
			}
		}
	}
	return 0;
}