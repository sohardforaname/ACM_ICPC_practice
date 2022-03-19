#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
const int N = 6e3 + 5;
const int M = 26;
int trie[N][M], fail[N];
int dp[N][N];
bool f[N];
int cnt;
void insert(char* s, int len)
{
	int root = 0;
	for (int i = 0; i < len; ++i)
	{
		int nxt = s[i] - 'A';
		if (!trie[root][nxt])
			trie[root][nxt] = ++cnt;
		root = trie[root][nxt];
	}
	f[root] = 1;
}
void get_fail()
{
	queue<int>q;
	for (int i = 0; i < M; ++i)
		if (trie[0][i])
			q.push(trie[0][i]);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < M; ++i)
		{
			if (trie[now][i])
			{
				fail[trie[now][i]] = trie[fail[now]][i];
				f[trie[now][i]] |= f[fail[trie[now][i]]];
				q.push(trie[now][i]);
			}
			else
				trie[now][i] = trie[fail[now]][i];
		}
	}
}
int pow(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
void solve(int n)
{
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= cnt; ++j)
			if (!f[j])
				for (int k = 0; k < M; ++k)
				{
					dp[i][trie[j][k]] += dp[i - 1][j];
					dp[i][trie[j][k]] %= mod;
				}
	int ans = 0;
	for (int i = 0; i <= cnt; ++i)
		if (!f[i])
			(ans += dp[n][i]) %= mod;
	printf("%d", (pow(26, n, mod) - ans % mod + mod) % mod);
}
char s[105];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", s);
		insert(s, strlen(s));
	}
	get_fail();
	solve(m);
	return 0;
}