#include <bits/stdc++.h>
using namespace std;
int tmp[5],f[10]={0,4,8,15,16,23,42};
int main()
{
    cout<<"? 1 3"<<endl;
    cin>>tmp[1];
    cout<<"? 2 4"<<endl;
    cin>>tmp[2];
    cout<<"? 3 5"<<endl;
    cin>>tmp[3];
    cout<<"? 4 6"<<endl;
    cin>>tmp[4];
    bool flag;
    do
    {
        flag=1;
        for(int i=1;i<=4;++i)
            if(f[i]*f[i+2]!=tmp[i])
                flag=0;
    }while(flag==0&&next_permutation(f+1,f+7));
    cout<<"! ";
    for(int i=1;i<=6;++i)
        cout<<f[i]<<(i==6?'\n':' ');
    return 0;
}