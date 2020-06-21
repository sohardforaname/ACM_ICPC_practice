#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
const int N = 1e5 + 5;
int trie[N * 6][28];
int cnt;
vector<int> e[N * 6];
int n, m;
char hs(char ch)
{
	if (isalpha(ch))
		return ch;
	else if (ch == '*')
		return 'z' + 1;
	else
		return 'z' + 2;
}
void insert(char *str, int len, int id)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'a';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	e[root].push_back(id);
}
int a[N], top = 0;
void query(char *str, int mat, int len, int u, bool rt)
{
	if (mat == len && e[u].size())
		for (int i = 0; i < e[u].size(); ++i)
			a[++top] = e[u][i] - 1;
	if (!u && !rt)
		return;
	int cur = str[mat] - 'a';
	if (trie[u][cur]) //匹配到字母
		query(str, mat + 1, len, trie[u][cur], 0);
	if (trie[u][27]) //匹配到?
		query(str, mat + 1, len, trie[u][27], 0);
	if (trie[u][26]) //匹配到*
		for (int i = 0; mat + i <= len; ++i)
			query(str, mat + i, len, trie[u][26], 0);
}
char s[25];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", s);
		int len = strlen(s);
		for (int j = 0; j < len; ++j)
			s[j] = hs(s[j]);
		insert(s, len, i);
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", s);
		top = 0;
		query(s, 0, strlen(s), 0, 1);
		sort(a + 1, a + top + 1);
		top = unique(a + 1, a + top + 1) - (a + 1);
		if (top)
			for (int i = 1; i <= top; ++i)
				printf("%d%c", a[i], " \n"[i == top]);
		else
			printf("Not match\n");
	}
	return 0;
}