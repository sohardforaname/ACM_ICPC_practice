#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct seg
{
	int l, r;
	seg() {}
	seg(int _l, int _r) :l(_l), r(_r) {}
	bool operator<(const seg& a)const
	{
		return l == a.l ? r < a.r : l < a.l;
	}
};
seg s[N];
int d[N << 2], b[N << 1], d_[N << 2];
int top;
void solve()
{
	top = 0;
	int n, ans0 = 0, ans1 = INT_MIN;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &s[i].l, &s[i].r);
		b[++top] = s[i].l, b[++top] = s[i].r;
	}
	sort(b + 1, b + top + 1);
	top = unique(b + 1, b + top + 1) - b - 1;//离散化特别注意
	for (int i = 1; i <= n; ++i)
	{
		s[i].l = lower_bound(b + 1, b + top + 1, s[i].l) - b;
		s[i].r = lower_bound(b + 1, b + top + 1, s[i].r) - b;
		s[i].l <<= 1, s[i].r <<= 1;
		++d[s[i].l], --d[s[i].r + 1];//计算差分
	}
	(top <<= 1) += 5;
	for (int i = 1; i <= top; ++i)
		d[i] += d[i - 1];
	for (int i = 0; i <= top; ++i)
		ans0 += (d[i] && !d[i + 1]);//计算一开始有多少个union
	for (int i = 0; i <= top; ++i)
		if (d[i] == 1 && d[i + 1] != 1)
			++d_[i];
	for (int i = 1; i <= top; ++i)
		if (d[i] == 1 && d[i - 1] != 1)
			++d_[i];//计算新增段
	for (int i = 1; i <= top; ++i)
		d_[i] += d_[i - 1];
	for (int i = 1; i <= n; ++i)
	{
		int t = (d_[s[i].r] - d_[s[i].l - 1]) / 2;
		t -= (d[s[i].l] == 1) + (d[s[i].r] == 1);
		ans1 = max(ans1, t);
	}
	printf("%d\n", ans0 + ans1);
	for (int i = 0; i <= top; ++i)
		d[i] = d_[i] = 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}