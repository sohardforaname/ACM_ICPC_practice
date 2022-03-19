#include <iostream>
#include <cstring>
using namespace std;
#define maxn 20001
bool isprime[20005];
int prime[20005];
int p=0;
void init()
{
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=0;
	for(int i=2;i<maxn;++i)
	{
		if(isprime[i])
			prime[p++]=i;
		for(int j=0;j<p&&i*prime[j]<maxn;++j)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}	
	}
}
int main()
{
	init();
	int n;
	cin>>n;
	for(int i=0;i<p&&prime[i]<n;++i)
		for(int j=i;j<p&&prime[j]<n;++j)
			for(int k=j;k<p&&prime[k];++k)
				if(prime[i]+prime[j]+prime[k]==n)
				{
					cout<<prime[i]<<" "<<prime[j]<<" "<<prime[k]<<endl;
					return 0;		
				}
}