#include <bits/stdc++.h>
using namespace std;
bool f[26];
string s, t;
int solve()
{
	cin >> s;
	t = string(1, s[0]);
	int pos = 0;
	memset(f, 0, sizeof(f));
	f[s[0] - 'a'] = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (f[s[i] - 'a'])
		{
			if (pos > 0 && t[pos - 1] == s[i])
				pos -= 1;
			else if (pos < t.size() - 1 && t[pos + 1] == s[i])
				pos += 1;
			else
				return cout << "NO\n", 0;
		}
		else
		{
			if (pos == 0)
				t = s[i] + t;
			else if (pos == t.size() - 1)
				pos += 1, t += s[i];
			else
				return cout << "NO\n", 0;
		}
		f[s[i] - 'a'] = 1;
	}
	for (int i = 0; i < 26; ++i)
		if (!f[i])
			t += (i + 'a');
	cout << "YES\n" << t << '\n';
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}