#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MAXN = 2e5 + 5;
struct mv
{
	int b, c, index;
};
mv t[MAXN];
unordered_map<int, int>mp;
int top = 0, n, m;
bool cmp(mv& aa, mv& bb)
{
	if (aa.b == bb.b)
		return aa.c > bb.c;
	return aa.b > bb.b;
}
int main()
{
	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a), ++mp[a];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &a), t[i].b = mp[a];
		t[i].index = i + 1;
	}
	for (int i = 0; i < m; ++i)
		scanf("%d", &a), t[i].c = mp[a];
	sort(t, t + m, cmp);
	printf("%d\n", t[0].index);
	return 0;
}
