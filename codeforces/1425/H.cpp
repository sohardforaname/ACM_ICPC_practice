#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int sgn = (a + b) % 2;
        printf("%s ", (sgn && a + d > 0) ? "Ya" : "Tidak");
        printf("%s ", (sgn && b + c > 0) ? "Ya" : "Tidak");
        printf("%s ", (!sgn && b + c > 0) ? "Ya" : "Tidak");
        printf("%s\n", (!sgn && a + d > 0) ? "Ya" : "Tidak");
    }
    return 0;
}