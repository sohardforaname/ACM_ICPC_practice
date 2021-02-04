#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int nxt[MAXN], extend[MAXN];
void getnext(string &t)
{
	nxt[0] = t.size();
	int now = 0;
	while (now + 1 < t.size() && t[now] == t[now + 1])
		++now;
	nxt[1] = now;
	int mx = 1;
	for (int i = 2; i < t.size(); ++i)
	{
		if (i + nxt[i - mx] < nxt[mx] + mx) //the first situation
			nxt[i] = nxt[i - mx];
		else
		{
			int now = nxt[mx] + mx - i;
			now = max(now, 0);
			while (i + now < t.size() && t[now] == t[now + i])
				++now;
			nxt[i] = now;
			mx = i;
		}
	}
}
void exkmp(string &s, string &t)
{
	int now = 0;
	while (now < min(s.size(), t.size()) && s[now] == t[now])
		++now;
	extend[0] = now;
	int mx = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (i + nxt[i - mx] < extend[mx] + mx) //the first situation
			extend[i] = nxt[i - mx];
		else
		{
			int now = extend[mx] + mx - i;
			now = max(now, 0);
			while (now < t.size() && now + i < s.size() && t[now] == s[now + i])
				++now;
			extend[i] = now;
			mx = i;
		}
	}
}
string s, t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	getnext(t);
	exkmp(s, t);
	for (int i = 0; i < t.size(); ++i)
		printf("%d%c", nxt[i], i == t.size() - 1 ? '\n' : ' ');
	for (int i = 0; i < s.size(); ++i)
		printf("%d%c", extend[i], i == s.size() - 1 ? '\n' : ' ');
	return 0;
}