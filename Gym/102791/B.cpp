#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
char s[N];
int main()
{
    int n;
    scanf("%d%s", &n, s + 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j < i; ++j)
            if (s[j] == 'L')
                ++cnt;
        for (int j = i + 1; j <= n; ++j)
            if (s[j] == 'R')
                ++cnt;
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}