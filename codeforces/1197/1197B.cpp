#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int maxn=a[0],maxpos=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]>maxn)
        {
            maxn=a[i];
            maxpos=i;
        }
    }
    bool flag=0;
    for(int i=maxpos;i>0;--i)
        if(a[i-1]>a[i])
            flag=1;
    for(int i=maxpos;i<n-1;++i)
        if(a[i+1]>a[i])
            flag=1;
    if(!flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
