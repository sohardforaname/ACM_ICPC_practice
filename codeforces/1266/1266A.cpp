#include <bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int even = 0, zero = 0;
		for (int i = 1; i <= len; ++i)
		{
			if ((s[i] - '0') % 2 == 0)
				++even;
			if (s[i] == '0')
				++zero;
		}
		if (even < 2 || zero == 0)
			printf("cyan\n");
		else
		{
			int sum = 0;
			for (int i = 1; i <= len; ++i)
				sum += s[i] - '0';
			if (sum % 3)
				printf("cyan\n");
			else
				printf("red\n");
		}
	}
	return 0;
}