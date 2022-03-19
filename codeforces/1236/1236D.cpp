#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
vector<int> G1[N];
vector<int> G2[N];
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G1[a].push_back(b);
        G2[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        sort(G1[i].begin(), G1[i].end());
    for (int i = 1; i <= m; ++i)
        sort(G2[i].begin(), G2[i].end());
    bool f = 0;
    ll ans = 1;
    int x = 1, y = 1;
    int up = 1, down = n, left = 1, right = m;
    int dir = 0;
    while (1)
    {
        int ny, nx;
        if (dir == 0) //右方向
        {
            int pos = lower_bound(G1[x].begin(), G1[x].end(), y) - G1[x].begin();
            nx = x;
            if (pos == G1[x].size())
                ny = right;
            else
                ny = min(right, G1[x][pos] - 1);
            up = x + 1;
        }
        else if (dir == 1) //下方向
        {
            int pos = lower_bound(G2[y].begin(), G2[y].end(), x) - G2[y].begin();
            ny = y;
            if (pos == G2[y].size())
                nx = down;
            else
                nx = min(down, G2[y][pos] - 1);
            right = y - 1;
        }
        else if (dir == 2)
        {
            int pos = lower_bound(G1[x].begin(), G1[x].end(), y) - G1[x].begin() - 1;
            nx = x;
            if (pos < 0)
                ny = left;
            else
                ny = max(left, G1[x][pos] + 1);
            down = x - 1;
        }
        else if (dir == 3)
        {
            int pos = lower_bound(G2[y].begin(), G2[y].end(), x) - G2[y].begin() - 1;
            ny = y;
            if (pos < 0)
                nx = up;
            else
                nx = max(up, G2[y][pos] + 1);
            left = y + 1;
        }
        if (nx == x && ny == y && f)
            break;
        dir = (dir + 1) % 4;
        ans += abs(nx - x) + abs(ny - y);
        x = nx;
        y = ny;
        f = 1;
    }
    if (ans == (ll)n * m - k)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}