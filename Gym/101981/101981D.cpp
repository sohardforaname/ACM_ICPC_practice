#include <bits/stdc++.h>
using namespace std;
long double eps=1e-7;
struct point
{
    long long x,y,z;
};
point p[105];
long double dis(point &a,point &b)
{
    return sqrt((long double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}
long double solve(int n)
{
    long double ans=1e30,mt,step=10050;
    int s=0;
    point tmp={0ll,0ll,0ll};
    while(step>eps)
    {
        for(int i=1;i<n;++i)
            if(dis(tmp,p[i])>dis(tmp,p[s]))
                s=i;
        mt=dis(tmp,p[s]);
        ans=min(ans,mt);
        tmp.x+=(p[s].x-tmp.x)/mt*step;
        tmp.y+=(p[s].y-tmp.y)/mt*step;
        tmp.z+=(p[s].z-tmp.z)/mt*step;
        step*=0.95;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    printf("%Lf\n",solve(n));
    return 0;
}
