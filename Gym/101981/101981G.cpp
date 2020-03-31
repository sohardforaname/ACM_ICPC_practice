#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long inv(long long a,long long b,long long p)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long ans=n%mod;
        ans=ans*(n+1)%mod;
        ans=ans*(n+2)%mod;
        ans=ans*(n+3)%mod;
        printf("%lld\n",ans*inv(24,mod-2,mod)%mod);
    }
    return 0;
}
