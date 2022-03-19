#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 2e1 + 6;
char str[MAXN];
struct Trie
{
	int tr[MAXN][MAXM];
	int cntword[MAXN];
	int cnt = 0;
	void insert(char* s, int len)
	{
		int root = 0;
		for (int i = 1; i <= len; ++i)
		{
			int nxt = s[i] - 'a';
			if (!tr[root][nxt])
				tr[root][nxt] = ++cnt;
			root = tr[root][nxt];
		}
		++cntword[root];
	}
	int query(char* s, int len)
	{
		int now = 0, ans = 0;
		for (int i = 1; i <= len; ++i)
		{
			int nxt = s[i] - 'a';
			now = tr[now][nxt];
			if (!now)
				break;
			ans += cntword[now];
		}
		return ans;
	}
};
Trie tr;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", str + 1);
		tr.insert(str, strlen(str + 1));
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", str + 1);
		printf("%d\n", tr.query(str, strlen(str + 1)));
	}
	return 0;
}