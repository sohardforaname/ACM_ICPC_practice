#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int main()
{
	int n;
	unsigned long long k;
	scanf("%d%llu", &n, &k);
	for (int i = 1; i <= n; ++i)
		s.push(k % 2), k >>= 1;
	bool tag = 0;
	while (!s.empty())
	{
		putchar(s.top() ^ tag + '0');
		if (s.top())
			tag = 1;
		else
			tag = 0;
		s.pop();
	}
	return 0;
}
