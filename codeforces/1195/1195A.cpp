#include <bits/stdc++.h>
using namespace std;
int num[1005],num2[1005];
int main()
{
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        ++num[a];
    }
    int ans=0;
    for(int i=1;i<=k;++i)
    {
        ans+=num[i]/2;
        num[i]%=num[i];
    }
    int res=ans*2;
    for(ans;ans*2<n;++ans)
        ++res;
    cout<<res<<endl;
    return 0;
}
