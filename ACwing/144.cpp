#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int dis[MAXN];
vector<pair<int, int>>E[MAXN];
bitset<32>s, t;
void dfs(int fa, int x, int val)
{
	dis[x] = val ^ dis[fa];
	for (auto& i : E[x])
		if (i.first != fa)
			dfs(x, i.first, i.second);
}
struct Trie
{
	int tr[MAXN * 32][2];
	int cnt = 0;
	void insert(bitset<32>& s, int len)
	{
		int root = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			if (!tr[root][s[i]])
				tr[root][s[i]] = ++cnt;
			root = tr[root][s[i]];
		}
	}
	int query(bitset<32>& s, int len)
	{
		t.reset();
		int now = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			if (tr[now][s[i] ^ 1])
				now = tr[now][s[i] ^ 1], t[i] = 1;
			else
				now = tr[now][s[i]], t[i] = 0;
		}
		return t.to_ulong();
	}
};
Trie tr;
int main()
{
	int n;
	scanf("%d", &n);
	int a, b, c;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		E[a + 1].push_back({ b + 1,c });
		E[b + 1].push_back({ a + 1,c });
	}
	dfs(0, 1, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		s = dis[i];
		if (i > 1)
			ans = max(ans, tr.query(s, 32));
		tr.insert(s, 32);
	}
	printf("%d\n", ans);
	return 0;
}
