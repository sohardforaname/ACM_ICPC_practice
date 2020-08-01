#include <bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5;
char s[N][N];
int main()
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%s", &s[i][j * 3]);
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    int px = x % 3, py = y % 3;
    int cnt = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (s[3 * px + i][3 * py + j] != '.')
                ++cnt;
    if (cnt == 9)
    {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (s[i][j] == '.')
                    s[i][j] = '!';
    }
    else
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (s[3 * px + i][3 * py + j] == '.')
                    s[3 * px + i][3 * py + j] = '!';
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            printf("%c", s[i][j]);
            if (j % 3 == 2)
                printf(" ");
        }
        if (i % 3 == 2)
            printf("\n");
        printf("\n");
    }
    return 0;
}