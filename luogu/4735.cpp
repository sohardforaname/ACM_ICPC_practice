#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
const int MAXM = 24;
int s[MAXN];
struct Trie
{
	int tr[MAXN * MAXM][2];
	int latest[MAXN * MAXM];
	int root[MAXN], cnt = 0;
	void init()
	{
		root[0] = ++cnt;
		latest[0] = -1;
	}
	void insert(int i, int k, int x, int f)
	{
		if (k < 0)
		{
			latest[x] = i;
			return;
		}
		int c = s[i] >> k & 1;
		if (x)
			tr[x][c ^ 1] = tr[f][c ^ 1];
		tr[x][c] = ++cnt;
		insert(i, k - 1, tr[x][c], tr[f][c]);
		latest[x] = max(latest[tr[x][0]], latest[tr[x][1]]);
	}
	int query(int now, int val, int k, int l)
	{
		if (k < 0)
			return s[latest[now]] ^ val;
		int c = val >> k & 1;
		if (latest[tr[now][c ^ 1]] >= l)
			return query(tr[now][c ^ 1], val, k - 1, l);
		else
			return query(tr[now][c], val, k - 1, l);
	}
};
Trie tr;
char op[2];
int main()
{
	tr.init();
	int n, m, t;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &t);
		s[i] = s[i - 1] ^ t;
		tr.root[i] = ++tr.cnt;
		tr.insert(i, 24, tr.root[i], tr.root[i - 1]);
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", op);
		if (op[0] == 'A')
		{
			scanf("%d", &t);
			tr.root[++n] = ++tr.cnt;
			s[n] = s[n - 1] ^ t;
			tr.insert(n, 24, tr.root[n], tr.root[n - 1]);
		}
		else if (op[0] == 'Q')
		{
			int l, r;
			scanf("%d%d%d", &l, &r, &t);
			printf("%d\n", tr.query(tr.root[r - 1], t ^ s[n], 24, l - 1));
		}
	}
	return 0;
}