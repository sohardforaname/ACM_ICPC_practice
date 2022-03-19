#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
bool mat[N][N][N];
char str[N];
bool zst[N][N], cst[N][N];
struct node
{
    int x, y, z;
    bool operator<(const node &a) const
    {
        return x == a.x ? (y == a.y ? z < a.z : y < a.y) : x < a.x;
    }
};
vector<node> v;
vector<int> v1, v2;
int main()
{
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; ++j)
            zst[i][j] = str[j] - '0';
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= h; ++j)
            cst[i][j] = str[j] - '0';
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (zst[i][j])
                for (int k = 1; k <= h; ++k)
                    mat[i][j][k] = 1;
    bool f = 1;
    for (int i = 1; i <= n && f; ++i)
        for (int k = 1; k <= h && f; ++k)
        {
            if (!cst[i][k])
                for (int j = 1; j <= m; ++j)
                    mat[i][j][k] = 0;
            else if (cst[i][k])
            {
                int tmp = 0;
                for (int j = 1; j <= m; ++j)
                    if (mat[i][j][k])
                        ++tmp;
                if (!tmp)
                    f = 0;
            }
        }
    for (int i = 1; i <= n && f; ++i)
        for (int j = 1; j <= m && f; ++j)
        {
            int tmp = 0;
            for (int k = 1; k <= h; ++k)
                if (mat[i][j][k])
                    ++tmp;
            if (zst[i][j] && !tmp)
                f = 0;
        }
    if (!f)
    {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n && f; ++i)
        for (int j = 1; j <= m && f; ++j)
            for (int k = 1; k <= h; ++k)
                if (mat[i][j][k])
                {
                    ++cnt;
                    v.push_back({i, j, k});
                }
    printf("%d\n", cnt);
    for (auto &i : v)
        printf("%d %d %d\n", i.x - 1, i.y - 1, i.z - 1);
    v.clear();
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        v1.clear(), v2.clear();
        for (int j = 1; j <= m; ++j)
            if (zst[i][j])
                v1.push_back(j);
        for (int j = 1; j <= h; ++j)
            if (cst[i][j])
                v2.push_back(j);
        cnt += max(v1.size(), v2.size());
        int diff = abs((int)v1.size() - (int)v2.size());
        if (v1.size() < v2.size())
        {
            for (int j = 0; j < diff; ++j)
                v.push_back({i, v1[0], v2[j]});
            for (int j = diff; j < v2.size(); ++j)
                v.push_back({i, v1[j - diff], v2[j]});
        }
        else
        {
            for (int j = 0; j < diff; ++j)
                v.push_back({i, v1[j], v2[0]});
            for (int j = diff; j < v1.size(); ++j)
                v.push_back({i, v1[j], v2[j - diff]});
        }
    }
    printf("%d\n", cnt);
    for (auto &i : v)
        printf("%d %d %d\n", i.x - 1, i.y - 1, i.z - 1);
    return 0;
}