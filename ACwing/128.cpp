#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
stack<int>s1, s2;
int sum[MAXN], f[MAXN];
void Ins(int x)
{
	s1.push(x);
	int sz = s1.size();
	sum[sz] = sum[sz - 1] + x;
	f[sz] = max(f[sz - 1], sum[sz]);
}
void Del()
{
	if (!s1.empty())
		s1.pop();
}
void Left()
{
	if (s1.size())
	{
		s2.push(s1.top());
		s1.pop();
	}
}
void Right()
{
	if (s2.size())
	{
		int tmp = s2.top();
		s1.push(tmp);
		s2.pop();
		int sz = s1.size();
		sum[sz] = sum[sz - 1] + tmp;
		f[sz] = max(f[sz - 1], sum[sz]);
	}
}
int main()
{
	for (int i = 0; i <= 1e6 + 5; ++i)
		f[i] = -0x3f3f3f3f;
	int Q;
	scanf("%d", &Q);
	char op[3];
	int n;
	while (Q--)
	{
		scanf("%s", op);
		if (op[0] == 'I')
			scanf("%d", &n), Ins(n);
		else if (op[0] == 'D')
			Del();
		else if (op[0] == 'L')
			Left();
		else if (op[0] == 'R')
			Right();
		else if (op[0] == 'Q')
			scanf("%d", &n), printf("%d\n", f[n]);
	}
	return 0;
}