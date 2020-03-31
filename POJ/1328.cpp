#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define equ(a,b) (fabs(a-b)<1e-6) 
using namespace std;
struct node
{
    double l,r;
    node(double a,double b)
    {
        l=a,r=b;
    }
    node(){}
};
node is[1005];
bool cmp(const node &a,const node &b)
{
    if(equ(a.r,b.r))
        return a.l>b.l;
    return a.r<b.r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d,a,b,index=0;
    bool f=0;
    while(cin>>n>>d&&n+d)
    {
        f=0;
        for(int i=0;i<n;++i)
        {
            cin>>a>>b;
            if(b>d)
                f=1;
            is[i].l=a-sqrt(d*d-b*b);
            is[i].r=a+sqrt(d*d-b*b); 
        }
        if(f)
        {
            cout<<"Case "<<++index<<": "<<-1<<endl;
            continue;
        }
        sort(is,is+n,cmp);
        double tmp2 = is[0].r;
        int cnt=1;
        for(int i=1;i<n;++i)
        {
            if(is[i].l-tmp2<=1e-6)//新线段的左端点小于等于旧线段的右端点
                ;
            else if(is[i].l-tmp2>1e-6)//新线段的左端点大于旧线段右端点，即无覆盖
                ++cnt,tmp2=is[i].r;
        }
        cout<<"Case "<<++index<<": "<<cnt<<endl;
    }
    return 0;
}
