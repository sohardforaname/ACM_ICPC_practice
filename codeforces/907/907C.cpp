#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N], ch[3];
int vis[30], buf[30];
int main()
{
    int n;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    bool f = 0;
    int cnts = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s%s", ch, s);
        int len = strlen(s);
        if (!f)
        {
            if (ch[0] == '.')
                for (int j = 0; j < len; ++j)
                    vis[s[j] - 'a'] = -1;
            else if (ch[0] == '!')
            {
                ++cnts;
                memset(buf, 0, sizeof(buf));
                for (int j = 0; j < len; ++j)
                    buf[s[j] - 'a'] = 1;
                for (int i = 0; i < 26; ++i)
                    if (buf[i])
                        ++vis[i];
            }
            else
                vis[s[0] - 'a'] = -1;
            int cnt = 0;
            for (int j = 0; j < 26; ++j)
                if (vis[j] == cnts)
                    ++cnt;
            if (cnt < 2)
                f = 1;
        }
        else if (i < n)
            if (ch[0] != '.')
                ++ans;
    }
    printf("%d\n", ans);
    return 0;
}