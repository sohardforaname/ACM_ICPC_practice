#include <cstring>
#include <cstdio>
int main()
{
	char s[85];
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		int ans = 0, k = 0, len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == 'O')
				++k, ans += k;
			else if (s[i] == 'X')
				k = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}