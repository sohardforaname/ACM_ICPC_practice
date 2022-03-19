#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 31;
struct Trie
{
	int tr[MAXN * MAXM][2];
	int cnt[MAXN * MAXM], tot = 0;
	void init()
	{
		for (int i = 0; i <= tot; ++i)
			tr[i][0] = tr[i][1] = cnt[i] = 0;
		tot = 0;
	}
	void insert(int num, int len)
	{
		int root = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int c = num >> i & 1;
			if (!tr[root][c])
				tr[root][c] = ++tot;
			++cnt[tr[root][c]];
			root = tr[root][c];
		}
	}
	int query(int num, int len)
	{
		int now = 0, ans = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int c = num >> i & 1;
			if (tr[now][c ^ 1] && cnt[tr[now][c ^ 1]])
				now = tr[now][c ^ 1], ans |= 1 << i;
			else
				now = tr[now][c];
		}
		return ans;
	}
	void del(int num, int len)
	{
		int now = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			int c = num >> i & 1;
			--cnt[tr[now][c]];
			now = tr[now][c];
		}
	}
};
Trie tr;
int s[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		tr.init();
		for (int i = 1; i <= n; ++i)
			scanf("%d", &s[i]), tr.insert(s[i], 31);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			tr.del(s[i], 31);
			for (int j = i + 1; j <= n; ++j)
			{
				tr.del(s[j], 31);
				ans = max(ans, tr.query(s[i] + s[j], 31));
				tr.insert(s[j], 31);
			}
			tr.insert(s[i], 31);
		}
		printf("%d\n", ans);
	}
	return 0;
}