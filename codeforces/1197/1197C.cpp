#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=1;i<n;++i)
        b[i]=a[i]-a[i-1];
    sort(b+1,b+n);
    long long sum1=0,sum2=0;
    for(int i=n-1;i>n-k;--i)
        sum2+=b[i];
    for(int i=1;i<n;++i)
        sum1+=b[i];
    cout<<sum1-sum2<<endl;
    return 0;
}
