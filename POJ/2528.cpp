#pragma GCC optimize(3)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define Tree 20005
bool vis[10000002];
int h[10000002];
struct P
{
    int l,r;
}dat[10005];
void cal(int n)//¿Î…¢ªØ
{
    int pos=0;
    memset(vis,0,sizeof(vis));
    memset(h,0,sizeof(h));
    for(int i=0;i<n;++i)
    {
        cin>>dat[i].l>>dat[i].r;
        if(!vis[dat[i].l])
            vis[dat[i].l]=1;
        if(!vis[dat[i].r])
            vis[dat[i].r]=1;    
    }
    for(int i=0;i<10000002;++i)
        if(vis[i])
            h[i]=++pos;
}
int now;
struct Segtree
{
    bool vis[10005];
    struct node
    {
        int l,r,val;
    }tr[Tree*4];
    void clean()
    {
        for(int i=0;i<Tree*4;++i)
            tr[i].val=-1;
        memset(vis,0,sizeof(vis));
    }
    void build(int l,int r,int k)
    {
        tr[k].l=l,tr[k].r=r,tr[k].val=-1;
        if(l==r)
            return;
        int m=(l+r)/2;
        build(l,m,k*2);
        build(m+1,r,k*2+1);    
    }
    void down(int k)
    {
        if(tr[k].val!=-1)
        {
            tr[k*2].val=tr[k].val;
            tr[k*2+1].val=tr[k].val;
        }
        tr[k].val=-1;
    }
    void update(int l,int r,int val,int k)
    {
        if(l<=tr[k].l&&r>=tr[k].r)
        {
            tr[k].val=val;
            return;
        }
        down(k);
        int m=(tr[k].l+tr[k].r)/2;
        if(l<=m)
            update(l,r,val,k*2);
        if(r>m)
            update(l,r,val,k*2+1);
    }
    void query(int k)
    {
        if(tr[k].l==tr[k].r)
        {
            if(tr[k].val!=-1&&tr[k].val!=now)
                vis[tr[k].val]=1;
            now=tr[k].val; 
            return;   
        }
        down(k);
        query(k*2);
        query(k*2+1);
    }
};
Segtree seg;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    seg.build(1,20005,1);
    int t,n;
    cin>>t;
    while(t--)
    {
        seg.clean();
        cin>>n;
        cal(n);
        now=-1;
        for(int i=0;i<n;++i)
            seg.update(h[dat[i].l],h[dat[i].r],i,1);
        seg.query(1);
        int ans=0;
        for(int i=0;i<10005;++i)
            if(seg.vis[i])
                ++ans;
        cout<<ans<<endl;            
    }
    return 0;
}
