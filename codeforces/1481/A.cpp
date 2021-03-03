#include "../base.h"

bool multi = 1;
const int N = 1e5 + 5;

char s[N];

void solve()
{
    int x, y;
    io(x, y);
    io(s + 1);
    int u = 0, d = 0, l = 0, r = 0;
    for (int i = 1; s[i]; ++i) {
        if (s[i] == 'U')
            ++u;
        else if (s[i] == 'D')
            ++d;
        else if (s[i] == 'L')
            ++l;
        else if (s[i] == 'R')
            ++r;
    }
    if (x < 0 && l < abs(x))
        return void(io("NO", '\n'));
    else if (x > 0 && r < x)
        return void(io("NO", '\n'));
    if (y < 0 && d < abs(y))
        return void(io("NO", '\n'));
    else if (y > 0 && u < y)
        return void(io("NO", '\n'));
    io("YES", '\n');
}

MAIN_FUNC