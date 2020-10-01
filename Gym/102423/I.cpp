#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
char mp[N][N];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
int n, m;
bool vis[N][N];
bool check(int i, int j, int k)
{
    if (i > n || i < 1 || j > m || j < 1)
        return false;
    if (k < 4)
        return mp[i][j] == '.';
    else if (k == 4)
        return mp[i][j] == '.' && mp[i][j - 1] == '/' && mp[i + 1][j] == '/';
    else if (k == 5)
        return mp[i][j] == '.' && mp[i][j + 1] == '/' && mp[i - 1][j] == '/';
    else if (k == 6)
        return mp[i][j] == '.' && mp[i][j - 1] == '\\' && mp[i - 1][j] == '\\';
    else if (k == 7)
        return mp[i][j] == '.' && mp[i][j + 1] == '\\' && mp[i + 1][j] == '\\';
}
bool check2(int x, int y)
{
    return x <= n && x >= 1 && y <= m && y >= 1 && mp[x][y] == '.';
}
bool bfs(int x, int y)
{
    bool f = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (q.size())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (vis[cur.first][cur.second])
            continue;
        vis[cur.first][cur.second] = 1;
        for (int i = 0; i < 8; ++i)
        {
            if (check(cur.first + dir[i][0], cur.second + dir[i][1], i))
                q.push({cur.first + dir[i][0], cur.second + dir[i][1]});
            if (cur.first == 1 || cur.first == n || cur.second == 1 || cur.second == m)
                f = 0;
        }
    }
    return f;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &mp[i][1]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (mp[i][j] == '/' && mp[i + 1][j] == '\\' && mp[i][j + 1] == '\\' && mp[i + 1][j + 1] == '/')
                ++ans;
            else
                for (int k = 0; k < 2; ++k)
                    for (int l = 0; l < 2; ++l)
                        if (check2(i + k, j + l) && !vis[i + k][j + l])
                            ans += bfs(i + k, j + l);
        }
    printf("%d\n", ans);
    return 0;
}