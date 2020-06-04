#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    if (n * 2 > s)
        return printf("NO\n"), 0;
    printf("YES\n");
    for (int i = 1; i < n; ++i)
        printf("2 ");
    printf("%d\n1\n", s - (n - 1) * 2);
    return 0;
}