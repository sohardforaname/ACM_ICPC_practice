#include <iostream>
#include <cstring>
using namespace std;
int pre[10000005];
bool ispre[10000005];
bool pal(int i)
{
	int y=i,x=0,tmp;
	while(y)
	{
		tmp=y%10;
		x=x*10+tmp;
		y/=10;	
	}
	//cout<<x<<endl;
	if(x==i)
		return 1;
	return 0;	
}
int main()
{
	int p=0;
	memset(ispre,1,sizeof(ispre));
	ispre[0]=ispre[1]=0;
	for(int i=2;i<10000005;++i)
	{
		if(ispre[i])
			pre[p++]=i;
		for(int j=0;j<p&&i*pre[j]<10000005;++j)
		{
			ispre[i*pre[j]]=0;
			if(i%pre[j]==0)//i除尽了pre[j]则i已经是合数了
				break;
		}
	}
	int n,m;
	cin>>n>>m;
	for(int i=n;i<=m&&i<=10000000;++i)
	{
		if(pal(i)&&ispre[i])
			cout<<i<<endl;
	}
	return 0;
}