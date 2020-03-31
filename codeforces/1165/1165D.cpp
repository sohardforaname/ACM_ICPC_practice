#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long num[305];
int main()
{
	int ca,n;
	cin>>ca;
	while(ca--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>num[i];
		sort(num,num+n);
		long long ans=0;
		if(n==1)
			ans=num[0]*num[0];
		else
			ans=num[0]*num[n-1];
		bool flag=0;	
		for(int i=0;i<n/2+1;++i)
			if(num[i]*num[n-1-i]!=ans)
				flag=1;
		if(flag)
		{
			cout<<-1<<endl;
			continue;	 
		} 			
		int x=0,y=n-1;
		for(int i=2;i<sqrt(ans)+1;++i)
		{
			if(ans%i==0)
			{
				//cout<<num[x]<<" "<<num[y]<<endl;
				if(num[x]!=i||num[y]!=ans/i)
				{
					flag=1;
					break;
				}
				else if(num[x]==i&&num[y]==ans/i)
					++x,--y;
			}
		}
		if(flag)
			cout<<-1<<endl;
		else	
			cout<<ans<<endl;			
	}
	return 0;
} 