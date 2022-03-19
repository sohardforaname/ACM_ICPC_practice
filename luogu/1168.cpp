#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >sq;
priority_queue<int>bq;
int main()
{
	int n, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		if (bq.empty() || a <= bq.top())
			bq.push(a);
		else
			sq.push(a);
		if (i % 2)
		{
			while (sq.size() > i / 2)
				bq.push(sq.top()), sq.pop();
			while (bq.size() > i / 2 + 1)
				sq.push(bq.top()), bq.pop();
			printf("%d\n", bq.top());
		}
	}
	return 0;
}