#include <bits/stdc++.h>
using namespace std;
long long num[200005];
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;++i)
        cin>>num[i],sum+=num[i];
    if(sum%2)
        cout<<"NO"<<endl;
    else
    {
        if((*max_element(num,num+n))<=sum/2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
