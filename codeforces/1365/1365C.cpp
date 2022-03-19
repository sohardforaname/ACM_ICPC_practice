#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e5 + 1;
int buc[N << 4];
int a[N], b[N], g1[N], g2[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ++buc[a[i]];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= a[n]; ++i)
    {
        if (buc[i])
            g1[++cnt1] = i;
        else
            g2[++cnt2] = i;
    }
    int pos1 = 1, pos2 = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (pos1 <= cnt1 && a[i] > g1[pos1])
            b[i] = g1[pos1++];
        else if (pos2 <= cnt2)
            b[i] = g2[pos2++];
        else
            b[i] = INF;
    }
    memset(buc, 0, sizeof(buc));
    int tmp = -1;
    for (int i = 1; i <= n; ++i)
    {
        buc[b[i]] = 1;
        while (buc[tmp + 1])
            ++tmp;
        if (a[i] != tmp + 1)
            return printf("-1\n"), 0;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}