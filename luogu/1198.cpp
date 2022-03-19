#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
#define N 200005
#define max(a,b) (a>b?a:b)
long long t = 0;
long long d;
long long INF = 0x7fffffffffffffff;
struct node
{
	int l, r;
	long long val;
}tr[N * 4];
void build(int l, int r, int k)
{
	tr[k].l = l, tr[k].r = r;
	if (l == r)
	{
		tr[k].val = -INF;
		return;
	}
	int m = (l + r) / 2;
	build(l, m, k * 2);
	build(m + 1, r, k * 2 + 1);
}
void update(int l, int r, int k, long long val)
{
	if (l <= tr[k].l && r >= tr[k].r)
	{
		tr[k].val = val;
		return;
	}
	int m = (tr[k].l + tr[k].r) / 2;
	if (l <= m)
		update(l, r, k * 2, val);
	if (r >= m + 1)
		update(l, r, k * 2 + 1, val);
	tr[k].val = max(tr[k * 2].val, tr[k * 2 + 1].val);
}
long long ask(int l, int r, int k)
{
	if (l <= tr[k].l && r >= tr[k].r)
		return tr[k].val;
	int m = (tr[k].l + tr[k].r) / 2;
	long long ans = -INF;
	if (l <= m)
		ans = max(ans, ask(l, r, k * 2));
	if (r >= m + 1)
		ans = max(ans, ask(l, r, k * 2 + 1));
	return ans;
}
int main()
{
	int n;
	scanf("%d%lld", &n, &d);
	build(1, 200005, 1);
	int pos = 1;
	char ch[3];
	long long num;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %lld", ch, &num);
		if (ch[0] == 'A')
		{
			update(pos, pos, 1, (num + t) % d);
			++pos;
		}
		else if (ch[0] == 'Q')
		{
			t = ask(pos - num, pos - 1, 1) % d;
			printf("%lld\n", t);
		}
	}
	return 0;
}