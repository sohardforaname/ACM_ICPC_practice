#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int num[100005];
bool check(int n)
{
    if(n>=2&&num[0]==0&&num[1]==0)
        return 1;
    for(int i=2;i<n;++i)//连续三堆相同
        if(num[i]==num[i-1]&&num[i-1]==num[i-2])
            return 1;
    for(int i=2;i<n;++i)
        if(num[i]==num[i-1]&&num[i]==num[i-2]+1)//第一个必须取一个，第二个再取一个，相等，输
            return 1;
    int cnt=0;
    for(int i=1;i<n;++i)//相同对
        if(num[i]==num[i-1])
            ++cnt;
    return cnt>1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i];
    sort(num,num+n);
    if(check(n))
    {
        cout<<"cslnb"<<endl;
        return 0;
    }
    long long sum=0;
    for(int i=0;i<n;++i)
        sum+=num[i];
    if((sum-n*(n-1)/2)%2)
        cout<<"sjfnb"<<endl;
    else
        cout<<"cslnb"<<endl;
    return 0;
}
