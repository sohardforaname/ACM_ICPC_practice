#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
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
	int x, y, u, d;
	que() {}
	que(int _x, int _y, int _u, int _d) :x(_x), y(_y), u(_u), d(_d) {}
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
bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
queue<que>q;
void bfs(int x, int y)
{
	int pos = ch[x][y] - 'A';
	int root = trie[0][pos];
	if (!root)
		return;
	int id = cntword[root];
	if(id&&!s[id].dir)
		s[id].x = x, s[id].y = y, s[id].dir = 'A';
	for (int i = 0; i < 8; ++i)
	{
		int dx = x + dir[i][0], dy = y + dir[i][1];
		if (check(dx, dy))
			q.push(que(dx, dy, trie[root][ch[dx][dy] - 'A'], i));
	}
	while (!q.empty())
	{
		que t = q.front();
		q.pop();
		if (!t.u)
			continue;
		id = cntword[t.u], x = t.x, y = t.y;
		if (id && !s[id].dir)
			s[id].x = x, s[id].y = y, s[id].dir = char((t.d + 4) % 8 + 'A');
		int dx = x + dir[t.d][0], dy = y + dir[t.d][1];
		if (check(dx, dy))
			q.push(que(dx, dy, trie[t.u][ch[dx][dy] - 'A'], t.d));
	}
}
char t[N];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", t);
		for (int j = 0; j < m; ++j)
			ch[i][j] = t[j];
	}
	for (int i = 1; i <= k; ++i)
	{
		scanf("%s", s[i].s);
		int len = strlen(s[i].s);
		reverse(s[i].s, s[i].s + len);
		insert(s[i].s, len, i);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			bfs(i, j);
	for (int i = 1; i <= k; ++i)
		printf("%d %d %c\n", s[i].x, s[i].y, s[i].dir);
	return 0;
}