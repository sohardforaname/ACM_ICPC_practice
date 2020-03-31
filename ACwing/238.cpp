#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 5;
struct Joint
{
	int fa[MAXN], d[MAXN], sz[MAXN];//d[x]为x到fa[x]的权值和
	void init(int n)
	{
		for (int i = 0; i <= n; ++i)
		{
			fa[i] = i;
			d[i] = 0;
			sz[i] = 1;
		}
	}
	int find(int x)
	{
		if (x == fa[x])
			return x;
		int rt = find(fa[x]);
		d[x] += d[fa[x]];
		return fa[x] = rt;
	}
	void join(int x, int y)
	{
		x = find(x), y = find(y);
		fa[x] = y, d[x] = sz[y];
		sz[y] += sz[x];
	}
};
Joint s;
char op[2];
int main()
{
	int n;
	scanf("%d", &n);
	s.init(MAXN);
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'M')
			s.join(x, y);
		else if (op[0] == 'C')
		{
			if (s.find(x) == s.find(y))
				printf("%d\n", abs(s.d[x] - s.d[y]) - 1);
			else
				printf("-1\n");
		}
	}
	return 0;
}