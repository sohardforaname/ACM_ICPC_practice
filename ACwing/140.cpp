#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
struct SA
{
	int n, m;
	int tax[MAXN], rank[MAXN], tp[MAXN], sa[MAXN];
	int height[MAXN];
	char s[MAXN];
	void sort()
	{
		for (int i = 0; i <= m; ++i)
			tax[i] = 0;
		for (int i = 1; i <= n; ++i)
			++tax[rank[i]];
		for (int i = 1; i <= m; ++i)
			tax[i] += tax[i - 1];
		for (int i = n; i >= 1; --i)
			sa[tax[rank[tp[i]]]--] = tp[i];
	}
	bool cmp(int a, int b, int k)
	{
		return tp[a] == tp[b] && tp[a + k] == tp[b + k];
	}
	void getsa()
	{
		n = strlen(s + 1);
		for (int i = 1; i <= n; ++i)
			m = max(m, rank[i] = s[i] - ' '), tp[i] = i;
		sort();
		for (int p = 0, j = 1; p < n; j <<= 1, m = p)
		{
			p = 0;
			for (int i = 1; i <= j; ++i)
				tp[++p] = n - j + i;
			for (int i = 1; i <= n; ++i)
				if (sa[i] > j)
					tp[++p] = sa[i] - j;
			sort();
			swap(rank, tp);
			rank[sa[1]] = p = 1;
			for (int i = 2; i <= n; ++i)
				rank[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		}
	}
	void getheight()
	{
		int k = 0;
		for (int i = 1; i <= n; ++i)
			rank[sa[i]] = i;
		for (int i = 1; i <= n; ++i)
		{
			if (rank[i] == 1)
				continue;
			if (k)
				--k;
			int j = sa[rank[i] - 1];
			while (j + k <= n && i + k <= n && s[j + k] == s[i + k])
				++k;
			height[rank[i]] = k;
		}
	}
};
SA sa;
int main()
{
	scanf("%s", sa.s + 1);
	sa.getsa();
	sa.getheight();
	int n = strlen(sa.s + 1);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", sa.sa[i] - 1, i == n ? '\n' : ' ');
	for (int i = 1; i <= n; ++i)
		printf("%d%c", sa.height[i], i == n ? '\n' : ' ');
	return 0;
}