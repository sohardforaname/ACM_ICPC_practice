#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 5;
const int MAXM = 1e5 + 5;
bitset<32>b[MAXM];
bitset<32>t;
struct Trie
{
	int tr[MAXN][2];
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
		int now = 0;
		t.reset();
		for (int i = len - 1; i >= 0; --i)
		{
			if (tr[now][s[i] ^ 1])
				now = tr[now][s[i] ^ 1], t[i] = 1;
			else
				now = tr[now][s[i]], t[i] = 0;
		}
		int ans = t.to_ulong();
		return ans;
	}
};
Trie tr;
int main()
{
	int n, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a), b[i] = a;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i > 1)
			ans = max(ans, tr.query(b[i], 32));
		tr.insert(b[i], 32);
	}
	printf("%d\n", ans);
	return 0;
}