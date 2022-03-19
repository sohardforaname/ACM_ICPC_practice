#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
char str1[MAXN], str2[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s%s", str1 + 1, str2 + 1);
		int d1 = 0, d2 = 0, cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (str1[i] != str2[i])
			{
				++cnt;
				if (!d1)
					d1 = i;
				else
					d2 = i;
			}
		}
		if (cnt != 2 && cnt != 0)
			printf("NO\n");
		else if (str1[d1] != str1[d2] || str2[d1] != str2[d2])
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}