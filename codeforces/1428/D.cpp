#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
deque<int> G[N], v1, v2;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
            G[i].push_back(i);
        if (a[i] == 1)
            v1.push_back(i);
        else if (a[i] >= 2)
            v2.push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (G[i].size())
        {
            if (a[i] == 2)
            {
                int tmp;
                auto pos = lower_bound(v1.begin(), v1.end(), i);
                if (pos == v1.end())
                    return printf("-1\n"), 0;
                tmp = *pos;
                v1.erase(pos);
                G[tmp].pop_back();
                G[tmp].push_back(i);
            }
            else if (a[i] == 3)
            {
                int tmp;
                auto pos1 = lower_bound(v2.begin(), v2.end(), i + 1);
                auto pos2 = lower_bound(v1.begin(), v1.end(), i);
                if (pos1 == v2.end() && pos2 == v1.end())
                    return printf("-1\n"), 0;
                else if (pos1 != v2.end())
                    tmp = *pos1, v2.erase(pos1);
                else
                    tmp = *pos2, v1.erase(pos2);
                G[tmp].push_front(i);
            }
        }
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (G[i].size() > 2)
            return printf("-1\n"), 0;
        else
            tot += G[i].size();
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i)
        for (auto j : G[i])
            printf("%d %d\n", j, i);
    return 0;
}