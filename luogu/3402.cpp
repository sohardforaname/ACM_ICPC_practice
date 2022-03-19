#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int lson[N << 5], rson[N << 5], fa[N << 5], dep[N << 5], root[N << 5];
int cnt, n, m;
void build(int &rt, int l, int r)
{
    rt = ++cnt;
    if (l == r)
    {
        fa[rt] = l;
        return;
    }
    int m = (l + r) >> 1;
    build(lson[rt], l, m);
    build(rson[rt], m + 1, r);
}
void merge(int lst, int &rt, int l, int r, int pos, int f)
{
    rt = ++cnt;
    lson[rt] = lson[lst];
    rson[rt] = rson[lst];
    if (l == r)
    {
        fa[rt] = f;
        dep[rt] = dep[lst];
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        merge(lson[lst], lson[rt], l, m, pos, f);
    else
        merge(rson[lst], rson[rt], m + 1, r, pos, f);
}
void upd(int rt, int l, int r, int pos)
{
    if (l == r)
    {
        ++dep[rt];
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        upd(lson[rt], l, m, pos);
    else
        upd(rson[rt], m + 1, r, pos);
}
int query(int rt, int l, int r, int pos)
{
    if (l == r)
        return rt;
    int m = (l + r) >> 1;
    if (pos <= m)
        return query(lson[rt], l, m, pos);
    else
        return query(rson[rt], m + 1, r, pos);
}
int find(int rt, int x)
{
    int cur = query(rt, 1, n, x);
    if (fa[cur] == x)
        return cur;
    return find(rt, fa[cur]);
}
void join(int rt, int x, int y)
{
    int posx = find(root[rt], x), posy = find(root[rt], y);
    if (fa[posx] != fa[posy])
    {
        if (dep[posx] > dep[posy])
            swap(posx, posy);
        merge(root[rt - 1], root[rt], 1, n, fa[posx], fa[posy]);
        if (dep[posx] == dep[posy])
            upd(root[rt], 1, n, fa[posy]);
    }
}
void search(int rt, int x, int y)
{
    int posx = find(root[rt], x), posy = find(root[rt], y);
    if (fa[posx] == fa[posy])
        puts("1");
    else
        puts("0");
}
int main()
{
    scanf("%d%d", &n, &m);
    build(root[0], 1, n);
    for (int i = 1; i <= m; ++i)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            root[i] = root[i - 1];
            join(i, x, y);
        }
        else if (op == 2)
        {
            int x;
            scanf("%d", &x);
            root[i] = root[x];
        }
        else if (op == 3)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            root[i] = root[i - 1];
            search(i, x, y);
        }
    }
    return 0;
}