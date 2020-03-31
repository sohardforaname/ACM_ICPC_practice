#include <iostream>
#include <queue>
using namespace std;
bool vis[1005];
int mem[105];
int main()
{
	queue<int>que;
	int n, m, s = 0, t = 0, voc, i;
	cin >> m >> n;
	for (i = 0; i < n && que.size() < m; ++i)
	{
		cin >> voc;
		if (!vis[voc])
		{
			que.push(voc);
			vis[voc] = 1;
			++t;
		}
	}
	if (i == n)
		cout << t << endl;
	else
	{
		for (i; i < n; ++i)
		{
			cin >> voc;
			if (!vis[voc])
			{
				vis[que.front()] = 0;
				que.pop();
				que.push(voc);
				vis[voc] = 1;
				++t;
			}
		}
		cout << t << endl;
	}
	return 0;
}