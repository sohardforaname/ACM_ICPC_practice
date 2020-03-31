#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 2e6 + 5;
const int MAXL = 26;
struct AC
{
	int nxt[MAXN][MAXL], fail[MAXN], cntword[MAXN];
	int in[MAXN], ans[MAXN], hs[MAXN], vis[MAXN];
	int cnt = 0;
	void insert(char* str, int len, int id)
	{
		int root = 0;
		for (int i = 0; i < len; ++i)
		{
			int nxtch = str[i] - 'a';
			if (!nxt[root][nxtch])
				nxt[root][nxtch] = ++cnt;
			root = nxt[root][nxtch];
		}
		if (!cntword[root])
			cntword[root] = id;
		hs[id] = cntword[root];
	}
	void getfail()
	{
		queue<int>que;
		int now = 0;
		for (int i = 0; i < MAXL; ++i)
			if (nxt[now][i])
			{
				que.push(nxt[now][i]);
				fail[nxt[now][i]] = 0;
				++in[0];
			}
		while (!que.empty())
		{
			now = que.front();
			que.pop();
			for (int i = 0; i < MAXL; ++i)
			{
				if (nxt[now][i])
				{
					fail[nxt[now][i]] = nxt[fail[now]][i];
					++in[fail[nxt[now][i]]];
					que.push(nxt[now][i]);
				}
				else
					nxt[now][i] = nxt[fail[now]][i];
			}
		}
	}
	void toposort()
	{
		queue<int>que;
		for (int i = 0; i <= cnt; ++i)
			if (!in[i])
				que.push(i);
		while (!que.empty())
		{
			int u = que.front();
			que.pop();
			vis[cntword[u]] = ans[u];
			int v = fail[u];
			ans[v] += ans[u], --in[v];
			if (!in[v])
				que.push(v);
		}
	}
	void query(char* str, int len)
	{
		int now = 0;
		for (int i = 0; i < len; ++i)
			now = nxt[now][str[i] - 'a'], ++ans[now];
	}
};
AC ac;
char str[MAXM];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", str), ac.insert(str, strlen(str), i);
	ac.getfail();
	scanf("%s", str);
	ac.query(str, strlen(str));
	ac.toposort();
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ac.vis[ac.hs[i]]);
	return 0;
}