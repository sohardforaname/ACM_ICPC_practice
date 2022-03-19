#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1200, M = 1500, L = 10;
const ll mod = 1e9 + 7;
int trie[M][L], fail[M], cnt;
int dp[N][M][2];
bool f[M];
void insert(char* s, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = s[i] - '0';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	f[root] = 1;
}
void get_fail()
{
	queue<int>q;
	for (int i = 0; i < L; ++i)
		if (trie[0][i])
			q.push(trie[0][i]);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < L; ++i)
		{
			const int nxt = trie[now][i];
			if (nxt)
			{
				fail[nxt] = trie[fail[now]][i];
				q.push(nxt);
				f[nxt] |= f[fail[nxt]];
			}
			else
				trie[now][i] = trie[fail[now]][i];
		}
	}
}
void solve(char* s, int len)
{
	dp[0][0][0] = 1;
	for (int i = 1; i <= len; ++i)
		for (int j = 0; j <= cnt; ++j);
			/*if (!f[j])
			{
				for (int k = 0; k < L; ++k)
					(dp[i][trie[j][k]][0] += dp[i - 1][j][0]) %= mod;
				for (int k = 0; k < s[i] - '0'; ++k)
					(dp[i][trie[j][k]][0] += dp[i - 1][j][1]) %= mod;
				(dp[i][trie[j][s[i] - '0']][1] += dp[i - 1][j][1]) %= mod;
			}*/
	ll ans = 0;
	for (int i = 0; i <= cnt; ++i)
		if (!f[i])
		{
			(ans += dp[len][i][0]) %= mod;
			(ans += dp[len][i][1]) %= mod;
		}
	printf("%lld\n", ans);
}
char s[M], s1[5];
int main()
{
	int m;
	scanf("%s%d", s1 + 1, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", s);
		insert(s, strlen(s));
	}
	get_fail();
	solve(s1, strlen(s1 + 1));
	return 0;
}