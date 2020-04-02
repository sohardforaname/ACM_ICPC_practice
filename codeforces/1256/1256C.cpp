#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int len[MAXN], tag[MAXN];
int main()
{
	int n, m, d, sum = 0;
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &len[i]), sum += len[i];
	if (sum + (m + 1) * (d - 1) < n)
		return printf("NO\n"), 0;
	int cnt = m;
	for (int i = n; cnt; --cnt)
		for (int j = len[cnt]; j; --j)
			tag[i--] = cnt;
	int pos = 0, p = n - sum + 1;
	cnt = 1;
	while (pos < n)
	{
		pos += d;//跳
		if (pos >= n || tag[pos])
			break;
		for (int i = 0; i < len[cnt]; ++i)
			swap(tag[pos + i], tag[p++]);
		pos += len[cnt] - 1;
		++cnt;
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d%c", tag[i], i == n ? '\n' : ' ');
	return 0;
}