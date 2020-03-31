#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int f[100005];
int res[100005];
vector<int>E[100005],Q[100005];
bool vis[100005],rt[100005];
int find(int x)
{
    return x==f[x]?x:f[x]=find(f[x]);
}
void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        f[fx]=fy;
}
void dfs(int u)
{
    for(int i=0;i<E[u].size();++i)
        if(!vis[E[u][i]])
        {
            dfs(E[u][i]);
            join(E[u][i],u);
            vis[E[u][i]]=1;
        }
    for(int i=0;i<Q[u].size();++i)
        if(vis[Q[u][i]])
            ++res[find(Q[u][i])];
}
void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        vis[i]=0;
        rt[i]=0;
        res[i]=0;
        E[i].clear();
        Q[i].clear();
        f[i]=i;
    }
}
int main()
{
    int n,m,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        init(n);
        for(int i=0;i<n;++i)
        {
            scanf("%d:(%d)",&m,&a);
            for(int i=0;i<a;++i)
            {
                scanf("%d",&b);
                E[m].push_back(b);
                rt[b]=1;
            }
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf(" (%d %d)",&a,&b);
            Q[a].push_back(b);
            Q[b].push_back(a);
        }
        for(int i=1;i<=n;++i)
            if(!rt[i])
            {
                dfs(i);
                break;
            }
        for(int i=1;i<=n;++i)
            if(res[i])
                printf("%d:%d\n",i,res[i]);
    }
    return 0;
}
