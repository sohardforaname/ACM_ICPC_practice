#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
bool ispri[N];
int pri[N], cnt;
void getpri(int n)
{
	fill(ispri, ispri + n, 1);
	for (int i = 2; i < n; ++i)
	{
		if (ispri[i])
			pri[++cnt] = i;
		for (int j = 1; j <= cnt && i * pri[j] < n; ++j)
		{
			ispri[i * pri[j]] = 0;
			if (i % pri[j] == 0)
				break;
		}
	}
}
int main()
{
	getpri(N);
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; ++c)
	{
		bool f = 0;
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)
			swap(a, b);
		if ((a > 2 && (b - a) % 2) || b == a)
		{
			printf("Case %d: %d\n", c, -1);
			continue;
		}
		for (int i = 2; i <= cnt; ++i)
			if (pri[i - 1] >= a && pri[i] - pri[i - 1] == b - a)
			{
				printf("Case %d: %d\n", c, pri[i] - b), f = 1;
				break;
			}
		if (!f)
			printf("Case %d: %d\n", c, -1);
	}
	return 0;
}
