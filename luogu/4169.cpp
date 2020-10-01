#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
const int MAXM = 1e6 + 5;

const int MAXBUF = 1 << 20;
char buf[1 << 20], *fh = NULL, *ft = NULL;
inline char gc()
{
	if (fh == ft)
	{
		int l = fread(buf, 1, MAXBUF, stdin);
		ft = (fh = buf) + l;
	}
	return *fh++;
}

inline int read()
{
	int x = 0;
	char c = gc();
	for (; c < '0' || c > '9'; c = gc())
		;
	for (; c >= '0' && c <= '9'; c = gc())
		x = (x << 3) + (x << 1) + c - '0';
	return x;
}
inline void _write(long long x)
{
	if (x > 9)
		_write(x / 10);
	putchar(x % 10 + '0');
}
inline void write(long long x)
{
	_write(x);
	putchar('\n');
}

struct node
{
	int x, y, kind;
	int id;
	node(int _x, int _y) : x(_x), y(_y) {}
	node() {}
	bool operator<(const node &a) const
	{
		return x == a.x ? y < a.y : x < a.x;
	}
};
node s1[MAXN], s2[MAXN], b[MAXN];
int d[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int ans[MAXN], n, m, tot, t;
struct BIT
{
	int c[MAXM];
	void init()
	{
		for (int i = 0; i < MAXM; ++i)
			c[i] = -(1 << 30);
	}
	int lowbit(int x)
	{
		return x & (-x);
	}
	void upd(int pos, int n, int val)
	{
		for (pos; pos <= n; pos += lowbit(pos))
			c[pos] = max(c[pos], val);
	}
	int query(int pos)
	{
		int ans = -(1 << 30);
		for (pos; pos; pos -= lowbit(pos))
			ans = max(ans, c[pos]);
		return ans;
	}
};
BIT tr;
void cdq(int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	int i = l, j = mid + 1;
	int k = l;
	while (j <= r)
	{
		while (i <= mid && s2[i].x <= s2[j].x)
		{
			if (s2[i].kind == 1)
				tr.upd(s2[i].y, tot, s2[i].x + s2[i].y);
			b[k++] = s2[i++];
		}
		if (s2[j].kind == 2)
			ans[s2[j].id] = min(ans[s2[j].id], abs(s2[j].x + s2[j].y - tr.query(s2[j].y)));
		b[k++] = s2[j++];
	}
	for (int p = l; p < i; ++p)
		if (s2[p].kind == 1)
			for (int q = s2[p].y; q <= tot; q += tr.lowbit(q))
				tr.c[q] = -(1 << 30);
	while (i <= mid)
		b[k++] = s2[i++];
	for (int p = l; p <= r; ++p)
		s2[p] = b[p];
}
void solve()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			s2[j] = s1[j];
			if (d[i][0])
				s2[j].x = tot - s2[j].x;
			if (d[i][1])
				s2[j].y = tot - s2[j].y;
		}
		cdq(1, m);
	}
}
int main()
{
	//scanf("%d%d", &n, &m);
	n = read(), m = read();
	m += n;
	for (int i = 1; i <= n; ++i)
	{
		//scanf("%d%d", &s1[i].x, &s1[i].y);
		s1[i].x = read(), s1[i].y = read();
		s1[i].kind = 1;
		++s1[i].y, ++s1[i].x;
		s1[i].id = i;
	}
	for (int i = n + 1; i <= m; ++i)
	{
		//scanf("%d%d%d", &s1[i].kind, &s1[i].x, &s1[i].y);
		s1[i].kind = read();
		s1[i].x = read(), s1[i].y = read();
		++s1[i].y, ++s1[i].x;
		s1[i].id = i;
	}
	for (int i = 1; i <= m; ++i)
		tot = max(tot, s1[i].y);
	++tot;
	tr.init();
	memset(ans, 0x3f, sizeof(ans));
	solve();
	for (int i = 1; i <= m; ++i)
		if (s1[i].kind == 2)
			printf("%d\n", ans[i]);
	return 0;
}
