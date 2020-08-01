#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 5;
char s[N][N];
int cnt[N][26];
char str[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", &s[i][1]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ++cnt[i][s[i][j] - 'a'];
    for (int i = 1; i <= n / 2; ++i)
    {
        int res = -1;
        for (int j = 0; j < 26; ++j)
        {
            if (cnt[i][j] > 0 && cnt[n - i + 1][j])
            {
                res = j;
                break;
            }
        }
        if (res == -1)
        {
            printf("-1\n");
            return;
        }
        str[i] = str[n - i + 1] = res + 'a';
    }
    if (n % 2)
    {
        int res = -1;
        for (int i = 0; i < 26; ++i)
            if (cnt[n / 2 + 1][i] > 0)
            {
                res = i;
                break;
            }
        if (res == -1)
        {
            printf("-1\n");
            return;
        }
        str[n / 2 + 1] = res + 'a';
    }
    printf("%s\n", str + 1);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}