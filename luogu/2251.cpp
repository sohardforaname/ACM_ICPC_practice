#include <cstdio>
#include <cmath>
#define min(a,b) (a<b?a:b)
int num[1000005];
int st[1000005][25];
void init(int n)
{
    for(int i=1;i<=n;++i)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;++i)
        st[i][0]=num[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=m;i<=n;++i)
        printf("%d\n",query(i-m+1,i));
    return 0;
}
