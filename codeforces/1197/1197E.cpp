#include <bits/stdc++.h>
using namespace std;
bool vis[300005];
int ans[500005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,u,v;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis[0])*3*(n+1));
        int num=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&u,&v);
            if(!vis[u]&&!vis[v])
            {
                vis[u]=vis[v]=1;
                ans[num++]=i;
            }
        }
        if(num<n)
        {
            printf("IndSet\n");
            int pos=0;
            for(int i=1;i<=3*n&&pos<n;++i)
                if(!vis[i])
                    printf("%d%c",i,(++pos==n?'\n':' '));
        }
        else
        {
            printf("Matching\n");
            for(int i=1;i<=n;++i)
                printf("%d%c",ans[i-1],(i==n?'\n':' '));
        }
    }
    return 0;
}
