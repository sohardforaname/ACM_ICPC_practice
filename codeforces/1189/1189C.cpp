#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long sum[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    int m,l,r;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1])/10<<endl;
    }
    return 0;
}
