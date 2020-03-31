#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ls k << 1
#define rs (k << 1) + 1
int a[MAXN], b[MAXN];
struct segtree
{
    struct node
    {
        int l, r, num;
        long long sum;
    };
    node tr[MAXN << 2];
    void up(int k)
    {
        tr[k].num = tr[ls].num + tr[rs].num;
        tr[k].sum = tr[ls].sum + tr[rs].sum;
    }
    void build(int l, int r, int k)
    {
        tr[k].l = l, tr[k].r = r;
        tr[k].sum = tr[k].num = 0;
        if (l == r)
            return;
        int m = (l + r) / 2;
        build(l, m, ls);
        build(m + 1, r, rs);
    }
    void update(int pos, int k, int val)
    {
        if (tr[k].l == tr[k].r)
        {
            ++tr[k].num;
            tr[k].sum += val;
            return;
        }
        int m = (tr[k].l + tr[k].r) / 2;
        if (pos <= m)
            update(pos, ls, val);
        else
            update(pos, rs, val);
        up(k);
    }
    int query(int k, int lim)
    {
        if (tr[k].l == tr[k].r)
            return min(lim / b[tr[k].l], tr[k].num); //ѡ���Ŀ�ѡ����
        if (tr[k].sum <= lim)
            return tr[k].num;
        if (tr[ls].sum >= lim)
            return query(ls, lim);
        else
            return tr[ls].num + query(rs, lim - tr[ls].sum);
    }
};
segtree tr;
int main()
{
    int T, n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int nn = unique(b + 1, b + n + 1) - (b + 1);
        //cout<<nn<<endl;
        tr.build(1, nn, 1);
        for (int i = 1; i <= n; ++i)
            a[i] = lower_bound(b + 1, b + nn + 1, a[i]) - b;
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
                printf("%d ", 0);
            else
                printf("%d ", i - 1 - tr.query(1, m - b[a[i]]));
            tr.update(a[i], 1, b[a[i]]);
            //cout<<endl;
            //for(int i=0;i<=20;++i)
            //cout<<tr.tr[i].l<<" "<<tr.tr[i].r<<" "<<tr.tr[i].num<<" "<<tr.tr[i].sum<<endl;
        }
        printf("\n");
    }
    return 0;
}
