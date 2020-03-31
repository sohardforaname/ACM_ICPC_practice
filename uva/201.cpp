#include <bits/stdc++.h>
using namespace std;
bool hor[12][12],ver[12][12];
bool check(int len,int x,int y,int n)
{
    if(x+len>n||y+len>n)
        return 0;
    for(int i=x;i<x+len;++i)
    {
        if(ver[i][y]==0)
            return 0;
        if(ver[i][y+len]==0)
            return 0;
    }
    for(int i=y;i<y+len;++i)
    {
        if(hor[x][i]==0)
            return 0;
        if(hor[x+len][i]==0)
            return 0;
    }
    return 1;
}
void print(int n)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<n;++j)
        {
            cout<<hor[i][j];
            if(j<n-1)
                cout<<" ";
            else
                cout<<endl;
        }
    for(int i=1;i<n;++i)
        for(int j=1;j<=n;++j)
        {
            cout<<ver[i][j];
            if(j<n)
                cout<<" ";
            else
                cout<<endl;
        }
}
int main()
{
    int n,m,a,b,index=0;
    char ch;
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
    while(cin>>n)
    {
        cin>>m;
        memset(hor,0,sizeof(hor));
        memset(ver,0,sizeof(ver));
        int s[10]={0};
        for(int i=0;i<m;++i)
        {   
            cin>>ch>>a>>b;
            if(ch=='H')
                hor[a][b]=1;
            else if(ch=='V')
                ver[b][a]=1;
        }
        //print(n);
        bool flag=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    if(check(k,i,j,n))
                        ++s[k],flag=1;
        if(index)
            cout<<endl<<"**********************************"<<endl<<endl;
        cout<<"Problem #"<<++index<<endl<<endl;
        if(!flag)
            cout<<"No completed squares can be found."<<endl;
        else 
        {
            for(int i=1;i<=n;++i)
                if(s[i])
                    cout<<s[i]<<" square (s) of size "<<i<<endl;
        }
    }
    return 0;
}
