#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char str[N][15];
int trie[N][10];
int cntword[N];
int cnt;
bool check;
void insert(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - '0';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	++cntword[root];
}
bool find(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		int nxt = str[i] - '0';
		root = trie[root][nxt];
		if (cntword[root])
			return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i <= cnt; ++i)
		{
			for (int j = 0; j < 10; ++j)
				trie[i][j] = 0;
			cntword[i] = 0;
		}
		cnt = 0;
		check = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", str[i]);
			insert(str[i], strlen(str[i]));
		}
		for (int i = 1; i <= n; ++i)
			if (find(str[i], strlen(str[i])))
			{
				check = 1;
				break;
			}
		if (check)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}