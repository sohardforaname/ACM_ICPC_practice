#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 35;
struct Trie
{
	int tr[MAXN * MAXM][2];
	int cnt = 0;
	void init()
	{
		cnt = 0;
		memset(tr, 0, sizeof(tr));
	}
	void insert(ll num, int k)
	{
		int root = 0;
		for (int i = k - 1; i >= 0; --i)
		{
			int c = num >> i & 1ll;
			if (!tr[root][c])
				tr[root][c] = ++cnt;
			root = tr[root][c];
		}
	}
	ll query(ll num, int k)
	{
		ll ans = 0;
		int now = 0;
		for (int i = k - 1; i >= 0; --i)
		{
			int c = num >> i & 1ll;
			if (tr[now][c ^ 1])
				now = tr[now][c ^ 1], ans |= ll(c ^ 1) << i;
			else
				now = tr[now][c], ans |= ll(c) << i;
		}
		return ans;
	}
};
Trie tr;
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		tr.init();
		int n, m;
		ll t;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &t), tr.insert(t, 33);
		printf("Case #%d:\n", i);
		for (int i = 1; i <= m; ++i)
		{
			scanf("%lld", &t);
			printf("%lld\n", tr.query(t, 33));
		}
	}
	return 0;
}