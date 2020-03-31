#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
long long pos[155][2];
double dis_t[155][155];
double dist(int i,int j)
{
    return sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>pos[i][0]>>pos[i][1];
    char ch;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dis_t[i][j]=99999999;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            cin>>ch;
            if(ch=='1')
                dis_t[i][j]=dist(i,j);
            if(i==j)
                dis_t[i][j]=0;
        }
    for(int k=0;k<n;++k)
        for(int j=0;j<n;++j)
            for(int i=0;i<n;++i)
                dis_t[i][j]=min(dis_t[i][j],dis_t[i][k]+dis_t[k][j]);
    double max_dis[155]={0},maxx=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            if(fabs(dis_t[i][j]-99999999)>1e-6)
                max_dis[i]=max(max_dis[i],dis_t[i][j]);
        maxx=max(maxx,max_dis[i]);
    }
    double minn=99999999;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(fabs(dis_t[i][j]-99999999)<1e-6)
                minn=min(minn,dist(i,j)+max_dis[i]+max_dis[j]);
    printf("%.6f\n",max(minn,maxx));
    return 0;
}
