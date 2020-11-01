#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
int h[N];
char s[N];
int main()
{
    int n;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i)
        s[i] -= '0';
    ll tot = 0, cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!s[i])
            tot += cur;
        else
        {
            int l = i, r = i;
            while (r + 1 <= n && s[r + 1])
                ++r;
            for (int j = 1; j <= r - l + 1; ++j)
            {
                cur += l + j - 1 - h[j];
                tot += cur;
                h[j] = r - j + 1;
            }
            i = r;
        }
    }
    printf("%lld\n", tot);
    return 0;
}