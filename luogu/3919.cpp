#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int num[MAXN];
int cnt=-1;
struct cheiftree
{
    struct node
    {
        int l,r,val;
    };
    node tr[MAXN*25];
    int rt[MAXN];
    void build(int l,int r,int &rt)//l一定是1，r一定是n
    {
        rt=++cnt;
        tr[rt].val=num[l];
        if(l==r)
            return;
        int m=(l+r)/2;
        build(l,m,tr[rt].l);
        build(m+1,r,tr[rt].r);
    }
    void update(int l,int r,int &rt,int lst,int x,int val)
    {
        rt=++cnt;
        tr[rt]=tr[lst];
        if(l==r)
        {
            tr[rt].val=val;
            return;
        }
        int m=(l+r)/2;
        if(x<=m)
            update(l,m,tr[rt].l,tr[lst].l,x,val);
        else
            update(m+1,r,tr[rt].r,tr[lst].r,x,val);
    }
    int query(int rt,int l,int r,int x)
    {
        if(l==r)
            return tr[rt].val;
        int m=(l+r)/2;
        if(x<=m)
            return query(tr[rt].l,l,m,x);
        else
            return query(tr[rt].r,m+1,r,x);
    }
};
cheiftree tr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>num[i];
    tr.build(1,n,tr.rt[0]);
    int a,b,c,d;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        if(b==1)
        {
            cin>>d;
            tr.update(1,n,tr.rt[i],tr.rt[a],c,d);
        }
        else
        {
            tr.rt[i]=tr.rt[a];
            cout<<tr.query(tr.rt[i],1,n,c)<<endl;
        }
    }
    return 0;
}
