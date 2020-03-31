#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
unordered_map<string, int> trie[N];
string s, tmp;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		int las = 0;
		int root = 0;
		for (int i = 1; i < s.size(); ++i)
			if (s[i] == '/')
			{
				tmp = s.substr(las, i - las);
				if (trie[root][tmp] == 0)
					trie[root][tmp] = ++cnt;
				root = trie[root][tmp];
				las = i;
			}
		tmp = s.substr(las, s.size() - las);
		if (trie[root][tmp] == 0)
			trie[root][tmp] = ++cnt;
		cout << cnt << endl;
	}
	return 0;
}