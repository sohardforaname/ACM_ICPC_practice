#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int query(int l, int r)
{
    printf("? %d ", r - l + 1);
    for (int i = l; i <= r; ++i)
        printf("%d%c", i, " \n"[i == r]);
    fflush(stdout);
    int res = 0;
    scanf("%d", &res);
    return res;
}
int col[N], tmp[N];
void solve()
{
    int n, k, a, b;
    scanf("%d%d", &n, &k);
    memset(col, -1, sizeof(col[0]) * (n + 1));
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", &a);
        for (int j = 1; j <= a; ++j)
        {
            scanf("%d", &b);
            col[b] = i;
        }
    }
    int maxn = query(1, n);
    int l = 1, r = n;
    int maxpos = 0;
    while (1)
    {
        int mid = (l + r) >> 1;
        if (l == mid)
        {
            if (query(l, mid) == maxn)
                maxpos = l;
            else
                maxpos = r;
            break;
        }
        if (query(l, mid) == maxn)
            r = mid;
        else
            l = mid + 1;
    }
    if (col[maxpos] == -1)
    {
        printf("! ");
        for (int i = 1; i <= k; ++i)
            printf("%d%c", maxn, " \n"[i == k]);
        fflush(stdout);
        char s[20];
        scanf("%s", s);
        return;
    }
    int top = 0;
    for (int i = 1; i <= n; ++i)
        if (col[i] != col[maxpos])
            tmp[++top] = i;
    printf("? %d ", top);
    for (int i = 1; i <= top; ++i)
        printf("%d%c", tmp[i], " \n"[i == top]);
    fflush(stdout);
    int res = 0;
    scanf("%d", &res);
    printf("! ");
    for (int i = 1; i < col[maxpos]; ++i)
        printf("%d ", maxn);
    printf("%d ", res);
    for (int i = col[maxpos] + 1; i <= k; ++i)
        printf("%d%c", maxn, " \n"[i == k]);
    fflush(stdout);
    char s[20];
    scanf("%s", s);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}