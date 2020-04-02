#include <bits/stdc++.h>
int a[100005];
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        sort(a,a+n);
        int maxn=min(a[n-1],a[n-2]);
        cout<<min(maxn-1,n-2)<<endl;
    }
    return 0;
}
