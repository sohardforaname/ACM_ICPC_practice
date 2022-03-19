#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
char s[10];
void solve()
{
    scanf("%s", s);
    int hh = s[0] * 10 + s[1];
    int mm = s[3] * 10 + s[4];
    int ss = s[6] * 10 + s[7];
    int tot = hh * 3600 + mm * 60 + ss;
    scanf("%s", s);
    hh = s[0] * 10 + s[1];
    mm = s[3] * 10 + s[4];
    ss = s[6] * 10 + s[7];
    tot = hh * 3600 + mm * 60 + ss - tot;
    printf("%d\n", abs(tot));
}
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}