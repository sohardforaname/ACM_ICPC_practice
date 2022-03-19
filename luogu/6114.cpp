#include "../base.h"

const int N = 5e6 + 5;
bool multi = 0;

char s[N];
int pos[N], top;

void lyndon(char *x, int n)
{
    int i = 0;
    while (i < n)
    {
        int j = i, k = i + 1;
        while (k < n && x[j] <= x[k])
        {
            if (x[j] == x[k])
                j++;
            else
                j = i;
            k++;
        }
        while (i <= j)
        {
            i += k - j;
            pos[++top] = i;
        }
    }
}

void solve()
{
    io(s);
    lyndon(s, strlen(s));
    int ans = 0;
    for (int i = 1; i <= top; ++i)
        ans ^= pos[i];
    io(ans, '\n');
}

MAIN_FUNC