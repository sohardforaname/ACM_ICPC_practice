#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define Tree 50005
struct Segtree 
{
    struct node
    {
        int l,r,mark=0;
        int maxlen,lpos,rpos;//最长连续的长度，从左第一个可用，从右第一个可用
        void upd()
        {
            lpos=mark?0:r-l+1;
            rpos=mark?0:r-l+1;
            maxlen=mark?0:r-l+1;
        }
    }tr[Tree<<2];
    void build(int l,int r,int k)
    {
        tr[k].l=l,tr[k].r=r,tr[k].lpos=r-l+1;
        tr[k].rpos=r-l+1,tr[k].maxlen=r-l+1,tr[k].mark=0;
        if(l==r)    
            return;
        int m=(l+r)/2;
        build(l,m,k*2);
        build(m+1,r,k*2+1);
    }
    void down(int k)
    {
        if(tr[k].mark!=-1)
        {
            tr[k*2].mark=tr[k].mark;
            tr[k*2+1].mark=tr[k].mark;
            tr[k].mark=-1;//-1表示已更新
            tr[k*2].upd();
            tr[k*2+1].upd();
        }
    }
    void up(int k)
    {
        tr[k].maxlen=max(tr[k].maxlen,tr[k*2].maxlen);
        tr[k].maxlen=max(tr[k].maxlen,tr[k*2+1].maxlen);
        tr[k].maxlen=max(tr[k].maxlen,tr[k*2].rpos+tr[k*2+1].lpos);
        tr[k].lpos=tr[k*2].lpos;
        tr[k].rpos=tr[k*2+1].rpos;
        if(tr[k*2].maxlen==tr[k*2].r-tr[k*2].l+1)
            tr[k].lpos+=tr[k*2+1].lpos;
        if(tr[k*2+1].maxlen==tr[k*2+1].r-tr[k*2+1].l+1)
            tr[k].rpos+=tr[k*2].rpos;
    }
    int query(int n,int k)
    {
        if(tr[k].l==tr[k].r)
            return tr[k].l;
        down(k);
        if(tr[k*2].maxlen>=n)
            return query(n,k*2);
        else if(tr[k*2].rpos+tr[k*2+1].lpos>=n)
            return tr[k*2].r-tr[k*2].rpos+1;
        else if(tr[k*2+1].maxlen>=n)
            return query(n,k*2+1);
        else
            return 0;            
    }
    void update(int l,int r,int k,int val)
    {
        if(l<=tr[k].l&&r>=tr[k].r)
        {
            tr[k].mark=val;
            tr[k].upd();
            return;
        }
        down(k);
        int m=(tr[k].l+tr[k].r)/2;
        if(l<=m)
            update(l,r,k*2,val);
        if(r>m)    
            update(l,r,k*2+1,val);
        up(k);
    }
};
Segtree seg;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,c,pos;
    cin>>n>>m;
    seg.build(1,n,1);
    for(int i=0;i<m;++i)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b;
            pos=seg.query(b,1);
            if(pos)
                seg.update(pos,pos+b-1,1,1);
            cout<<pos<<endl;    
            
        }
        else
        {
            cin>>b>>c;
            seg.update(b,b+c-1,1,0);
        }
    }
    return 0;
}
