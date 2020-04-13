#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct segment
{
#define ls (k << 1)
#define rs ((k << 1) + 1)
    struct node
    {
        int l, r;
        set<int> s;
    };
    node tr[N];
    void build(int l, int r, int k)
    {
        if (l == r)
            return;
        tr[k].l = l, tr[k].r = r;
        int m = (l + r) / 2;
        build(l, m, ls);
        build(m + 1, r, rs);
    }
    void update(int l, int r, int k, pair<int, int> &p)
    {
    }
}