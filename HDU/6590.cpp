#include <bits/stdc++.h>
using namespace std;
const int tmax = 105;
struct Point
{
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
    Point operator+(Point p)
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(Point p)
    {
        return Point(x - p.x, y - p.y);
    }
    bool operator<(Point p)
    {
        return x != p.x ? x < p.x : y < p.y;
    }
};
long long dot(Point p1, Point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
long long cross(Point p1, Point p2)
{
    return p1.x * p2.y - p2.x * p1.y;
}
int convexHull(Point *P, int n, Point *aim)
{
    int i, m = 0;
    sort(P + 1, P + 1 + n);
    for (i = 1; i <= n; i++)
    {
        while (m >= 2 && cross(aim[m] - aim[m - 1], P[i] - aim[m - 1]) <= 0)
            m--;
        aim[++m] = P[i];
    }
    int k = m;
    for (i = n; i >= 1; i--)
    {
        while (m > k && cross(aim[m] - aim[m - 1], P[i] - aim[m - 1]) <= 0)
            m--;
        aim[++m] = P[i];
    }
    return m;
}
bool check(Point A, Point *p, int n)
{
    int l = 1, r = n - 2, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        double a1 = cross(p[mid] - p[0], A - p[0]);
        double a2 = cross(p[mid + 1] - p[0], A - p[0]);
        if (a1 >= 0 && a2 <= 0)
        {
            if (cross(p[mid + 1] - p[mid], A - p[mid]) >= 0)
                return true;
            return false;
        }
        else if (a1 < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{
    int T, i, n, kind, num0[2], num1[2];
    Point data[2][tmax], aim[2][tmax], tmp;
    scanf("%d", &T);
    while (T--)
    {
        num0[0] = num0[1] = num1[0] = num1[1] = 0;
        memset(data, 0, sizeof(data));
        memset(aim, 0, sizeof(aim));
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%lld%lld%d", &tmp.x, &tmp.y, &kind);
            if (kind == 1)
                data[1][++num1[0]] = tmp;
            else
                data[0][++num0[0]] = tmp;
        }
        num0[1] = convexHull(data[0], num0[0], aim[0]);
        num1[1] = convexHull(data[1], num1[0], aim[1]);
        bool ok = false;
        for (i = 1; i <= num0[1]; i++)
            ok |= check(aim[0][i], aim[1] + 1, num1[1]);
        for (i = 1; i <= num1[1]; i++)
            ok |= check(aim[1][i], aim[0] + 1, num0[1]);
        if (!ok)
            printf("Successful!\n");
        else
            printf("Infinite loop!\n");
    }
    return 0;
}
