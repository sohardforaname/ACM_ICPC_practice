#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
    int seed = time(0);
    if (argc > 1)
        seed = atoi(argv[1]);
    srand(seed);
    int n = 1;
    while (n--)
    {
        int len = rand() % 20 + 1;
        printf("%d\n", len);
        for (int i = 1; i <= len; ++i)
            putchar(char(rand() % 3 + '0'));
        putchar('\n');
    }
    return 0;
}