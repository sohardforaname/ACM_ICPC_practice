#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t[205];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(t, 0, sizeof(t));
        int m, aa, bb;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> aa >> bb;
            int a = min(aa, bb), b = max(aa, bb);
            for (int j = (a - 1) / 2; j <= (b - 1) / 2; ++j)
                ++t[j];
        }
        int maxn = 0;
        for (int i = 0; i < 200; ++i)
            maxn = max(t[i], maxn);
        cout << maxn * 10 << endl;
    }
    return 0;
}
