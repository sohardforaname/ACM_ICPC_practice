#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int x,y,num;
    node(int x,int y,int num)
    {
        this->x=x,this->y=y,this->num=num;
    }
};
bool cmp(node &a,node &b)
{
    return a.num>b.num;
}
vector<node>a;
int main()
{
    int n,m,k,tmp;
    cin>>n>>m>>k;
    k-=1;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            cin>>tmp;
            if(tmp>0)
                a.push_back(node(i,j,tmp));
        }       
    sort(a.begin(),a.end(),cmp);
    int nowx=0,nowy=a[0].y;
    int res=0;
    for(int i=0;i<a.size();++i)
    {
        int r=abs(a[i].x-nowx)+abs(a[i].y-nowy)+a[i].x;
        if(k>r+1)
            k-=(r-a[i].x),res+=a[i].num,nowx=a[i].x,nowy=a[i].y,k-=1;
        else
            break;
    }
    cout<<res<<endl;
    return 0;
}
