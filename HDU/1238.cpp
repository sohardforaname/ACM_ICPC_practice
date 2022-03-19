#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int nextarray[105];
string strt[105];
void getnext(string &str)
{
	memset(nextarray, 0, sizeof(nextarray));
	int j = -1, k = 0;
	nextarray[0] = -1;
	while (k < str.size())
	{
		if (j == -1 || str[j] == str[k])
			nextarray[++k] = ++j;
		else
			j = nextarray[j];
	}
}
bool kmp(string &a, string &b)
{
	int i = 0, j = 0, ans = 0;
	while (i < a.size())
	{
		if (j == -1 || a[i] == b[j])
			++i, ++j;
		else
			j = nextarray[j];
		if (j == b.size())
			++ans, j = nextarray[j];
	}
	if (ans)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	string str1, tmp;
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> strt[i];
		sort(strt, strt + m);
		str1 = strt[0];
		int ans = 0;
		bool flag;
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 1; i + j <= str1.size(); ++j)
			{
				flag = 0;
				tmp = str1.substr(i, j);
				getnext(tmp);
				for (int k = 1; k < m; ++k)
					if (!kmp(strt[k], tmp))
						flag = 1;
				if (!flag)
					ans = max(int(tmp.size()), ans);

			}
		}
		reverse(str1.begin(), str1.end());
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 1; i + j <= str1.size(); ++j)
			{
				flag = 0;
				tmp = str1.substr(i, j);
				getnext(tmp);
				for (int k = 1; k < m; ++k)
					if (!kmp(strt[k], tmp))
						flag = 1;
				if (!flag)
					ans = max(int(tmp.size()), ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}