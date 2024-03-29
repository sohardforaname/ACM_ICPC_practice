#include <cstdio>
#include <iostream>
using namespace std;
int pre[100005]; //100000个点
int ranks[100005]; //
int cnt;
void init(int n)
{
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
        ranks[i] = 0;
    }
}
int find(int x)
{
    int r = x, i = x, j;
    while (pre[r] != r)
        r = pre[r]; //找父节点
    while (i != r) {
        j = pre[i]; //记录i的父节点
        pre[i] = r; //将根节点赋给i的父节点
        i = j; //一直寻找到根节点为止
    }
    return r;
}
bool iscc(int x, int y)
{
    return pre[x] == pre[y];
}
void unity(int x, int y)
{
    int rootx = find(x), rooty = find(y);
    if (rootx == rooty)
        return;
    else if (ranks[rootx] > ranks[rooty]) {
        pre[rooty] = rootx;
        //--cnt;
    } else {
        if (ranks[rootx] == ranks[rooty])
            ++ranks[rooty];
        pre[rootx] = rooty;
        //--cnt;
    }
}
int main()
{
    int n, m, a, b;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        init(n);
        cnt = -1;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            unity(a - 1, b - 1);
        }
        for (int i = 0; i < n; ++i)
            if (pre[i] == i)
                ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
