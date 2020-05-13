#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;
char s[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        int k = 0, i = 0, j = 1;
        while (k < n && i < n && j < n)
        {
            if (s[(i + k) % n] == s[(j + k) % n])
                ++k;
            else
            {
                if (s[(i + k) % n] > s[(j + k) % n])
                    i += k + 1;
                else
                    j += k + 1;
                k = 0;
                if (i == j)
                    ++j;
            }
        }
        printf("%d\n", min(i, j) + 1);
    }
    return 0;
}