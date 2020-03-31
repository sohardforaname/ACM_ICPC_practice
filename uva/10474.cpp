#include <bits/stdc++.h>
using namespace std;
int num[10005];
int main()
{
    int n,m,cas=0;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        for(int i=0;i<n;++i)
            scanf("%d",&num[i]);
        sort(num,num+n);
        int q;
        printf("CASE# %d:\n",++cas);
        for(int i=0;i<m;++i)
        {
            scanf("%d",&q);
            int *pos=lower_bound(num,num+n,q);
            if(*pos!=q)
                printf("%d not found\n",q);
            else
                printf("%d found at %d\n",q,pos-num+1);
        }
    }
    return 0;
}
