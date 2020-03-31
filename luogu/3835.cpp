#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
struct Treap
{
    struct node
    {
        int lc,rc,val,rnk,size;
    };
    node tr[MAXN*50];
    int root[MAXN*10];
    int cnt=0;
    void init()
    {
        cnt=0;
    }
    void copy(int x,int y)
    {
        tr[x]=tr[y];
    }
    void pushup(int p)
    {
        tr[p].size=tr[tr[p].lc].size+tr[tr[p].rc].size+1;
    }
    int _rand()
    {
        static int seed=int(12345);
        return seed = int(seed * 482711ll % 2147483647);
    }
    void merge(int &rt,int a,int b)//保证a的权值小于b的权值
    {
        if(!a||!b)
        {
            rt=a+b;
            return;
        }
        if(tr[a].rnk<tr[b].rnk)
        {
            rt=++cnt;
            copy(rt,a);
            merge(tr[rt].rc,tr[a].rc,b);
        }
        else
        {
            rt=++cnt;
            copy(rt,b);
            merge(tr[rt].lc,a,tr[b].lc);
        }
        pushup(rt);
    }
    void split(int rt,int &a,int &b,int val)
    {
        if(!rt)
        {
            a=b=0;
            return;
        }
        if(tr[rt].val<=val)
        {
            a=++cnt;
            copy(a,rt);
            split(tr[rt].rc,tr[a].rc,b,val);
            pushup(a);
        }
        else
        {
            b=++cnt;
            copy(b,rt);
            split(tr[rt].lc,a,tr[b].lc,val);
            pushup(b);
        }
    }
    int newnode(int val)
    {
        int rt=++cnt;
        tr[rt].size=1;
        tr[rt].val=val;
        tr[rt].lc=tr[rt].rc=0;
        tr[rt].rnk=_rand();
        return rt;
    }
    void insert(int &rt,int val)
    {
        int x=0,y=0,n=newnode(val);
        split(rt,x,y,val);
        merge(x,x,n);
        merge(rt,x,y);
    }
    void del(int &rt,int val)
    {
        int x=0,y=0,z=0;
        split(rt,x,y,val);
        split(x,x,z,val-1);
        merge(z,tr[z].lc,tr[z].rc);
        merge(x,x,z);
        merge(rt,x,y);
    }
    int querynum(int rt,int rnk)
    {
        while(tr[tr[rt].lc].size+1!=rnk)
        {
            if(tr[tr[rt].lc].size<rnk)
                rnk-=tr[tr[rt].lc].size+1,rt=tr[rt].rc;
            else
                rt=tr[rt].lc;
        }
        return tr[rt].val;
    }
    int queryrnk(int &rt,int val)
    {
        int x=0,y=0;
        split(rt,x,y,val-1);
        int tmp=tr[x].size+1;
        merge(rt,x,y);
        return tmp;
    }
    int queryfront(int &rt,int val)
    {
        int x=0,y=0;
        split(rt,x,y,val-1);
        int tmp=querynum(x,tr[x].size);
        merge(rt,x,y);
        return tmp;
    }
    int queryback(int &rt,int val)
    {
        int x=0,y=0;
        split(rt,x,y,val);
        int tmp=querynum(y,1);
        merge(rt,x,y);
        return tmp;
    }
};
Treap tr;
int p;
int main()
{
    int n;
    scanf("%d",&n);
    int m,ope,k;
    tr.init();
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&m,&ope,&k);
        tr.root[i]=tr.root[m];
        if(ope==1)
            tr.insert(tr.root[i],k);
        else if(ope==2)
            tr.del(tr.root[i],k);
        else if(ope==3)
            printf("%d\n",tr.queryrnk(tr.root[i],k));
        else if(ope==4)
            printf("%d\n",tr.querynum(tr.root[i],k));
        else if(ope==5)
            printf("%d\n",tr.queryfront(tr.root[i],k));
        else if(ope==6)
            printf("%d\n",tr.queryback(tr.root[i],k));
    }
    return 0;
}
