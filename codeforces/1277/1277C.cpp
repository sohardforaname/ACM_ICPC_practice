#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5;
char s[N];
int pos[N];
int len;
vector<int>ans;
int check(int p)
{
	if (p + 4 <= len)
	{
		if (s[p] == 't' && s[p + 1] == 'w' && s[p + 2] == 'o' && s[p + 3] == 'n' && s[p + 4] == 'e')
			return 2;
	}
	if (p + 2 <= len)
	{
		if (s[p] == 't' && s[p + 1] == 'w' && s[p + 2] == 'o')
			return 1;
		else if (s[p] == 'o' && s[p + 1] == 'n' && s[p + 2] == 'e')
			return 1;
	}
	return 0;
}
int main()
{
	int ti;
	scanf("%d", &ti);
	while (ti--)
	{
		ans.clear();
		scanf("%s", s + 1);
		len = strlen(s + 1);
		for (int i = 1; i <= len;)
		{
			int tmp = check(i);
			if (tmp)
				ans.push_back(i + tmp), i += 3;
			else
				++i;
		}
		printf("%d\n", ans.size());
		for (auto i : ans)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}