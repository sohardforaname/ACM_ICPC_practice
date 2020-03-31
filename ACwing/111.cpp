#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 5e4 + 5;
struct cow
{
	long long beg, end, index;
	bool operator<(const cow& a)const
	{
		return beg == a.beg ? end < a.end : beg < a.beg;
	}
};
struct node
{
	long long t, index;
	bool operator<(const node& a)const
	{
		return t == a.t ? index > a.index : t > a.t;
	}
	node(long long _t, long long _index)
	{
		t = _t, index = _index;
	}
};
priority_queue<node>que;
cow c[MAXN];
int ans[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &c[i].beg, &c[i].end), c[i].index = i;
	sort(c, c + n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (que.empty()|| que.top().t >= c[i].beg)
		{
			++cnt;
			ans[c[i].index] = cnt;
			que.push(node(c[i].end, cnt));
		}
		else
		{
			node tmp = que.top();
			que.pop();
			ans[c[i].index] = tmp.index;
			tmp.t = c[i].end;
			que.push(tmp);
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
