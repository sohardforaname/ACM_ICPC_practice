#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char str[MAXN];
int zero[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		long long k;
		scanf("%d%lld", &n, &k);
		scanf("%s", str + 1);
		int top = 0;
		for (int i = 1; i <= n; ++i)
			if (str[i] == '0')
				zero[++top] = i;
		for (int i = 1; i <= top; ++i)
		{
			if (k <= 0)
				break;
			if (zero[i] == i)
				continue;
			if (k >= zero[i] - i)
				k -= zero[i] - i, zero[i] = i;
			else
				zero[i] -= k, k = 0;
		}
		zero[top + 1] = n + 1;
		int pos = 1, cnt = 1;
		while (pos <= n)
		{
			while (pos <= n && pos < zero[cnt])
				printf("1"), ++pos;
			if (pos <= n)
				printf("0"), ++pos;
			++cnt;
		}
		printf("\n");
	}
	return 0;
}