#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        while(b>0&&c>1)
        {
            ans+=3;
            b-=1;
            c-=2;
        }
        while(b>1&&a>0)
        {
            ans+=3;
            b-=2;
            a-=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}