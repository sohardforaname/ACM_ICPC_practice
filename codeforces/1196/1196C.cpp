#include <bits/stdc++.h>
using namespace std;
int MAXN=100000;
int maxnx[100005],minnx[100005],maxny[100005],minny[100005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,y,a,b,c,d;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            maxnx[i]=maxny[i]=MAXN;
            minnx[i]=minny[i]=-MAXN;
        }
        for(int i=0;i<n;++i)
        {
            cin>>x>>y>>a>>b>>c>>d;
            if(!a) 
                minnx[i]=x;
            if(!b)
                maxny[i]=y;
            if(!c)
                maxnx[i]=x;
            if(!d)
                minny[i]=y;
        }
        int maxx=MAXN+1,minx=-MAXN-1,maxy=MAXN+1,miny=-MAXN-1;
        for(int i=0;i<n;++i)
        {
            maxx=min(maxx,maxnx[i]);
            maxy=min(maxy,maxny[i]);
            minx=max(minx,minnx[i]);
            miny=max(miny,minny[i]);
        }
        if(maxx<minx||maxy<miny)
            cout<<0<<endl;
        else
            cout<<1<<" "<<minx<<" "<<miny<<endl;   
    }
    return 0;
}
