#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
ll s[MAXN];
struct node
{
	ll num;
	int id;
	bool operator<(const node& a)
	{
		return num < a.num;
	}
};
node t[MAXN];
vector<tuple<int, int, ll> >op;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		s[a] -= c, s[b] += c;
	}
	for (int i = 1; i <= n; ++i)
		t[i].num = s[i], t[i].id = i;
	sort(t + 1, t + n + 1);
	int p1, p2;
	for (p1 = 1; p1 <= n; ++p1)
		if (t[p1].num < 0)
			break;
	for (p2 = 1; p2 <= n; ++p2)
		if (t[p2].num > 0)
			break;
	while (p2 <= n && p1 <= n)
	{
		ll minn = min(abs(t[p1].num), abs(t[p2].num));
		op.push_back(make_tuple(t[p1].id, t[p2].id, minn));
		t[p1].num += minn;
		t[p2].num -= minn;
		while (p1 <= n && t[p1].num >= 0)
			++p1;
		while (p2 <= n && t[p2].num <= 0)
			++p2;
	}
	printf("%d\n", op.size());
	for (auto i : op)
		printf("%d %d %lld\n", get<0>(i), get<1>(i), get<2>(i));
	return 0;
}