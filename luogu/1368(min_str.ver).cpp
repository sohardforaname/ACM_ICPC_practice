#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int s[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    int i = 0, j = 1, k = 0;
    while (k < n && i < n && j < n)
    {
        int t = s[(i + k) % n] - s[(j + k) % n];
        if (!t)
            ++k;
        else
        {
            if (t > 0)
                i += k + 1;
            else
                j += k + 1;
            k = 0;
            if (i == j)
                ++j;
        }
    }
    int ans = min(i, j);
    for (int i = 0; i < n; ++i)
        printf("%d%c", s[(ans + i) % n], " \n"[i == n - 1]);
    return 0;
}
