#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int cnt[2]={0,0};
    for(int i=0;i<n;++i)
        ++cnt[str[i]-'0'];   
    if(cnt[0]==cnt[1])
    {
        cout<<2<<endl<<str[0]<<" ";
        for(int i=1;i<n;++i)
            cout<<str[i];
        cout<<endl;
    }
    else
        cout<<1<<endl<<str<<endl;
    return 0;
}
