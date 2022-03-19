#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n, m;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool check(int x, int y)
{
    for (int i = 0; i < 4; ++i)
        if (x / m + dx[i] == y / m && x % m + dy[i] == y % m)
            return 0;
    return 1;
}
bool dfs(int pos)
{
    if (pos == n * m)
        return 1;
    int x = pos / m, y = pos % m;
    for (int i = pos; i < n * m; ++i)
    {
        swap(a[pos], a[i]);
        if ((x && !check(a[pos], a[(x - 1) * m + y])) || (y && !check(a[pos], a[x * m + y - 1])))
            continue;
        if (dfs(pos + 1))
            return 1;
        swap(a[pos], a[i]);
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i * m + j] = i * m + j;
    if (!dfs(0))
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                printf("%d%c", a[i * m + j] + 1, " \n"[j == m - 1]);
    }
    return 0;
}