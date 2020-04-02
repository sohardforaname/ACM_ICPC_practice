#include <bits/stdc++.h>
using namespace std;
vector<int>E[100005];
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    bool f=0;
    for(int i=1;i<=n;++i)
        if(E[i].size()==2)
            f=1;
    if(!f)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
