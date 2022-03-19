#pragma GCC optimize(2)
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
using namespace std;
const int N = 2e5 + 5;

int s[N << 1], sa[N], rnk[N], height[N];
int c[N], p[N], tmp[N];
bool t[N << 1];

int fn(int a)
{
    return ++a;
}

#define Ar(x, a) sa[p[s[x]] a] = x
#define IS(s1)                                             \
    memset(sa + 1, 0, n << 2);                             \
    memset(c + 1, 0, m << 2);                              \
    for (int i = 1; i <= n; ++i)                           \
        ++c[s[i]];                                         \
    partial_sum(c + 1, c + m + 1, c + 1);                  \
    memcpy(p + 1, c + 1, m << 2);                          \
    for (int i = n1; i; --i)                               \
        Ar(s1[i], --);                                     \
    transform(c, c + m, p + 1, fn);                        \
    for (int i = 1; i <= n; ++i)                           \
        sa[i] > 1 && t[sa[i] - 1] ? Ar(sa[i] - 1, ++) : 0; \
    memcpy(p + 1, c + 1, m << 2);                          \
    for (int i = n; i; --i)                                \
        sa[i] > 1 && !t[sa[i] - 1] ? Ar(sa[i] - 1, --) : 0;

void SAIS(int s[], bool t[], int tmp[], int n, int m)
{
    int n1 = 0, m1 = rnk[1] = 0, *s1 = s + n;
    t[n] = 0;
    for (int i = n - 1; i; --i)
        t[i] = s[i] ^ s[i + 1] ? s[i] > s[i + 1] : t[i + 1];
    for (int i = 2; i <= n; ++i)
        rnk[i] = t[i - 1] && !t[i] ? tmp[++n1] = i, n1 : 0;
    IS(tmp);
    for (int i = 1, x, y = 0; i <= n; ++i)
        if (x = rnk[sa[i]])
        {
            if (m1 <= 1 || tmp[x + 1] - tmp[x] != tmp[y + 1] - tmp[y])
                ++m1;
            else
                for (int a = tmp[x], b = tmp[y]; a <= tmp[x + 1]; ++a, ++b)
                    if ((s[a] << 1 | t[a]) ^ (s[b] << 1 | t[b]))
                    {
                        ++m1;
                        break;
                    }
            s1[y = x] = m1;
        }
    if (m1 < n1)
        SAIS(s1, t + n, tmp + n1, n1, m1);
    else
        for (int i = 1; i <= n1; ++i)
            sa[s1[i]] = i;
    for (int i = 1; i <= n1; ++i)
        s1[i] = tmp[sa[i]];
    IS(s1);
}
void get_sa(char *str, int n)
{
    for (int i = 1; i <= n; ++i)
        s[i] = str[i] - '0' + 2;
    s[++n] = 1;
    SAIS(s, t, tmp, n, 300);
    --n;
    for (int i = 1; i <= n; ++i)
        rnk[sa[i] = sa[i + 1]] = i;
    for (int i = 1, L = 0, j; i <= n; height[rnk[i++]] = L)
        for (j = sa[~(-rnk[i])], L -= L > 0; i + L <= n && j + L <= n && s[i + L] == s[j + L]; ++L)
            ;
}
void init(int n)
{
    memset(rnk, 0, sizeof(rnk[0]) * n);
    memset(height, 0, sizeof(height[0]) * n);
}
typedef long long ll;
ll sta[N][2];
ll ans, cnt, len;
int la, top;
int n, k;
void solve()
{
    top = 0;
    ans = cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (height[i] < k)
            top = cnt = 0;
        else
        {
            len = 0;
            if (sa[i - 1] <= la)
                ++len, cnt += height[i] - k + 1;
            while (top && sta[top - 1][0] >= height[i])
            {
                --top;
                cnt -= sta[top][1] * (sta[top][0] - height[i]);
                len += sta[top][1];
            }
            sta[top][0] = height[i], sta[top++][1] = len;
            if (sa[i] > la)
                ans += cnt;
        }
    }
    cnt = 0;
    top = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (height[i] < k)
            top = cnt = 0;
        else
        {
            len = 0;
            if (sa[i - 1] > la)
                ++len, cnt += height[i] - k + 1;
            while (top && sta[top - 1][0] >= height[i])
            {
                --top;
                cnt -= sta[top][1] * (sta[top][0] - height[i]);
                len += sta[top][1];
            }
            sta[top][0] = height[i], sta[top++][1] = len;
            if (sa[i] <= la)
                ans += cnt;
        }
    }
    printf("%lld\n", ans);
}
char str[N];
int main()
{
    while (scanf("%d", &k) && k)
    {
        scanf("%s", str + 1);
        la = strlen(str + 1);
        str[la + 1] = '0';
        scanf("%s", str + la + 2);
        n = strlen(str + 1);
        str[n + 1] = 0;
        init(n);
        get_sa(str, n);
        solve();
    }
    return 0;
}