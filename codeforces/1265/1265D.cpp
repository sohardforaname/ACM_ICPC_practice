#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int num[4], q[4];
vector<int>ans;
void solve()
{
	for (int i = 0; i < 4; ++i)
		scanf("%d", &num[i]);
	for (int i = 0; i < 4; ++i)
	{
		ans.clear();
		memcpy(q, num, sizeof(num));
		int x = i;
		ans.push_back(x);
		--q[x];
		while (1)
		{
			if (x && q[x - 1])
				--x, --q[x], ans.push_back(x);
			else if (x != 3 && q[x + 1])
				++x, --q[x], ans.push_back(x);
			else
				break;
		}
		if (!(q[0] || q[1] || q[2] || q[3]))
		{
			printf("YES\n");
			for (auto i : ans)
				printf("%d ", i);
			printf("\n");
			return;
		}
	}
	printf("NO\n");
	return;
}
int main()
{
	int t = 1;
	//scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}