#include <bits/stdc++.h>
using namespace std;
struct Line
{
    int x1,x2,y1,y2;
    bool tag;
    bool operator<(const Line &a)const
    {
        return y2==a.y2?x2<a.x2:y2<a.y2;
    }
    Line(int a,int b,int c,int d)
    {
        x1=a,y1=b,x2=c,y2=d;
    }
};
struct segtree
{
    struct node
    {
        int l,r,val;
    };
    node tr[10015*4];
    void build(int l,int r,int k)
    {
        tr[k].l=l,tr[k].r=r;
        if(l==r)
        {
            tr[k].val=0;
            return;
        }
        int m=(l+r)/2;
        build(l,m,k*2);
        build(m+1,r,k*2+1);
        tr[k].val=tr[k*2].val+tr[k*2+1].val;
    }
    void update(int pos,int k,int val)
    {
        if(tr[k].l==tr[k].r)
        {
            tr[k].val=val;
            return;
        }
        int m=(tr[k].l+tr[k].r)/2;
        if(pos<=m)
            update(pos,k*2,val);
        else
            update(pos,k*2+1,val);
        tr[k].val=tr[k*2].val+tr[k*2+1].val;
    }
    int query(int l,int r,int k)
    {
        if(l<=tr[k].l&&r>=tr[k].r)
        {
            return tr[k].val;
            return;
        }
        int m=(tr[k].l+tr[k].r)/2;
        int ans=0;
        if(l<=m)
            ans+=query(l,r,k*2);
        if(r>m)
            ans+=query(l,r,k*2+1);
        return ans;
    }
};
vector<Line>ver,hor;
int main()
{
    int n,x1,x2,y1,y2;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x1>>y1>>x2>>y2;
        x1+=5001,y1+=5001,x2+=5001,y2+=5001;
        if(x1==x2)
        {
            if(y1>y2)
                swap(y1,y2);
            ver.push_back(Line(x1,y1,x2,y2));
        }
        else if(y1==y2)
        {
            if(x1>x2)
                swap(y1,y2);
            hor.push_back(Line(x1,y1,x2,y2));
        }
    }
    sort(ver.begin(),ver.end());
    sort(hor.begin(),hor.end());
    for(int i=0;i<hor.size();++i)
    {
        for(int j=0;j<ver.size();++j)
    }
}
