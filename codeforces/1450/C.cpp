#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
char mp[N][N];

vector<pair<int, int>> v[2][3];

void solve()
{
    int n;
    scanf("%d", &n);
    int cc1 = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            v[i][j].clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", &mp[i][1]);
        for (int j = 1; j <= n; ++j)
            if (mp[i][j] != '.')
                v[mp[i][j] == 'X'][(i + j) % 3].push_back({i, j}), ++cc1; // 0 == 'O', 1 == 'X'
    }
    int p1 = -1, p2 = -1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (i != j && v[0][i].size() + v[1][j].size() <= cc1 / 3)
                p1 = i, p2 = j;
    for (auto &p : v[0][p1])
        mp[p.first][p.second] = 'X';
    for (auto &p : v[1][p2])
        mp[p.first][p.second] = 'O';
    for (int i = 1; i <= n; ++i)
        puts(&mp[i][1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
