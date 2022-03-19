#include <bits/stdc++.h>
using namespace std;
unordered_set<string>s;
string str;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str;
		for (int i = 1; i < str.size(); ++i)
			if (str[i] == '/')
				s.insert(str.substr(0, i));
		s.insert(str);
		cout << s.size() << endl;
	}
	return 0;
}