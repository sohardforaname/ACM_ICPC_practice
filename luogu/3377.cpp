#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
struct Leftist
{
    struct node
    {
        int l,r,val,dis,fa,rt;
    };
    node tr[MAXN];
    int tot=1;
    int merge(int x,int y)
    {
        if(y==0)
            return x;
        else if(x==0)
            return y;
        if(tr[x].val>tr[y].val||(tr[x].val==tr[y].val&&x>y))
            swap(x,y);
        tr[x].r=merge(tr[x].r,y);
        tr[tr[x].r].fa=x;
        tr[tr[x].l].rt=tr[tr[x].r].rt=tr[x].rt=x;
        if(tr[tr[x].r].dis>tr[tr[x].l].dis)
            swap(tr[x].l,tr[x].r);
        tr[x].dis=tr[x].r==0?0:tr[tr[x].r].dis+1;
        return x;
    }
    int add(int val,int x)
    {
        tr[tot].l=tr[tot].r=tr[tot].dis=0;
        tr[tot].val=val; 
        return merge(tot++,x);
    }
    int del(int x)
    {
        int l=tr[x].l,r=tr[x].r;
        tr[l].fa=tr[l].rt=l,tr[r].fa=tr[r].rt=r;
        tr[x].fa=tr[x].l=tr[x].r=tr[x].dis=0;
        tr[x].val=-INF;
        return tr[x].rt=merge(l,r);
    }
    void init(int n)
    {
        for(int i=0;i<=n;++i)
        {
            tr[i].l=tr[i].r=tr[i].dis=0;
            tr[i].fa=tr[i].rt=i;
        }
    }
    int build(int n)
    {
        init(n);
        queue<int>que;
        for(int i=1;i<=n;++i)
            que.push(i);
        while(que.size()>1)
        {
            int x=que.front();
            que.pop();
            int y=que.front();
            que.pop();
            que.push(merge(x,y));
        }
        return que.front();
    }
    int findset(int x)
    {
        return tr[x].rt==x?x:tr[x].rt=findset(tr[x].rt);
    }
};
Leftist lf;
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n,m,a,b,c;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    lf.init(n);
    for(int i=1;i<=n;++i)
        //cin>>lf.tr[i].val;
        scanf("%d",&lf.tr[i].val);
    for(int i=0;i<m;++i)
    {
        //cin>>a;
        scanf("%d",&a);
        if(a==1)
        {
            //cin>>b>>c;
            scanf("%d%d",&b,&c);
            int x=lf.findset(b),y=lf.findset(c);
            if(lf.tr[b].val==-INF||lf.tr[c].val==-INF||x==y)
                continue;
            else
                lf.merge(x,y);
        }
        else if(a==2)
        {
            //cin>>b;
            scanf("%d",&b);
            c=lf.findset(b);
            if(lf.tr[b].val==-INF)
                //cout<<-1<<endl;
                printf("%d\n",-1);
            else
            {
                //cout<<lf.tr[c].val<<endl;
                printf("%d\n",lf.tr[c].val);
                lf.del(c);
            }
        }
    }
    return 0;
}
