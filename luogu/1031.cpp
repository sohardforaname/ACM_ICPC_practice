#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
int main()
{
    int n,tot=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i],tot+=num[i];
    int aver=tot/n;
    for(int i=0;i<n;++i)
        num[i]-=aver;
    int ans=0;
    for(int i=1;i<n;++i)
    {
        if(num[i-1]==0)//前一个不需要移动
            continue;
        num[i]=num[i]+num[i-1];
        if(num[i]==0)//刚好凑整
            ++ans,++i;
        else    //没有凑整
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
