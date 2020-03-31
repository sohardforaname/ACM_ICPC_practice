#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int a[N];
int num[N];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int top = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != a[i - 1])
			num[++top] = 1;
		else
			++num[top];
	}
	int g = 0, s = 0, t = 0;
	for (int i = 1; i <= top; ++i)
	{
		if (!g)
			g = num[i];
		else if (s <= g)
			s += num[i];
		else if (g + s + t + num[i] <= n / 2)
			t += num[i];
		else
			break;
	}
	if (g >= s || g >= t || !(g && s && t))
		printf("0 0 0\n");
	else
		printf("%d %d %d\n", g, s, t);
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}