#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int x[N], y[N];
int n, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int calc(int qx, int qy)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += abs(qx - x[i]);
    for (int i = 1; i <= n; ++i)
        sum += abs(qy - y[i]);
    return sum;
}
pair<int, int> p[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i), p[i] = make_pair(x[i], y[i]);
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    int ql, qr, qu, qd;
    if (n % 2)
        ql = qr = x[n / 2 + 1], qu = qd = y[n / 2 + 1];
    else
        ql = x[n / 2], qr = x[n / 2 + 1], qu = y[n / 2], qd = y[n / 2 + 1];
    int sum = (qr - ql + 1) * (qd - qu + 1);
    for (int i = 1; i <= n; ++i)
        if (p[i].first <= qr && p[i].first >= ql && p[i].second <= qd && p[i].second >= qu)
            --sum;
    if (!sum)
    {
        int cnt = 1, minn = 0x3f3f3f3f;
        assert(ql == qr && qu == qd);
        for (int i = 0; i < 4; ++i)
        {
            int tmp = calc(ql + dir[i][0], qu + dir[i][1]);
            if (tmp == minn)
                ++cnt;
            else if (tmp < minn)
                minn = tmp, cnt = 1;
        }
        printf("%d %d\n", minn, cnt);
        return 0;
    }
    printf("%d %d", calc(ql, qu), sum);
    return 0;
}
