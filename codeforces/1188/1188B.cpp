#include <bits/stdc++.h>
//#pragma GCC optimize(3)
using namespace std;
long long inv(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
map<long long,int>m;
int main()
{
    long long n,k,p,a;
    long long sum=0;
    cin>>n>>p>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        long long t=(inv(a,4,p)%p-k*a%p)%p;
        if(t<0)
            t+=p;
        sum+=m[t];
        ++m[t];
    }
    cout<<sum<<endl;
    return 0;
}
