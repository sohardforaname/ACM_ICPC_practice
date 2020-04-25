#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;
struct stru
{
    int x, id;
};
stru a[3];
bool cmp(stru &a, stru &b)
{
    return a.x > b.x;
}
bool vis[N][N];
int main()
{
    scanf("%d%d%d", &a[0].x, &a[1].x, &a[2].x);
    for (int i = 0; i < 3; ++i)
        a[i].id = i;
    sort(a, a + 3, cmp);
    int k;
    if (a[0].id == 0)
    {
        if (a[1].id == 1) //a>b>c
            k = 1;
        else if (a[1].id == 2) //a>c>b
            k = 2;
    }
    if (a[0].id == 1)
    {
        if (a[1].id == 0) //b>a>c
            k = 3;
        else if (a[1].id == 2) //b>c>a
            k = 4;
    }
    if (a[0].id == 2)
    {
        if (a[1].id == 0) //c>a>b
            k = 5;
        else if (a[1].id == 1) //c>b>a
            k = 6;
    }
    if (a[2].x * a[1].x < a[0].x)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", a[0].x);
    for (int i = 1; i <= a[2].x; ++i)
    {
        if (k == 1 || k == 2)
            printf("%d %d 1\n", i, i);
        else if (k == 3 || k == 4)
            printf("%d 1 %d\n", i, i);
        else if (k == 5 || k == 6)
            printf("1 %d %d\n", i, i);
        vis[i][i] = 1;
    }
    for (int i = a[2].x + 1; i <= a[1].x; ++i)
    {
        if (k == 1)
            printf("%d %d 1\n", i, a[2].x), vis[i][a[2].x] = 1;
        else if (k == 2)
            printf("%d %d 1\n", a[2].x, i), vis[a[2].x][i] = 1;
        else if (k == 3)
            printf("%d 1 %d\n", i, a[2].x), vis[i][a[2].x] = 1;
        else if (k == 4)
            printf("%d 1 %d\n", a[2].x, i), vis[a[2].x][i] = 1;
        else if (k == 5)
            printf("1 %d %d\n", i, a[2].x), vis[i][a[2].x] = 1;
        else if (k == 6)
            printf("1 %d %d\n", a[2].x, i), vis[a[2].x][i] = 1;
    }
    int cnt = a[0].x - a[1].x;
    for (int i = 1; i <= a[2].x; ++i)
        for (int j = 1; j <= a[1].x; ++j)
        {
            if ((k == 1 || k == 3 || k == 5) && cnt && !vis[j][i])
            {
                if (k == 1)
                    printf("%d %d 1\n", j, i);
                else if (k == 3)
                    printf("%d 1 %d\n", j, i);
                else if (k == 5)
                    printf("1 %d %d\n", j, i);
                --cnt;
            }
            else if ((k == 2 || k == 4 || k == 6) && cnt && !vis[i][j])
            {
                if (k == 2)
                    printf("%d %d 1\n", i, j);
                else if (k == 4)
                    printf("%d 1 %d\n", i, j);
                else if (k == 6)
                    printf("1 %d %d\n", i, j);
                --cnt;
            }
        }
    return 0;
}