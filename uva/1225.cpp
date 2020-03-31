#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int num[10005][10];
void init()
{
	for (int i = 0; i < 1e4 + 1; ++i)
	{
		int tmp = i;
		while (tmp)
			++num[i][tmp % 10], tmp /= 10;
		if (i > 1)
			for (int j = 0; j < 10; ++j)
				num[i][j] += num[i - 1][j];
	}
}
int main()
{
	init();
	int n, a;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &a);
		for (int i = 0; i < 10; ++i)
		{
			printf("%d", num[a][i]);
			if (i < 9)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}