#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;
int mat[MAXN][MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &mat[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mat[i][j] = mat[i][j] + mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k < i; ++k)
				for (int l = 0; l < j; ++l)
					ans = max(ans, mat[i][j] - mat[i][l] - mat[k][j] + mat[k][l]);
	printf("%d\n", ans);
	return 0;
}