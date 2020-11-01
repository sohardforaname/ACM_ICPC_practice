#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

char s[MAXN];
int n;

bool chk(int lim)
{
    int num = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            continue;
        if (s[i] == '2')
        {
            if (num == lim || cnt == 2 * lim)
                continue;
            num++;
            cnt++;
        }
        if (s[i] == '0')
        {
            if (num > 0)
                num--;
        }
        if (num == 0 && cnt == 2 * lim)
            return 1;
    }
    return 0;
}

void solve()
{
    scanf("%s", s + 1);
    int l = 0, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (chk(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d", &n) != EOF)
        solve();
    return 0;
}
