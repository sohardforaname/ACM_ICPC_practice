#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 155;
#define debug(x, n)                     \
	cout << #x << endl;                 \
	for (int ii = 1; ii <= n; ++ii)     \
		for (int jj = 1; jj <= n; ++jj) \
			cout << x.m[ii][jj] << " \n"[jj == n];
struct mat
{
	bitset<N> m[N];
};
mat mul(const mat &a, const mat &b, int n)
{
	mat res, tmp;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			tmp.m[i][j] = b.m[j][i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			res.m[i][j] = (a.m[i] & tmp.m[j]).any();
	return res;
}
mat pow(mat a, int p, int n)
{
	mat res;
	for (int i = 1; i <= n; ++i)
		res.m[i][i] = 1;
	while (p)
	{
		if (p & 1)
			res = mul(res, a, n);
		a = mul(a, a, n);
		p >>= 1;
	}
	return res;
}
mat G, res;
struct edge
{
	int u, v, d;
	bool operator<(const edge &a) const
	{
		return d < a.d;
	}
};
unsigned char dep[N];
int bfs(const mat &res, int n)
{
	memset(dep, 0, sizeof(dep));
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (res.m[1][i])
			q.push(i), dep[i] = 1;
	while (!q.empty())
	{
		int now = q.front();
		if (now == n)
			return dep[now] - 1;
		q.pop();
		for (int i = 1; i <= n; ++i)
			if (G.m[now][i] && !dep[i])
				q.push(i), dep[i] = dep[now] + 1;
	}
	return 0x3f3f3f3f;
}
edge e[N];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].d);
	sort(e + 1, e + m + 1);
	int minn = 0x3f3f3f3f;
	int p = 0; //已走过的边数
	if (e[1].d > 0)
		return printf("Impossible\n"), 0;
	res.m[1][1] = 1;
	for (int i = 1; i <= m; ++i)
	{
		int b = e[i].d - p;				 //求出差距
		res = mul(res, pow(G, b, n), n); //递推
		p = e[i].d;
		G.m[e[i].u][e[i].v] = 1; //加入边
		minn = min(minn, bfs(res, n) + p);
	}
	if (minn >= 0x3f3f3f3f)
		printf("Impossible\n");
	else
		printf("%d\n", minn);
	return 0;
}