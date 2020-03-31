#include <iostream>
#include <cmath>
#include <cstdio>
int num[1000005];
int st[25][1000005];//长度为i起始位置为j的最小值
#define max(a,b) (a>b?a:b)
using namespace std;
void init(int n)
{
    for(int i=1;i<=n;++i)
        scanf("%d",&num[i]);
    for(int i=1;i<=n;++i)
        st[0][i]=num[i];
    for(int i=1;(1<<i)<=n;++i)
        for(int j=1;j<=n;++j)//j+(1<<i)是某一段开始，-1表示上一段的结束
            if(j+(1<<i)-1<=n)
                st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int query(int l,int r)
{
    int k=int(log2(r-l+1)/log2(2.0));
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    int a,b;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(a,b));
    }
    return 0;
}
