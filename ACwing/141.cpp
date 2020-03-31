#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int nxt[MAXN];
char s[MAXN];
void getnext(char* s, int len)
{
	nxt[0] = -1;
	int k = 0, j = -1;
	while (k < len)
	{
		if (j == -1 || s[j] == s[k])
			nxt[++k] = ++j;
		else
			j = nxt[j];
	}
}
int main()
{
	int n, c = 0;
	while (scanf("%d", &n) && n)
	{
		scanf("%s", s);
		int len = strlen(s);
		getnext(s, len);
		printf("Test case %d\n", ++c);
		for (int i = 2; i <= len; ++i)
			if (i % (i - nxt[i]) == 0 && i / (i - nxt[i]) > 1)
				printf("%d %d\n", i, i / (i - nxt[i]));
		printf("\n");
	}
	return 0;
}