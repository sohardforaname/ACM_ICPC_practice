#include <bits/stdc++.h>
using namespace std;
long long a[300005],b[300005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    long long maxx=0,ans=0;
    for(int i=0;i<m;++i)//枚举减k的位置
    {
        for(int j=0;j<n;++j)
            b[j]=a[j]-(j%m==i?k:0);//对需要减k的地方处理
        maxx=0;
        for(int j=0;j<n;++j)
        {
            maxx=max(maxx+b[j],0ll);//求最大子列和
            if(j%m==i)
                ans=max(ans,maxx);//保证了所有的最大子列和都减了相应个数的k
            cout<<maxx<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
