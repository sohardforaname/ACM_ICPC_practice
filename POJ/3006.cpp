#include <iostream>
using namespace std;
int prime[1000005],tot=0;
bool isprime[1000005];
void findprime(int n)
{
    for(int i=2;i<n;++i)
        isprime[i]=1;
    for(int i=2;i<n;++i)
    {
        if(isprime[i])
            prime[tot++]=i;
        for(int j=0;j<tot&&prime[j]*i<n;++j)
        {
            isprime[prime[j]*i]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
    findprime(1000001);
    int a,d,n;
    while(cin>>a>>d>>n&&a+d+n)
    {
        int cnt=0;
        for(a;cnt<n;a+=d)
            if(isprime[a])
                ++cnt;
        a-=d;
        cout<<a<<endl;        
    }
    return 0;
}
