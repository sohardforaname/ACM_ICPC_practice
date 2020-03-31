#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v;
    bool tag;
    edge(int _u,int _v)
    {
        u=_u,v=_v,tag=0;
    }
};
int deg[1000005],lim[1000005];
vector<edge>E;
int main()
{
    int n,m,a,b,pos=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        E.push_back(edge(a,b));
        ++deg[a];
        ++deg[b];
    }
    for(int i=1;i<=n;++i)
        lim[i]=(deg[i]+1)/2;
    //for(int i=1;i<=n;++i)
        //cout<<deg[i]<<(i==n?'\n':' ');
    int k=(n+m+1)/2;
    random_shuffle(E.begin(),E.end());
    for(int i=0;i<E.size()&&m>k;++i)
    {
        auto &j=E[i];
        if(deg[j.u]==lim[j.u])
            continue;
        if(deg[j.v]==lim[j.v])
            continue;
        if(!j.tag)
        {
            --deg[j.v];
            --deg[j.u];
            --m;
            j.tag=1;
        }
    }
    printf("%d\n",m);
    for(auto &j:E)
        if(!j.tag)
            printf("%d %d\n",j.u,j.v);
    return 0;
}
