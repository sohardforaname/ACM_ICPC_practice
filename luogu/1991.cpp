#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int pre[505];
struct Edge
{
    int u,v;
    double dis;
    bool operator<(const Edge &a)const
    {
        return this->dis<a.dis;
    }
};
Edge e[250005];
void init(int n)
{
    for(int i=1;i<=n;++i)
        pre[i]=i;
}
int find(int x)
{
    while(x!=pre[x])
        x=pre[x];
    return x;
}
bool isok(int x,int y)
{
    return find(x)==find(y);
}
void unite(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        pre[fx]=fy;
}
void kruskal(int n,int m)
{
    sort(e,e+n*n);
    double ans=0;
    int num=0;
    for(int i=0;i<n-m;++num)
    {
        //cout<<e[num].u<<" "<<e[num].v<<" "<<e[num].dis<<endl;
        if(!isok(e[num].u,e[num].v))
        {
            ans=max(ans,e[num].dis);
            unite(e[num].u,e[num].v);
            ++i;
        }
    }
    printf("%.2f\n",ans);
}
int dis[505][2];
double caldis(int x1,int x2,int y1,int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
        cin>>dis[i][0]>>dis[i][1];
    init(m);
    int num=0;
    for(int i=0;i<m;++i)
        for(int j=0;j<m;++j)
        {
            if(i!=j)
            {
                double d=caldis(dis[i][0],dis[j][0],dis[i][1],dis[j][1]);
                e[num].u=i,e[num].v=j,e[num++].dis=d;
            }
        }
    kruskal(m,n);
    return 0;
}
