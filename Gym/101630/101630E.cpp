#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int buc[N];
vector<int> z;
int zcnt = 0;
int main()
{
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        if (a > 0)
            ++buc[a];
        else if (a == 0)
            ++zcnt;
        else if (a < 0)
        {
            if (buc[-a])
                --buc[-a];
            else if (zcnt)
                --zcnt, z.push_back(-a);
            else
            {
                printf("No\n");
                return 0;
            }
        }
    }
    while (zcnt--)
        z.push_back(1);
    printf("Yes\n");
    for (int i = 0; i < z.size(); ++i)
        printf("%d%c", z[i], " \n"[i == z.size() - 1]);
    return 0;
}