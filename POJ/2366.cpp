#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
const int N = 5e4 + 5;
int a[N];
map<int, int> mp;
int main()
{
    int n, m, b;
tag:
    while (~scanf("%d", &n))
    {
        mp.clear();
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", &b);
            ++mp[b];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            if (mp.find(1e4 - a[i]) != mp.end())
            {
                puts("YES");
                goto tag;
            }
        puts("NO");
    }
    return 0;
}