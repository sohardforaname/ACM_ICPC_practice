#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
bool vis[MAXN], vis2[MAXN];
vector<int>ans;
vector<int>t;
int main()
{
	int n, a;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		if (a > 0)//进入
		{
			if (vis[a] || vis2[a])
				return printf("-1\n"), 0;
			else
				vis[a] = 1, cnt += 1;
		}
		else if (a < 0)
		{
			a = -a;
			if (!vis[a] || vis2[a])
				return printf("-1\n"), 0;
			else
			{
				vis[a] = 0, cnt -= 1;
				vis2[a] = 1;
				t.push_back(a);
				if (cnt == 0)
				{
					ans.push_back(i);
					for (auto& i : t)
						vis2[i] = 0;
					t.clear();
				}
			}
		}
	}
	if (ans[ans.size() - 1] != n)
		return printf("-1\n"), 0;
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i == 0)
			printf("%d ", ans[i]);
		else
			printf("%d ", ans[i] - ans[i - 1]);
	}
	putchar('\n');
	return 0;
}