#include <bits/stdc++.h>
using namespace std;
int mat[505][505];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1)
		printf("0\n");
	else if (m > 1)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				mat[i][j] = j + 1;
		for (int j = 1; j <= m; ++j)
			for (int i = 2; i <= n; ++i)
				mat[i][j] *= (i + m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				printf("%d%c", mat[i][j], j == m ? '\n' : ' ');
	}
	else if (m == 1)
		for (int i = 1; i <= n; ++i)
			printf("%d\n", i + 1);
	return 0;
}