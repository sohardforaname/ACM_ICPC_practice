#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int>G[N];
int fa[N], t[N];
char ch[N];
stack<int>s;
long long a[N];
void dfs(int u)
{
	int top = 0;
	if (ch[u] == '(')
		s.push(u);
	else if (!s.empty())
	{
		top = s.top();
		t[u] = t[fa[top]] + 1;
		s.pop();
	}
	a[u] = a[fa[u]] + t[u];//加上所有
	for (auto i : G[u])
		dfs(i);
	if (ch[u] == '(')
		s.pop();
	else if (top)
		s.push(top);
}
char str[N];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 1; i <= n; ++i)
		ch[i] = str[i - 1];
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &fa[i]);
		G[fa[i]].push_back(i);
	}
	dfs(1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans ^= i * a[i];
	printf("%lld\n", ans);
	return 0;
}