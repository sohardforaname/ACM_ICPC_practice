#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e3 + 5;
int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
char ch[N][N];
int trie[N * N][26];
int cntword[N * N], cnt, n, m, k;
struct str
{
	int x, y;
	char dir;
	char s[N];
};
struct que
{
	int a, b, c;
	que() {}
	que(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {}
};
str s[N];
void insert(char* str, int len, int id)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = str[i] - 'A';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	cntword[root] = id;
}
void dfs(int u, int px, int py, int x, int y, int d)
{
	if (!u || x < 0 || x >= n || y < 0 || y >= m)
		return;
	int pos = cntword[u];
	if (pos && !s[pos].dir)
	{
		s[pos].x = px;
		s[pos].y = py;
		s[pos].dir = d + 'A';
	}
	pos = ch[x + dir[d][0]][y + dir[d][1]] - 'A';
	dfs(trie[u][pos], px, py, x + dir[d][0], y + dir[d][1], d);
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s", ch[i]);
	for (int i = 1; i <= k; ++i)
	{
		scanf("%s", s[i].s);
		int len = strlen(s[i].s);
		insert(s[i].s, len, i);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 8; ++k)
				dfs(trie[0][ch[i][j] - 'A'], i, j, i, j, k);
	for (int i = 1; i <= k; ++i)
		printf("%d %d %c\n", s[i].x, s[i].y, s[i].dir);
	return 0;
}