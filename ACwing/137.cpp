#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
unordered_map<ll, int>mp;
struct node
{
	int a[10];
};
node a[MAXN];
int a1[10], a2[10];
bool check(int p1, int p2)
{
	memcpy(a1, a[p1].a, sizeof(a[p1].a));
	memcpy(a2, a[p2].a, sizeof(a[p2].a));
	bool f;
	for (int i = 0; i < 6; ++i)
	{
		f = 1;
		for (int j = 0; j < 6; ++j)
			if (a1[j] != a2[(j + i) % 6])
				f = 0;
		if (f == 1)
			return 1;
	}
	reverse(a1, a1 + 6);
	for (int i = 0; i < 6; ++i)
	{
		f = 1;
		for (int j = 0; j < 6; ++j)
			if (a1[j] != a2[(j + i) % 6])
				f = 0;
		if (f == 1)
			return 1;
	}
	return 0;
}
ll hs(int pos)
{
	ll ans = 0, ans1 = 1;
	for (int i = 0; i < 6; ++i)
		ans += a[pos].a[i];
	for (int i = 0; i < 6; ++i)
		ans1 *= a[pos].a[i];
	return ans + ans1;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 6; ++j)
			scanf("%d", &a[i].a[j]);
	bool f = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll tmp = hs(i);
		if (!mp.count(tmp))
			mp[tmp] = i;
		else
			if (check(i, mp[tmp]))
			{
				printf("Twin snowflakes found.\n");
				f = 1;
				break;
			}
	}
	if (!f)
		printf("No two snowflakes are alike.\n");
	return 0;
}