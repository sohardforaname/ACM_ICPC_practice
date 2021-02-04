#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bool vis[N];
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int rev = n - (n / a) * a, cur = n - rev;
    vis[rev] = 1;
    while (1)
    {
        while (rev < a && b <= cur)
            rev += b, cur -= b;
        while (rev >= a)
            rev -= a, cur += a;
        if (vis[rev])
            break;
        vis[rev] = 1;
    }
    int minn = 0x3f3f3f3f;
    for (int i = 0; i <= 1e6; ++i)
        if (vis[i])
            minn = min(minn, i);
    printf("%d\n", n - minn);
    return 0;
}