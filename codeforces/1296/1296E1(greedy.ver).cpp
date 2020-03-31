#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
char s[N];
bool c[N];
vector<char>v;
int main()
{
	int n;
	scanf("%d%s", &n, s + 1);
	for (int i = 2, j = 1; i <= n; ++i)
	{
		if (s[i] >= s[j])
			j = i;
		else
			v.push_back(s[i]), c[i] = 1;
	}
	for (int i = 1; i < v.size(); ++i)
		if (v[i] < v[i - 1])
			return printf("NO\n"), 0;
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d", c[i]);
	printf("\n");
	return 0;
}