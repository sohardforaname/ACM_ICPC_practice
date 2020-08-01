#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v1, v2, v3, vm;
    scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
    if (v2 <= vm || v3 * 2 < vm || vm * 2 < v3)
        printf("-1\n");
    else
        printf("%d %d %d\n", v1 * 2, v2 * 2, max(v3, vm));
    return 0;
}