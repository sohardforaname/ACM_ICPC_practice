#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int nextarray[205];
string strt[4005];
void getnext(string &str)
{
	//memset(nextarray, 0, sizeof(nextarray));
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
	cin.tie(0);
	string str1, tmp, ans;
	int n;
	while (cin >> n && n)
	{
		ans = "";
		int m = n;
		for (int i = 0; i < m; ++i)
			cin >> strt[i];
		//sort(strt, strt + m);
		str1 = strt[0];
		bool flag;
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 1; i + j <= str1.size(); ++j)
			{
				flag = 0;
				tmp = str1.substr(i, j);
				if (tmp.size() < ans.size())
					continue;
				getnext(tmp);
				for (int k = 1; k < m; ++k)
					if (!kmp(strt[k], tmp))
						flag = 1;
				if (!flag)
				{
					if (ans.size() < tmp.size())
						ans = tmp;
					else if (ans.size() == tmp.size() && ans > tmp)
						ans = tmp;
				}
			}
		}
		if (ans.size())
			cout << ans << endl;
		else
			cout << "IDENTITY LOST" << endl;
	}
	return 0;
}