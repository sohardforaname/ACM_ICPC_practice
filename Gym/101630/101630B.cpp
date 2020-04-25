#include <bits/stdc++.h>
using namespace std;
int check(int a, int b, int c, int w, int h)
{
    if (2 * a + 2 * c <= w && 2 * a + b <= h || 2 * a + 2 * c <= h && 2 * a + b <= w)
        return 1;
    else if (a + b + c <= w && 2 * a + b + c <= h || a + b + c <= h && 2 * a + b + c <= w)
        return 1;
    else if (a + b <= w && a + b + 3 * c <= h || a + b <= h && a + b + 3 * c <= w)
        return 1;
    return 0;
}
int main()
{
    int a, b, c, w, h;
    cin >> a >> b >> c >> w >> h;
    if (check(a, b, c, w, h) || check(a, c, b, w, h) || check(b, a, c, w, h) || check(b, c, a, w, h) || check(c, a, b, w, h) || check(c, b, a, w, h))
        cout << "Yes" << endl; //调换a,b,c后的六种情况
    else
        cout << "No" << endl;
    return 0;
}