#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 5, Inf = INT_MAX;
int n, f[4];
char s[N];
int main(int argc, char** argv)
{
    freopen((string("D:/4.3-data/A/") + to_string(stoi(argv[1]) + 1) + ".out").c_str(), "w", stdout);
    freopen((string("D:/4.3-data/A/") + to_string(stoi(argv[1]) + 1) + ".in").c_str(), "r", stdin);
    scanf("%s", s);
    n = strlen(s);
    fill(f, f + 4, -Inf);
    for (int i = 0; i < n; ++i)
        switch (s[i]) {
        case '1':
            f[0] < 0 ? f[0] = 1 : ++f[0];
            break;
        case '8':
            f[1] = max(f[0], f[1]) + 1;
            break;
        case '0':
            f[2] = max(f[1], f[2]) + 1;
            break;
        case '7':
            f[3] = max(f[2], f[3]) + 1;
            break;
        }
    printf("%d\n", f[3] > 0 ? f[3] : -1);
    return 0;
}