#include "../base.h"

bool multi = 1;
const int N = 1e3 + 5;

char mp[N][N];
void solve()
{
    int n, m;
    io(n, m);
    for (int i = 1; i <= n; ++i)
        io(&mp[i][1]);
    int u = 0, v = 0;
    if (m % 2) {
        io("YES", '\n');
        for (int i = 1; i <= (m + 1) / 2; ++i)
            io(1, ' '), io(2, ' ');
        putchar('\n');
        return;
    }
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (mp[i][j] == mp[j][i]) {
                u = i, v = j;
                break;
            }
    if (u && v) {
        io("YES", '\n');
        for (int i = 1; i <= (m + 1) / 2; ++i)
            io(u, ' '), io(v, ' ');
        if (m % 2 == 0)
            io(u, '\n');
        else
            putchar('\n');
        return;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                if (i == j || j == k || i == k)
                    continue;
                if (mp[i][j] == mp[j][k]) {
                    bool f = 0;
                    io("YES", '\n');
                    if (m % 4 == 0)
                        f = 1;
                    if (f)
                        io(j, ' '), m -= 2;
                    for (int x = 1; x <= m / 2; ++x) {
                        if (x % 2 == 0)
                            io(j, ' ');
                        else
                            io(i, ' ');
                    }
                    io(j, ' ');
                    for (int x = 1; x <= m / 2; ++x) {
                        if (x % 2 == 0)
                            io(j, ' ');
                        else
                            io(k, ' ');
                    }
                    if (f)
                        io(j, ' ');
                    putchar('\n');
                    return;
                }
            }
    io("NO", '\n');
}

MAIN_FUNC