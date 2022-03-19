#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
typedef long long ll;
int nxt[N];
char s[N];
void get_next(char *s, int len)
{
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
            nxt[++i] = ++j;
        else
            j = nxt[j];
    }
}
int main()
{
    ll a, b;
    while (~scanf("%lld%lld", &a, &b))
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int pos = 1;
        for (; s[pos] != '.'; ++pos)
            ;
        char *beg = s + pos + 1, *end = s + 1 + len;
        reverse(beg, end);
        len = end - beg;
        get_next(beg, len);
        ll maxn = -1e18;
        for (int i = 0; i < len; ++i)
            maxn = max(maxn, a * (1ll * len - i) - b * (1ll * len - i - nxt[len - i]));
        printf("%lld\n", maxn);
    }
    return 0;
}