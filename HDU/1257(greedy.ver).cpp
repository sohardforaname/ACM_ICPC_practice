#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int G[N];
int main()
{
    int n, a;
    while (~scanf("%d", &n))
    {
        int sum = 0;
        while (n--)
        {
            scanf("%d", &a);
            int pos = 0;
            for (; pos <= sum; ++pos)
                if (a <= G[pos])
                {
                    G[pos] = a;
                    break;
                }
            if (pos > sum)
                G[++sum] = a;
            sort(G, G + sum);
        }
        printf("%d\n", sum);
    }
    return 0;
}