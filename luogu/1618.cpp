#include <iostream>
#include <algorithm>
using namespace std;
int cnt=0;
void gen(int num,int a,int b,int c)
{
	bool s[10]={0};
	if(num%a)
		return;
	else
	{
		int x=num/a*b,y=num/a*c;
		if(x>=1000||y>=1000)
			return;
		int tmp=y;
		for(int i=0;i<3;++i)
		{
			if(i==1)
				tmp=x;
			else if(i==2)
				tmp=num;	
			while(tmp)
			{
				if(s[tmp%10]||tmp%10==0)
					return;
				s[tmp%10]=1;
				tmp/=10;	
			}
		}
		cout<<num<<" "<<x<<" "<<y<<endl; 
		++cnt;
	}	
	return;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=100;i<350;++i)
		gen(i,a,b,c);
	if(cnt==0)
		cout<<"No!!!"<<endl;
	return 0;	
}