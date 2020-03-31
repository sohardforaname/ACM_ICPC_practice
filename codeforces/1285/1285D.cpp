#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>v;
int dfs(vector<int>& c, int bit)
{
	if (c.empty() || bit < 0)
		return 0;
	vector<int>l, r;
	for (auto i : c)
	{
		if ((i >> bit) & 1)
			l.push_back(i);
		else
			r.push_back(i);
	}
	if (l.empty())
		return dfs(r, bit - 1);
	else if (r.empty())
		return dfs(l, bit - 1);
	return min(dfs(l, bit - 1), dfs(r, bit - 1)) + (1 << bit);
}
int main()
{
	int n;
	scanf("%d", &n);
	v.resize(n);
	for (auto& i : v)
		scanf("%d", &i);
	printf("%d\n", dfs(v, 30));
	return 0;
}