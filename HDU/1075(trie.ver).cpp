#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
unordered_map<int, int> trie[N];
vector<string>vec;
int cntword[N];
int cnt, strcnt;
void insert(string& s, int v)
{
	int root = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int nxt = s[i] - 'a';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	cntword[root] = v;
}
int get(string& s)
{
	int root = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int nxt = s[i] - 'a';
		if (!trie[root][nxt])
			return 0;
		root = trie[root][nxt];
	}
	return cntword[root];
}
string s, t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	while (cin >> s && s != "END")
	{
		cin >> t;
		vec.push_back(s);
		insert(t, ++strcnt);
	}
	cin >> s;
	getline(cin, s);
	while (getline(cin, s) && s != "END")
	{
		t = "";
		int pos;
		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i]))
				t += s[i];
			else
			{
				cout << ((pos = get(t)) ? vec[pos - 1] : t);
				t.clear();
				cout << s[i];
			}
		}
		cout << ((pos = get(t)) ? vec[pos - 1] : t) << endl;
	}
	return 0;
}