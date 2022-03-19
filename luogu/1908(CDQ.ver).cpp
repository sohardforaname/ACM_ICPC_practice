#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
struct node
{
	int id, op, a, b;
	node() {}
	node(int _id, int _op, int _a, int _b) : id(_id), op(_op), a(_a), b(_b) {}
};
node q[N << 1], q1[N << 1];
//0/1->change/query
bool cmpa(const node &a, const node &b)
{
	return a.a == b.a ? a.op < b.op : a.a < b.a;
}
bool cmpb(const node &a, const node &b)
{
	return a.b == b.b ? a.op > b.op : a.b > b.b;
}
int ans[N];
void solve(int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) >> 1;
	solve(l, m);
	solve(m + 1, r);
	merge(q + l, q + m + 1, q + m + 1, q + r + 1, q1 + l, cmpb);
	memcpy(q + l, q1 + l, sizeof(node) * (r - l + 1));
	int cnt = 0;
	for (int i = l; i <= r; ++i)
	{
		if (q[i].op == 0 && q[i].a <= m)
			++cnt;
		else if (q[i].op == 1 && q[i].a > m)
			ans[q[i].id] += cnt;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		q[i] = {0, 0, i, x};
		q[i + n] = {i, 1, i, x};
	}
	sort(q + 1, q + 2 * n + 1, cmpa);
	for (int i = 1; i <= 2 * n; ++i)
		q[i].a = i;
	solve(1, 2 * n);
	ll cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += ans[i];
	printf("%lld\n", cnt);
	return 0;
}