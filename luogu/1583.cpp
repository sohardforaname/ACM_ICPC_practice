#include <bits/stdc++.h>
using namespace std;
struct node
{
    int w,id;
    bool operator<(const node &a)const
    {
        if(w==a.w)
            return id<a.id;
        return w>a.w;
    }
};
node a[20005];
int num[15];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=10;++i)
        scanf("%d",&num[i]);    
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i].w);
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        a[i].w+=num[(i-1)%10+1];
        //cout<<a[i].w<<endl;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m;++i)
        printf("%d%c",a[i].id,(i==m?'\n':' '));
    return 0;
}
