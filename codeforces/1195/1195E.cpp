#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int num[3005][3005];
int minn[3005][3005];
int ans[3005][3005];
int n,m,a,b,g,x,y,z;
void data_gen()
{
    num[0][0]=g;
    long long tmp=g;
    for(int i=0;i<n;++i)
    {
        int j=i?0:1;
        for(;j<m;++j)
        {
            tmp=(tmp*x+y)%z;
            num[i][j]=tmp;
        }
    }
}
int main()
{
    cin>>n>>m>>a>>b>>g>>x>>y>>z;
    data_gen();
    deque<pair<int,int> >que;
    for(int i=0;i<n;++i)
    {
        while(!que.empty())
            que.pop_front();
        for(int j=0;j<b;++j)
        {
            while(!que.empty()&&que.back().first>num[i][j])
                que.pop_back();
            que.push_back(make_pair(num[i][j],j));
        }
        minn[i][0]=que.front().first;
        for(int j=b;j<m;++j)
        {
            while(!que.empty()&&que.back().first>num[i][j])
                que.pop_back();
            que.push_back(make_pair(num[i][j],j));
            while(!que.empty()&&que.front().second<j-b+1)
                que.pop_front();
            minn[i][j-b+1]=que.front().first;
        }
    }
    for(int i=0;i<m-b+1;++i)
    {
        while(!que.empty())
            que.pop_front();
        for(int j=0;j<a;++j)
        {
            while(!que.empty()&&que.back().first>minn[j][i])
                que.pop_back();
            que.push_back(make_pair(minn[j][i],j));
        }
        ans[0][i]=que.front().first;
        for(int j=a;j<n;++j)
        {
            while(!que.empty()&&que.back().first>minn[j][i])
                que.pop_back();
            que.push_back(make_pair(minn[j][i],j));
            while(!que.empty()&&que.front().second<j-a+1)
                que.pop_front();
            ans[j-a+1][i]=que.front().first;
        }
    }
    long long res=0;
    for(int i=0;i<n-a+1;++i)
        for(int j=0;j<m-b+1;++j)
            res+=ans[i][j];
    cout<<res<<endl;
    return 0;
}
