#include <bits/stdc++.h>
using namespace std;
int sum[1000005];
int main()
{
    string s,t;
    cin>>s>>t;
    sum[0]=0;
    for(int i=0;i<s.size();++i)
        sum[i+1]=sum[i]+(s[i]=='1'?1:0);
    int ss=0;
    for(int i=0;i<t.size();++i)
        ss+=t[i]=='1'?1:0;
    int ans=0;
    for(int i=t.size();i<=s.size();++i)
        if((sum[i]-sum[i-t.size()])%2==ss%2)
            ++ans;
    cout<<ans<<endl;
    return 0;
}
