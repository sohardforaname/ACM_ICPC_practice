#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int prime[1000005],tot=0;
bool isprime[1000005];
void findprime(int n)
{
    for(int i=0;i<n;++i)
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
    findprime(1000000);
    int n;
    while(cin>>n&&n)
    {
        for(int i=1;i<tot;++i)
            if(isprime[n-prime[i]])
            {
                cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<endl;
                break;
            }
    }
    return 0;
}
