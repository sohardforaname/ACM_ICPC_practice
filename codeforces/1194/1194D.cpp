#include <bits/stdc++.h>
using namespace std;
int f[35],sg[35],hashing[35];
void getsg(int n,int size)
{
    memset(sg,0,sizeof(sg));
    for(int i=0;i<=n;++i)//总个数
    {
        memset(hashing,0,sizeof(hashing));
        for(int j=0;f[j]<=i&&j<size;++j)
            hashing[sg[i-f[j]]]=1;//可以到达的i的下一个状态
        for(int j=0;j<=n;++j)
        {
            if(hashing[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}
void gettable()
{
    for(int i=3;i<=30;++i)
    {
        f[0]=1;
        f[1]=2;
        f[2]=i;
        for(int j=0;j<=30;++j)
        {
            cout<<"k="<<i<<" "<<"n="<<j<<endl;
            getsg(j,3);
            for(int k=0;k<=j;++k)
                cout<<sg[k]<<" ";
            cout<<endl;
        }
    }
}
void solve(int n,int k)
{
    if(n==0)
        cout<<"Bob"<<endl;
    else if(k%3==0)
    {
        n%=(k+1);
        if(n==k)
            cout<<"Alice"<<endl;
        else if(n%3==0)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
    else
    {
        if(n%3==0)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }
}
int main()
{
    //gettable();
    int n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        solve(a,b);
    }
    return 0;
}
