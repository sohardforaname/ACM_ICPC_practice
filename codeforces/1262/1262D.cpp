#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
const int MAXN = 2e5 + 5;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
struct node
{
	int num, pos;
	bool operator<(const node& a)const
	{
		return num == a.num ? pos<a.pos : num>a.num;
	}
};
node a[MAXN], b[MAXN];
struct query
{
	int id, k, pos;
	bool operator<(const query& a)
	{
		return k < a.k;
	}
};
query q[MAXN];
int ans[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].num);
		a[i].pos = i;
		b[i] = a[i];
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d", &q[i].k, &q[i].pos);
		q[i].id = i;
	}
	sort(a + 1, a + n + 1);
	sort(q + 1, q + m + 1);
	int pos = 1;
	for (int i = 1; i <= m; ++i)
	{
		while (tr.size() < q[i].k)
			tr.insert(a[pos++].pos);
		ans[q[i].id] = b[*tr.find_by_order(q[i].pos - 1)].num;
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}