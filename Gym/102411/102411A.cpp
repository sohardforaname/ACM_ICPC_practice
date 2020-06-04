#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, n, tmp = 0;
    scanf("%d%d%d", &a, &b, &n);
    printf("%d\n", (n - a - 1) / (b - a) * 2 + 1);
    return 0;
}