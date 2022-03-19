#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n < m)
            swap(n, m);
        ans.clear();
        while (n % m)
        {
            for (int j = 1; j <= n / m; ++j)
                for (int i = 1; i <= m; ++i)
                    ans.push_back(m);
            n %= m;
            swap(n, m);
        }
        for (int i = 1; i <= n; ++i)
            ans.push_back(m);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}