#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
set<int> s;
set<int> s1;
int a[N];
void solve()
{
    s.clear();
    s1.clear();
    int n;
    scanf("%d", &n);
    int cnt = n;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d", &k);
        bool f = 0;
        if (k)
            for (int j = 1; j <= k; ++j)
            {
                scanf("%d", &a[j]);
                if (!f && s.find(a[j]) != s.end())
                {
                    s.erase(a[j]);
                    --cnt;
                    f = 1;
                }
            }
        if (!f)
            s1.insert(i);
    }
    if (cnt && s.size() && s1.size())
    {
        int i = *s.begin(), j = *s1.begin();
        printf("IMPROVE\n%d %d\n", j, i);
    }
    else
        printf("OPTIMAL\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}