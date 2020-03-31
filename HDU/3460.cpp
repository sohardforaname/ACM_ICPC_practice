#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int trie[N][26];
int cnt;
void insert(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
}
char str[55];
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int maxn = 0;
		for (int i = 0; i <= cnt; ++i)
			for (int j = 0; j < 26; ++j)
				trie[i][j] = 0;
		cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", str);
			int len = strlen(str);
			insert(str, len);
			maxn = max(maxn, len);
		}
		printf("%d\n", (cnt << 1) - maxn + n);
	}
	return 0;
}
