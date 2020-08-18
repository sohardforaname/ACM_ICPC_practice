#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node
{
	int id, op, a, b, c;
	node() {}
	node(int _id, int _op, int _a, int _b, int _c)
		: id(_id), op(_op), a(_a), b(_b), c(_c) {}
};
// 0/1->change/query
node q[N], q1[N];
struct BIT
{
	int m[N];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int x, int n, int val)
	{
		for (; x <= n; x += lowbit(x))
			m[x] += val;
	}
	int query(int x, int n)
	{
		int ans = 0;
		for (; x; x -= lowbit(x))
			ans += m[x];
		return ans;
	}
};
bool cmpa(const node &a, const node &b)
{
	return a.a == b.a ? a.op < b.op : a.a < b.a;
}
bool cmpb(const node &a, const node &b)
{
	return a.b == b.b ? a.op < b.op : a.b < b.b;
}

int ans[N], cnt[N];
BIT tr;
int n, k;
void solve(int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) >> 1;
	solve(l, m);
	solve(m + 1, r);
	merge(q + l, q + m + 1, q + m + 1, q + r + 1, q1 + l, cmpb);
	memcpy(q + l, q1 + l, sizeof(node) * (r - l + 1));
	for (int i = l; i <= r; ++i)
	{
		if (q[i].op == 0 && q[i].a <= m)
			tr.update(q[i].c, k, 1);
		else if (q[i].op == 1 && q[i].a > m)
			ans[q[i].id] += tr.query(q[i].c, 2e5);
	}
	for (int i = l; i <= r; ++i)
		if (q[i].op == 0 && q[i].a <= m)
			tr.update(q[i].c, k, -1);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
		q[i].id = q[i].op = 0;
		q[i + n] = q[i];
		q[i + n].id = i;
		q[i + n].op = 1;
	}
	sort(q + 1, q + n * 2 + 1, cmpa);
	for (int i = 1; i <= n * 2; ++i)
		q[i].a = i;
	solve(1, 2 * n);
	for (int i = 1; i <= n; ++i)
		++cnt[--ans[i]];
	for (int i = 0; i < n; ++i)
		printf("%d\n", cnt[i]);
	return 0;
}