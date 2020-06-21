#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 5;
typedef long long ll;
typedef pair<int, int> pii;
char s[N];
void solve()
{
    scanf("%s", s);
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
        {
            bool f = 0;
            for (int k = i; k <= j; ++k)
                if (s[k] != s[j - k + i])
                {
                    f = 1;
                    break;
                }
            if (f)
                ans = max(ans, j - i + 1);
        }
    printf("%d\n", ans);
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}