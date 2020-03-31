#include <cstdio>
#include <cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int num[50005];
int minn[50005][25],maxn[50005][25];
void init(int n)
{
    for(int i=1;i<=n;++i)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;++i)
    {
        minn[i][0]=num[i];
        maxn[i][0]=num[i];
    }
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
        {
            maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
            minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
        }
}
int maxquery(int l,int r)
{
    int k=log2(r-l+1);
    return max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}
int minquery(int l,int r)
{
    int k=log2(r-l+1);
    return min(minn[l][k],minn[r-(1<<k)+1][k]);
}
int main()
{
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",maxquery(a,b)-minquery(a,b));
    }
    return 0;
}
