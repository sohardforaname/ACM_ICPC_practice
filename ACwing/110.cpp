#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2.5e3 + 5;
struct cow
{
	int minn, maxn;
	bool operator<(const cow& a)const
	{
		return minn == a.minn ? maxn > a.maxn : minn > a.minn;
	}
};
cow c[MAXN];
int num[MAXN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &c[i].minn, &c[i].maxn);
	int a, b;
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &a, &b), num[a] += b;
	int cnt = 0;
	sort(c, c + n);
	for (int i = 0; i < n; ++i)
	{
		int maxpos = -1;
		for (int j = c[i].minn; j <= c[i].maxn; ++j)
			if (num[j] && j > maxpos)
				maxpos = j;
		if (maxpos > -1)
			++cnt, --num[maxpos];
	}
	printf("%d\n", cnt);
	return 0;
}
