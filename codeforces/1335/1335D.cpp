#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
int a[N][N];
char s[N];
pair<int, int> dx[9] = {{1, 1}, {2, 4}, {3, 7}, {4, 2}, {5, 5}, {6, 8}, {7, 3}, {8, 6}, {9, 9}};
void chg(int x, int y)
{
    if (a[x][y] != 1)
        --a[x][y];
    else if (a[x][y] != 9)
        ++a[x][y];
}
void solve()
{
    for (int i = 1; i <= 9; ++i)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= 9; ++j)
            a[i][j] = s[j] - '0';
    }
    for (int i = 0; i < 9; ++i)
        chg(dx[i].first, dx[i].second);
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
            printf("%d", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}