#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string s[10005];
int getmin(string &str)
{
	int i = 0, j = 1, k = 0;
	while (i < str.size() && j < str.size() && k < str.size())
	{
		int t = str[(i + k) % str.size()] - str[(j + k) % str.size()];
		if (t == 0)
			++k;
		else
		{
			if (t > 0)
				i += k + 1;
			else if (t < 0)
				j += k + 1;
			if (i == j)
				++j;
			k = 0;
		}
	}
	return i < j ? i : j;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, minpos;
	string tmp;
	vector<int>ans;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
			minpos = getmin(s[i]);
			tmp = s[i].substr(0, minpos);
			s[i] = s[i].substr(minpos, s[i].size() - minpos);
			s[i] = s[i] + tmp;
		}
		sort(s, s + n);
		ans.clear();
		tmp = s[0];
		int t = 1;
		for (int i = 1; i < n; ++i)
		{
			if (s[i] == tmp)
				++t;
			else
			{
				ans.push_back(t);
				t = 1; tmp = s[i];
			}
		}
		ans.push_back(t);
		cout << ans.size() << endl;
	}
	return 0;
}