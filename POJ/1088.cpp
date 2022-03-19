#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e2 + 5;
int mat[N][N], n, m;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dp[N][N];
bool check(int i, int j)
{
    return i && i <= n && j && j <= m;
}

int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    for (int i = 0; i < 4; ++i)
        if (check(x + dir[i][0], y + dir[i][1]) && mat[x][y] > mat[x + dir[i][0]][y + dir[i][1]])
            dp[x][y] = max(dp[x][y], dfs(x + dir[i][0], y + dir[i][1]) + 1);
    return dp[x][y];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &mat[i][j]);
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            maxn = max(maxn, dfs(i, j));
    printf("%d\n", maxn + 1);
    return 0;
}