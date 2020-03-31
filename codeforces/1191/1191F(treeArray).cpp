#include <iostream>
#include <algorithm>
#include <cstring>
#pragma GCC optimize(2)
using namespace std;
struct Fenwick
{
    bool cntx[200005];
    int c[200005];
    int lowbit(int x)
    {
        return x&(-x);
    }
    void update(int pos,int val,int n)//Containing error
    {
        if(cntx[pos])
            return;
        else
        {
            cntx[pos]=1;
            for(int i=pos;i<=n;i+=lowbit(i))
                c[i]+=val;
        }
    }
    int sum(int pos,int n)
    {
        int sum=0;
        for(int i=pos;i;i-=lowbit(i))
            sum+=c[i];
        return sum;
    }
    int query(int l,int r,int n)
    {
        if(l>r)
            return 0;
        return sum(r,n)-sum(l-1,n);
    }
    void print(int n)
    {
        for(int i=0;i<n;++i)
            cout<<c[i]<<" ";
        cout<<endl;
    }
};
struct Point
{
    int x,y;
    bool operator<(const Point &a)const
    {
        return y==a.y?x<a.x:y>a.y;
    }
};
Point p[200005];
int x[200005],y[200005],ydiv[200005];
Fenwick tr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x[i]>>y[i];
        p[i].x=x[i];
        p[i].y=y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    int xn=unique(x,x+n)-x;
    int yn=unique(y,y+n)-y;
    for(int i=0;i<n;++i)
    {
        p[i].x=lower_bound(x,x+xn,p[i].x)-x+1;
        p[i].y=lower_bound(y,y+yn,p[i].y)-y+1;
        //cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    sort(p,p+n);
    //É¨ÃèÏß
    memset(tr.c,0,sizeof(tr.c));
    int beg=0,cur=0;
    //max xn+1
    long long sum=0;
    while(beg<n)
    {
        int pos=0;
        while(cur<n&&p[cur].y==p[beg].y)
        {
            tr.update(p[cur].x,1,xn+1);
            ydiv[pos++]=p[cur++].x;
            //tr.print(xn+1);
        }
        ydiv[pos]=xn+1;
        for(int i=0;i<pos;++i)
        {
            long long cntl=tr.query(1,ydiv[i]-1,xn+1);
            long long cntr=tr.query(ydiv[i]+1,ydiv[i+1]-1,xn+1);
            sum+=(cntl+1)*(cntr+1);
        }
        beg=cur;
    }
    cout<<sum<<endl;
    return 0;
}
