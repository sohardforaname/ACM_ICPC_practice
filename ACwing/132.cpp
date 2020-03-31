#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
unordered_multimap<int, int>mp;
queue<int>q[MAXN];
void enqueue(int x)
{
	auto g = *mp.find(x);
	int tmp = g.second;
	if (q[tmp].empty())
		q[0].push(tmp);
	q[tmp].push(x);
}
int dequeue()
{
	int tmp = q[0].front();
	int m = q[tmp].front();
	if (q[tmp].size() == 1)
		q[0].pop();
	q[tmp].pop();
	return m;
}
char op[10];
int main()
{
	int T, c = 1;
	while (scanf("%d", &T) && T)
	{
		for (int i = 0; i <= 1000; ++i)
			while (q[i].size())
				q[i].pop();
		int n, tmp;
		for (int i = 1; i <= T; ++i)
		{
			scanf("%d", &n);
			for (int j = 1; j <= n; ++j)
			{
				scanf("%d", &tmp);
				mp.insert(make_pair(tmp, i));
			}
		}
		printf("Scenario #%d\n", c++);
		while (scanf("%s", op) && op[0] != 'S')
		{
			if (op[0] == 'E')
				scanf("%d", &tmp), enqueue(tmp);
			else if (op[0] == 'D')
				printf("%d\n", dequeue());
		}
		printf("\n");
	}
	return 0;
}