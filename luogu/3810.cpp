#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
struct node
{
	int a, b, c;
	int cnt = 0, ans = 0;
	node(){}
	node(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {};
};
node s1[MAXN], s2[MAXN];
int n, k, top, m;
int ans[MAXN];
bool cmp1d(const node& a, const node& b)
{
	if (a.a == b.a)
		return a.b == b.b ? a.c < b.c : a.b < b.b;
	return a.a < b.a;
}
bool cmp2d(const node& a, const node& b)
{
	return a.b == b.b ? a.c < b.c : a.b < b.b;
}
bool cmp(node& a, node& b)
{
	if (a.a != b.a)
		return true;
	if (a.b != b.b)
		return true;
	if (a.c != b.c)
		return true;
	return false;
}
struct BIT
{
	int c[MAXM];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void insert(int x, int n, int val)
	{
		for (x; x <= n; x += lowbit(x))
			c[x] += val;
	}
	int sum(int x)
	{
		int ans = 0;
		for (x; x; x -= lowbit(x))
			ans += c[x];
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
	sort(s2 + l, s2 + mid + 1, cmp2d);
	sort(s2 + mid + 1, s2 + r + 1, cmp2d);//对两个小区间分别排序
	int i, j = l;
	for (i = mid + 1; i <= r; ++i)
	{
		while (s2[i].b >= s2[j].b && j <= mid)//把小于i的j的数量加入树状数组
			tr.insert(s2[j].c, k, s2[j].cnt), ++j;
		s2[i].ans += tr.sum(s2[i].c);//求前缀和即为数量
	}
	for (int i = l; i < j; ++i)//清空树状数组
		tr.insert(s2[i].c, k, -s2[i].cnt);
}
int main()
{
	int a, b, c;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		s1[i] = node(a, b, c);
		//cout << s1[i].a << " " << s1[i].b << " " << s1[i].c << endl;
	}
	sort(s1 + 1, s1 + n + 1, cmp1d);//对第一维排序
	for (int i = 1; i <= n; ++i)//合并相同项
	{
		++top;
		if (cmp(s1[i], s1[i + 1]))
		{
			++m;
			s2[m] = node(s1[i].a, s1[i].b, s1[i].c);
			s2[m].cnt = top;
			top = 0;
		}
	}
	cdq(1, m);//分治
	for (int i = 1; i <= m; ++i)
		ans[s2[i].ans + s2[i].cnt - 1] += s2[i].cnt;//统计数量
	for (int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}