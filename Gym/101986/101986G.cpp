#include <bits/stdc++.h>
using namespace std;
const double sqr3 = sqrt(3);
const double sqr32 = sqr3 / 2;
const double pi = acos(-1);
char s[5];
int solve()
{
    int d, l;
    scanf("%s%d%d", s, &d, &l);
    double angle = pi * d / 180;
    if (s[0] == 'D')
        angle = 2 * pi - angle;
    else if (s[0] == 'B')
        angle = 5 * pi / 3 - angle;
    else
        angle = 4 * pi / 3 - angle;
    double x = cos(angle) * l;
    double y = sin(angle) * l;
    while (y < 0)
    {
        y += sqr3;
        x += 1;
    }
    y = y * 2 / sqr3;
    x = x - y * 0.5;
    while (x < 0)
        x += 2;
    while (x > 2)
        x -= 2;
    if (x < 1 && y < 1)
        return x + y < 1 ? 2 : 1;
    if (1 < x && x < 2 && y < 1)
        return x - 1 + y < 1 ? 3 : 4;
    if (x < 1 && 1 < y && y < 2)
        return x + y - 1 < 1 ? 4 : 3;
    if (1 < x && 1 < y && y < 2)
        return x - 1 + y - 1 < 1 ? 1 : 2;
    return -1;
}
int main()
{
    printf("%s", solve() == solve() ? "YES\n" : "NO\n");
    return 0;
}
