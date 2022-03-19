#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e4 + 5;
int trie[N][26];
int cntword[N], cnt;
char str[1000][25];
void insert(char* str, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
		++cntword[root];
	}
}
int get(char* str, int len)
{
	int root = 0, maxn = -1;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		root = trie[root][nxt];
		if (cntword[root] == 1)
		{
			maxn = i;
			break;
		}
	}
	return maxn > -1 ? maxn : len - 1;
}
int main()
{
	int tot = 0;
	while (~scanf("%s", str[tot++]))
		insert(str[tot - 1], strlen(str[tot - 1]));
	for (int i = 0; i < tot; ++i)
	{
		printf("%s ", str[i]);
		int pos = get(str[i], strlen(str[i]));
		for (int j = 0; j <= pos; ++j)
			printf("%c", str[i][j]);
		printf("\n");
	}
	return 0;
}