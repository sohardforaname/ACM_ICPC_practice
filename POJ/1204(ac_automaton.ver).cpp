#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e3 + 5;
char ch[N][N];
int trie[N * N][26];
int cntword[N * N], fail[N * N], cnt;
int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
struct str
{
	int x, y;
	char dir;
	char s[N];
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
void getfail()
{
	int now = 0;
	queue<int>q;
	for (int i = 0; i < 26; ++i)
		if (trie[now][i])
			q.push(trie[now][i]);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i)
		{
			if (trie[now][i])
			{
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push(trie[now][i]);
			}
			else
				trie[now][i] = trie[fail[now]][i];
		}
	}
}
int n, m, k;
bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
void query(int x, int y, int d)
{
	int root = 0;
	while (check(x, y))
	{
		int pos = ch[x][y] - 'A'; 
		root = trie[root][pos];
		int now = root;
		while (now)
		{
			int id = cntword[now];
			if (id && !s[id].dir)
			{
				s[id].x = x;
				s[id].y = y;
				s[id].dir = char((d + 4) % 8 + 'A');
			}
			now = fail[now];
		}
		x += dir[d][0];
		y += dir[d][1];
	}
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
		reverse(s[i].s, s[i].s + len);
		insert(s[i].s, len, i);
	}
	getfail();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < 8; ++j)
			query(0, i, j), query(n - 1, i, j);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 8; ++j)
			query(i, 0, j), query(i, m - 1, j);
	for (int i = 1; i <= k; ++i)
		printf("%d %d %c\n", s[i].x, s[i].y, s[i].dir);
	return 0;
}