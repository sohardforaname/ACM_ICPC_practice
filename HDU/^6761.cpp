#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char s[N];
typedef long long ll;
const ll mod = 1e9 + 7;
ll pos[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len;)
        {
            int j = i, k = i + 1;
            int l = 1;
            pos[i] = i;
            while (k <= N && s[j] <= s[k])
            {
                if (s[j] < s[k])
                    j = i, l = k - i + 1, pos[k] = i;
                else
                    pos[k] = pos[j] + l, ++j;
                ++k;
            }
            while (i <= j)
                i += k - j;
        }
        ll ans = 0, tmp = 1;
        for (int i = 1; i <= len; ++i)
            ans = (ans + pos[i] * tmp) % mod, tmp = tmp * 1112 % mod;
        printf("%lld\n", ans);
    }
    return 0;
}