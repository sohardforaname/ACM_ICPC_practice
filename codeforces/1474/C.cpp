#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

bool multi = 1;
int a[N << 1];
multiset<int> s;
vector<pair<int, int>> v;

void solve()
{
    s.clear();
    int n;
    scanf("%d", &n);
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), s.insert(a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i)
    {
        v.clear();
        multiset<int> s1 = s;
        auto it = s1.find(a[i]);
        int t1;
        if (it != s1.end())
        {
            t1 = *it;
            s1.erase(it);
        }
        it = --s1.end();
        int cur = *it;
        v.push_back({t1, cur});
        s1.erase(it);
        while (s1.size())
        {
            int tmp = cur - *(--s1.end());
            cur = *(--s1.end());
            s1.erase(--s1.end());
            it = s1.find(tmp);
            if (it != s1.end())
            {
                t1 = *it;
                s1.erase(it);
                v.push_back({t1, cur});
            }
            else
                break;
        }
        if (s1.size() == 0)
        {
            printf("YES\n");
            printf("%d\n", v[0].first + v[0].second);
            for (auto &i : v)
                printf("%d %d\n", i.first, i.second);
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    int t;
    if (multi)
        scanf("%d", &t);
    else
        t = 1;
    while (t--)
        solve();
    return 0;
}