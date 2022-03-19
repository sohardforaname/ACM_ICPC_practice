#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	char s[205], tmp[105];
	char ans[105];
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		int len = strlen(s);
		memcpy(ans, s, len + 1);
		for (int i = 0; i <= len; ++i)
			s[i + len] = s[i];
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
				tmp[j] = s[i + j];
			tmp[len] = '\0';
			if (strcmp(tmp, ans) < 0)
				memcpy(ans, tmp, len + 1);
		}
		printf("%s\n", ans);
	}
	return 0;
}