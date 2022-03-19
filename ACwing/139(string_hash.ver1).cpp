#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e6 + 5;
const int base = 13331;
ull prf[MAXN], suf[MAXN], p[MAXN];
char str[MAXN];
ull hash1(int l, int r, ull* arr)
{
	return arr[r] - arr[l - 1] * p[r - l + 1];
}
ull hash2(int l, int r, ull* arr)
{
	return arr[l] - arr[r + 1] * p[r - l + 1];
}
int main()
{
	int c = 0;
	p[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		p[i] = p[i - 1] * base;
	while (scanf("%s", str + 1) && str[1] != 'E')
	{
		int len = strlen(str + 1);
		prf[0] = suf[len + 1] = 0;
		for (int i = 1; i <= len; ++i)
			prf[i] = prf[i - 1] * base + str[i] - 'a';
		for (int i = len; i >= 1; --i)
			suf[i] = suf[i + 1] * base + str[i] - 'a';
		int ans = 0;
		for (int i = 1; i <= len; ++i)
		{
			int l = 0, r = min(i - 1, len - i);//奇数回文串
			while (l < r)
			{
				int m = (l + r + 1) >> 1;
				if (hash1(i - m, i - 1, prf) == hash2(i + 1, i + m, suf))
					l = m;
				else
					r = m - 1;
			}
			ans = max(ans, (l << 1) | 1);
		}
		for (int i = 1; i <= len; ++i)
		{
			int l = 0, r = min(i - 1, len - i + 1);//偶数回文串
			while (l < r)
			{
				int m = (l + r + 1) >> 1;
				if (hash1(i - m, i - 1, prf) == hash2(i, i + m - 1, suf))
					l = m;
				else
					r = m - 1;
			}
			ans = max(ans, l << 1);
		}
		printf("Case %d: %d\n", ++c, ans);
	}
	return 0;
}