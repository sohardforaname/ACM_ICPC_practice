#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int num[MAXN];
ll sum[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&num[i]);
    sort(num+1,num+n+1,greater<int>());
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+num[i];
    int m,tmp;
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",&tmp);
        printf("%lld\n",sum[n]-num[tmp]);
    }
    return 0;
}
