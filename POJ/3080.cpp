#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int nextarray[65];
string str[15];
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
	string s;
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j)
			cin >> str[j];
		string ans = "";
		for (int j = 0; j < str[0].size(); ++j)
			for (int k = 1; k + j <= str[0].size(); ++k)
			{
				s = str[0].substr(j, k);
				getnext(s);
				bool flag = 0;
				for (int l = 1; l < m; ++l)
					//cout << kmp(str[l], s) << " " << str[l] << " " << s << endl;
					if (!kmp(str[l], s))
						flag = 1;
				//cout << flag << endl;
				if (!flag)
				{
					if (ans.size() < s.size())
						ans = s;
					else if (ans.size() == s.size() && ans > s)
						ans = s;
					//cout << ans << endl;
				}
			}
		if (ans.size() < 3)
			cout << "no significant commonalities" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}