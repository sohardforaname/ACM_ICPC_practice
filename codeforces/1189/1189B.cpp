#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    swap(a[n-1],a[n-2]);
    bool f=0;
    for(int i=1;i<n-1;++i)
        if(a[i-1]+a[i+1]<=a[i])
        {
            f=1;
            break;
        }
    if(a[n-2]+a[0]<=a[n-1])
        f=1;
    if(a[n-1]+a[1]<=a[0])
        f=1;
    if(!f)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)
            cout<<a[i]<<(i==n-1?"\n":" ");
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
