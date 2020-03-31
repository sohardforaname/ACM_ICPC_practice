#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ls (k<<1)
#define rs (k<<1)+1
    
const int MAXBUF = 1 << 20;
char buf[1<<20], *fh=NULL, *ft=NULL;
inline char gc() 
{
    if(fh == ft) 
    {
        int l = fread(buf, 1, MAXBUF, stdin);
        ft = (fh = buf) + l;
    }
    return *fh++;
}
    
inline int read() 
{
    int x = 0;
    char c = gc();
    for(; c < '0' || c > '9'; c = gc())
        ;
    for(; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + c - '0';
    return x ;
}
inline void _write(long long x) 
{
    if(x > 9)
        _write(x / 10);
    putchar(x % 10 + '0');
}
inline void write(long long x) 
{
    _write(x);
    //putchar('\n');
}
    
struct segtree
{
    struct node
    {
        int l,r,val,lazy;
    };
    node tr[MAXN<<2];
    void build(int l,int r,int k)
    {
        tr[k].l=l,tr[k].r=r;
        tr[k].val=tr[k].lazy=0;
        if(l==r)
            return;
        int m=(l+r)>>1;
        build(l,m,ls);
        build(m+1,r,rs);
    }
    void down(int k)
    {
        tr[ls].lazy=max(tr[k].lazy,tr[ls].lazy);
        tr[rs].lazy=max(tr[k].lazy,tr[rs].lazy);
        tr[k].lazy=0;
    }
    void update1(int pos,int k,int val)
    {
        if(tr[k].l==tr[k].r)
        {
            tr[k].lazy=0;
            tr[k].val=val;
            return;
        }
        down(k);
        int m=(tr[k].l+tr[k].r)>>1;
        if(pos<=m)
            update1(pos,ls,val);
        else
            update1(pos,rs,val);
        tr[k].val=min(tr[ls].val,tr[rs].val);
    }
    void update2(int l,int r,int k,int val)
    {
        if(l<=tr[k].l&&tr[k].r>=tr[k].r)
        {
            tr[k].lazy=max(tr[k].lazy,val);
            return;
        }
        down(k);
        int m=(tr[k].l+tr[k].r)>>1;
        if(l<=m&&val>tr[ls].val)
            update2(l,r,ls,val);
        if(r>m&&val>tr[rs].val)
            update2(l,r,rs,val);
        tr[k].val=min(tr[ls].val,tr[rs].val);
    }
    int query(int pos,int k)
    {
        if(tr[k].l==tr[k].r)
            return max(tr[k].val,tr[k].lazy);
        down(k);
        int m=(tr[k].l+tr[k].r)>>1;
        if(pos<=m)
            return query(pos,ls);
        else
            return query(pos,rs);
    }
};
segtree tr;
int main()
{
    int n,m,a,p,x;
    //scanf("%d",&n);
    n=read();
    tr.build(1,n,1);
    for(int i=1;i<=n;++i)
    {
        a=read();
        tr.update1(i,1,a);
    }
    m=read();
    for(int i=0;i<m;++i)
    {
        a=read();
        p=read();
        if(a==1)
        {
            x=read();
            tr.update1(p,1,x);
        }
        else
            tr.update2(1,n,1,p);
    }
    for(int i=1;i<=n;++i)
    {
        write(tr.query(i,1));
        putchar((i==n?'\n':' '));
    }
    return 0;
}
