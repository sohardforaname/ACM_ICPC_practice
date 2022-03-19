#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
const int M = 26;
vector<int> G[N];
int sz[N];
ll ans = 0;
struct SAM
{
	int maxlen[N], link[N], size, last;
	int nxt[N][M];
	SAM() : size(1), last(1) {}
	void extend(int ch)
	{
		ch -= 'a';
		int cur = (++size), p;
		sz[size] = 1;
		maxlen[cur] = maxlen[last] + 1;
		for (p = last; p && !nxt[p][ch]; p = link[p])
			nxt[p][ch] = cur;
		if (!p)
			link[cur] = 1;
		else
		{
			int q = nxt[p][ch];
			if (maxlen[q] == maxlen[p] + 1)
				link[cur] = q;
			else
			{
				int tmp = ++size;
				maxlen[tmp] = maxlen[p] + 1;
				for (int i = 0; i < M; ++i)
					nxt[tmp][i] = nxt[q][i];
				link[tmp] = link[q];
				for (; p && nxt[p][ch] == q; p = link[p])
					nxt[p][ch] = tmp;
				link[cur] = link[q] = tmp;
			}
		}
		last = cur;
	}
};
SAM sam;
void dfs(int u)
{
	for (auto i : G[u])
	{
		dfs(i);
		sz[u] += sz[i];
	}
	if (sz[u] != 1 && u > 1)
		ans = max(ans, 1ll * sz[u] * sam.maxlen[u]);
}
char s[N];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; ++i)
		sam.extend(s[i]);
	for (int i = 2; i <= sam.size; ++i)
		G[sam.link[i]].push_back(i);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}