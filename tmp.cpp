#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
    int seed = time(0);
    if (argc > 1)
        seed = atoi(argv[1]);
    srand(seed);
    int n = rand() % 5 + 1, m = rand() % 20 + 1;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", rand() % 20 + m + 1);
    return 0;
}