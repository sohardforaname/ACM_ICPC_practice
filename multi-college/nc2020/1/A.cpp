#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int suf[N][2];
char s[N];
struct Ans
{
    int fi, se;
    int id;
    bool operator<(const Ans &a) const
    {
        if (fi == a.fi)
            return se == a.se ? id > a.id : se < a.se;
        return fi < a.fi;
    }
};
Ans ans[N];
int main()
{
    int n;
    while (~scanf("%d%s", &n, s + 1))
    {
        suf[n][0] = suf[n][1] = n + 1;
        suf[n + 1][0] = suf[n + 1][1] = n + 1;
        for (int i = n - 1; i; --i)
        {
            suf[i][0] = suf[i + 1][0];
            suf[i][1] = suf[i + 1][1];
            suf[i][s[i + 1] - 'a'] = i + 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            ans[i].id = i;
            ans[i].fi = suf[i][(s[i] - 'a') ^ 1] - i;
            int tmp = suf[i][(s[i] - 'a') ^ 1];
            ans[i].se = suf[tmp][(s[i] - 'a') ^ 1] - tmp;
        }
        sort(ans + 1, ans + n + 1);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans[i].id, " \n"[i == n]);
    }
    return 0;
}