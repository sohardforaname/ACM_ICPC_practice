#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
char s[N];
bool f[N];
vector<int> pre, suf;
vector<vector<int>> v;
void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int ans = 0;
	while (1)
	{
		pre.clear();
		suf.clear();
		for (int i = 1; i <= n; ++i)
			if (!f[i] && s[i] == '(')
				pre.push_back(i), f[i] = 1;
		for (int i = n; i >= 1; --i)
			if (!f[i] && s[i] == ')')
				suf.push_back(i), f[i] = 1;
		int cnt = 0;
		while (cnt < min(pre.size(), suf.size()) && pre[cnt] < suf[cnt])
			++cnt;
		if (!pre.size() || !suf.size() || !cnt)
			break;
		v.push_back(vector<int>());
		for (int i = 0; i < cnt; ++i)
			v[ans].push_back(pre[i]);
		for (int i = cnt - 1; i >= 0; --i)
			v[ans].push_back(suf[i]);
		++ans;
	}
	printf("%d\n", v.size());
	for (auto &i : v)
	{
		printf("%d\n", i.size());
		for (int j = 0; j < i.size(); ++j)
			printf("%d%c", i[j], " \n"[j == i.size()]);
	}
}
int main()
{
	int t = 1;
	//scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}