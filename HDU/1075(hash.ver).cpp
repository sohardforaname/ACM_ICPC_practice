#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string>mp;
string s, t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	while (cin >> s && s != "END")
	{
		cin >> t;
		mp[t] = s;
	}
	cin >> s;
	getline(cin, s);
	while (getline(cin, s) && s != "END")
	{
		int las = 0;
		t = "";
		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i]))
				t += s[i];
			else
			{
				if (mp[t] == "")
					cout << t;
				else
					cout << mp[t];
				t.clear();
				cout << s[i];
			}
		}
		cout << (mp[t] != "" ? mp[t] : t) << endl;
	}
	return 0;
}