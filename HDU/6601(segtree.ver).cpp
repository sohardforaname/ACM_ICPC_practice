#include <bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
#define MAXN 100005
int num[MAXN];
void print(vector<int> &vec)
{
    for (auto &i : vec)
        cout << " " << i;
    cout << endl;
}
int tagtop;
struct SegTree
{
    struct node
    {
        vector<int> val;
        int l, r;
    };
    node tr[MAXN << 2];
    void build(int l, int r, int k)
    {
        tr[k].l = l, tr[k].r = r;
        if (l == r)
        {
            tr[k].val.resize(1);
            tr[k].val[0] = num[l];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, k << 1);
        build(m + 1, r, (k << 1) + 1);
        tr[k].val.resize(min(90, r - l + 1));
        merge(tr[k << 1].val.begin(), tr[k << 1].val.end(), tr[(k << 1) + 1].val.begin(), tr[(k << 1) + 1].val.end(),
              tr[k].val.begin(), greater<int>());
        tr[k].val.resize(min(45, r - l + 1));
    }
    int tag[MAXN], tagpos[MAXN];
    void query(int l, int r, int k)
    {
        if (l <= tr[k].l && r >= tr[k].r)
        {
            tag[tagtop] = k, tagpos[tagtop++] = 0;
            return;
        }
        int m = (tr[k].l + tr[k].r) / 2;
        ;
        if (l <= m)
            query(l, r, k << 1);
        if (r > m)
            query(l, r, (k << 1) + 1);
    }
    int val[50], maxtop, maxval, maxpos;
    long long answer(int l, int r)
    {
        if (r - l + 1 < 3)
            return -1;
        query(l, r, 1);
        bool flag = 0;
        int t = 45;
        maxtop = 0;
        while (t-- && !flag)
        {
            maxval = maxpos = 0;
            flag = 1;
            for (int i = 0; i < tagtop; ++i)
            {
                if (tagpos[i] < tr[tag[i]].val.size())
                {
                    if (tr[tag[i]].val[tagpos[i]] > maxval)
                    {
                        maxval = tr[tag[i]].val[tagpos[i]];
                        maxpos = i;
                    }
                    flag = 0;
                }
            }
            if (!flag)
            {
                ++tagpos[maxpos];
                val[maxtop++] = maxval;
            }
        }
        for (int i = 2; i < maxtop; ++i)
            if (val[i - 2] < val[i - 1] + val[i])
                return (long long)(val[i - 2]) + (long long)(val[i - 1]) + (long long)(val[i]);
        return -1;
    }
};
SegTree tr;
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        tr.build(1, n, 1);
        int l, r;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &l, &r);
            tagtop = 0;
            printf("%lld\n", tr.answer(l, r));
        }
    }
    return 0;
}
