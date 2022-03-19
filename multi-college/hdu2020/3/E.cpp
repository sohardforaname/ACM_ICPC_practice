#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int fa[N], r[N], c[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void join(int x, int y) //x to y
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        r[fy] += r[fx];
        c[fy] += c[fx];
    }
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        r[i] = 0; //change to 1 if he is a reader
        c[i] = 0; //change to 1 if he is a coder.
    }
}