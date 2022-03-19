#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e2 + 5;
char str[MAXN], tmp[MAXN];
int n;
vector<int>op;
void solve(char c)
{
	op.clear();
	strcpy(str, tmp);
	for (int i = 0; i < n - 1; ++i)
		if (str[i] != c)
		{
			str[i] = c;
			if (str[i + 1] == 'B')
				str[i + 1] = 'W';
			else
				str[i + 1] = 'B';
			op.push_back(i);
		}
	if (str[n - 1] != c)
		return;
	printf("%d\n", op.size());
	for (auto i : op)
		printf("%d ", i + 1);
	printf("\n");
	exit(0);
}
int main()
{
	scanf("%d", &n);
	scanf("%s", tmp);
	solve('B');
	solve('W');
	printf("-1\n");
	return 0;
}