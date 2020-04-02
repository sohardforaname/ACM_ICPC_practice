#include <bits/stdc++.h>
using namespace std;
int num[100005];
const long long mod=998244353;
long long cal(int x,int n)
{
    long long tmp,ans=0,t=1;
    while(x)
    {
        tmp=x%10;
        x/=10;
        ans+=(((tmp*t)%mod)*n*11%mod);
        t*=100;
    }
    ans%=mod;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i];
    long long ans=0;
    for(int i=0;i<n;++i)
        ans=(ans+cal(num[i],n))%mod;
    cout<<ans<<endl;
    return 0;
}
