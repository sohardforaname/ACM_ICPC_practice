#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int main()
{
    int T,n,a,k,odd,even;
    cin>>T;
    while(T--)
    {
        ans.clear();
        odd=even=0;
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
            cin>>a;
            if(a%2)
                ++odd,ans.push_back(i);
            else
                ++even;
        }
        if(odd<k)
            cout<<"NO"<<endl;
        else if((k-odd)%2)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k-1;++i)
                cout<<ans[i]<<" ";
            cout<<n<<endl;
        }
    }
    return 0;
}
