#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 1e4 + 5;
int fail[MAXN];
int a[MAXN], b[MAXM];
void getfail(int lenb)
{
	fail[0] = -1;
	int j = -1, k = 0;
	while (k < lenb)
	{
		if (j == -1 || b[j] == b[k])
			fail[++k] = ++j;
		else
			j = fail[j];
	}
}
int getpos(int lena, int lenb)
{
	int j = 0, k = 0;
	while (j < lena)
	{
		if (k == -1 || a[j] == b[k])
			++j, ++k;
		else
			k = fail[k];
		if (k == lenb)
			return j - lenb + 1;
	}
	return -1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		getfail(m);
		printf("%d\n", getpos(n, m));
	}
	return 0;
}