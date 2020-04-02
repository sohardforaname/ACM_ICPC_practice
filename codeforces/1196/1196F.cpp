#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct edge
{
    int u,v,w;
    bool operator<(const edge &a)const
    {
        return w<a.w;
    }
};
edge e[MAXN];
int hashing[MAXN];
long long G[1005][1005],E[1005*1005+10];
void init()
{
    memset(G,0x3f3f3f3f,sizeof(G));
    for(int i=0;i<1005;++i)
        G[i][i]=0;
}
long long solve(int k,int m)
{
    init();
    memset(hashing,0,sizeof(hashing));
    sort(e,e+m);
    m=min(k,m);
    int pos=0;
    for(int i=0;i<m;++i)
    {
        if(!hashing[e[i].u])
            hashing[e[i].u]=++pos;
        if(!hashing[e[i].v])
            hashing[e[i].v]=++pos;
        G[hashing[e[i].u]][hashing[e[i].v]]=e[i].w;
        G[hashing[e[i].v]][hashing[e[i].u]]=e[i].w;
    }
    for(int l=1;l<=2*m;++l)
        for(int i=1;i<=2*m;++i)
            for(int j=1;j<=2*m;++j)
                G[i][j]=min(G[i][j],G[i][l]+G[l][j]);
    pos=0;
    for(int i=1;i<=2*m;++i)
        for(int j=i+1;j<=2*m;++j)
            if(G[i][j]<0x3f3f3f3f3f3f3f3f)
                E[pos++]=G[i][j];
    sort(E,E+pos);
    return E[k-1];
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
        cin>>e[i].u>>e[i].v>>e[i].w;
    cout<<solve(k,m)<<endl;
    return 0;
}
