#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
map<string, int>mp;
bool g[N];
char get_rev(char s)
{
	if (s == '0')
		return '1';
	else if (s == '1')
		return '0';
	assert(0);
}
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	srand(0);
	string s(n, 0);
	while(1)
	{
		s = string(n, 0);
		for (int j = 0; j < n; ++j)
			s[j] = rand() % 2 + '0';
		if (!mp[s])
		{
			mp[s] = 1;
			printf("%s\n", s.c_str());
			fflush(stdout);
			fflush(stdin);
			scanf("%d", &ans);
			if (ans == n)
				return 0;
			else if (ans == n / 2)
				break;
		}
	}
	memset(g, 0, sizeof(g));
	for (int i = 1; i < n; ++i)
	{
		s[0] = get_rev(s[0]);
		s[i] = get_rev(s[i]);
		printf("%s\n", s.c_str());
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &ans);
		if (ans == n / 2)
			g[i] = g[0] ^ 1;
		else if (ans == 0)
			g[i] = g[0];
		else if (ans == n)
			return 0;
		s[0] = get_rev(s[0]);
		s[i] = get_rev(s[i]);
	}
	for (int i = 0; i < n; ++i)
		if (g[i])
			s[i] = get_rev(s[i]);
	printf("%s\n", s.c_str());
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &ans);
	if (ans == n)
		return 0;
	else
	{
		for (int i = 0; i < n; ++i)
			s[i] = get_rev(s[i]);
		printf("%s\n", s.c_str());
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &ans);
	}
	return 0;
}