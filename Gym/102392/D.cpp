#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int cnt[26];
int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1), mxid;
    for (int i = 1; i <= len; ++i)
        ++cnt[s[i] - 'a'];
    int tot = 0, maxn = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i])
            ++tot;
        maxn = max(maxn, cnt[i]);
        if (cnt[i] == maxn)
            mxid = i;
    }
    if (maxn == len)
    {
        printf("NO\n");
        return 0;
    }
    if (maxn == len - 1 && len > 2)
    {
        printf("NO\n");
        return 0;
    }
    if (tot == 2 && maxn == len - 2 && len > 4)
    {
        printf("NO\n");
        return 0;
    }
    if (maxn == len - 1 && len <= 2)
    {
        printf("YES\n");
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                putchar(i + 'a');
        putchar('\n');
        return 0;
    }
    if (tot == 2 && maxn == len - 2 && len <= 4)
    {
        printf("YES\n");
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                putchar(i + 'a');
        putchar('\n');
        return 0;
    }
    else
    {
        printf("YES\n");
        if (maxn <= len / 2)
        {
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < cnt[i]; ++j)
                    putchar(i + 'a');
            putchar('\n');
        }
        else
        {
            for (int i = 1; i <= len / 2; i++)
                putchar('a' + mxid);
            cnt[mxid] -= len / 2;
            for (int i = 0; i < 26; i++)
                if (cnt[i] > 0 && mxid != i)
                {
                    putchar(i + 'a');
                    cnt[i]--;
                    break;
                }
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < cnt[i]; ++j)
                    putchar(i + 'a');
            putchar('\n');
        }
    }
    return 0;
}