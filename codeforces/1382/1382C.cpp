#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s1[N], s2[N];
vector<int> ans1, ans2;
void solve()
{
    int n;
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);
    s1[n + 1] = '0';
    s2[n + 1] = '0';
    ans1.clear();
    ans2.clear();
    for (int i = 1; i <= n; ++i)
        if (s1[i] != s1[i + 1])
            ans1.push_back(i);
    for (int i = 1; i <= n; ++i)
        if (s2[i] != s2[i + 1])
            ans2.push_back(i);
    reverse(ans2.begin(), ans2.end());
    printf("%d", ans1.size() + ans2.size());
    for (auto i : ans1)
        printf(" %d", i);
    for (auto i : ans2)
        printf(" %d", i);
    printf("\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}