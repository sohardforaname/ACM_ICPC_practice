#include "../base.h"

const int N = 5e5 + 5;
bool multi = 0;

char s[N];
int nxt[N], b[N], dp[N];
void getnext(char *s, int len)
{
    int j = 0;
    for (int k = 2; k <= len; ++k)
    {
        while (j && s[j + 1] != s[k])
            j = nxt[j];
        if (s[j + 1] == s[k])
            ++j;
        nxt[k] = j;
    }
}
void solve()
{
    io(s + 1);
    int len = strlen(s + 1);
    getnext(s, len);
    for (int i = 1; i <= len; ++i)
    {
        dp[i] = i;
        if (b[dp[nxt[i]]] >= i - nxt[i])
            dp[i] = dp[nxt[i]];
        b[dp[i]] = i;
    }
    io(dp[len], '\n');
}

MAIN_FUNC