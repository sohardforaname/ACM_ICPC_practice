#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        next_permutation(a,a+n);
    for(int i=0;i<n;++i)
    {
        cout<<a[i];
        if(i<n-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
