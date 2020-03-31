#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
string str[105];
char ch[105][65];
int main()
{
#ifdef _Aya
	freopen("D:\\out.txt", "w", stdout);
#endif
	int n;
	while (~scanf("%d", &n))
	{
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", ch[i]);
			str[i] = ch[i];
			m = max(m, (int)str[i].size());
		}
		sort(str, str + n);
		for (int i = 0; i <= 60; ++i)
			printf("%c", i == 60 ? '\n' : '-');
		int C = (60 - m) / (m + 2) + 1, R = (n - 1) / C + 1;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (j * R + i < n)
					printf("%-*s", j == C - 1 ? m : (m + 2), str[j * R + i].c_str());
			}
			putchar('\n');
		}
	}
	return 0;
}
