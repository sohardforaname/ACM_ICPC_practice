#include <iostream>
using namespace std;
int cnt=0,n;
int a[10][60000];
int tmp[10];
void dfs(int dep,int sum)
{
	if(dep==10)
	{
		if(sum==n)
		{
			++cnt;
			for(int i=0;i<10;++i)
				a[i][cnt]=tmp[i];
		}
		return;	
	}
	for(int i=1;i<=3;++i)
	{
		tmp[dep]=i;
		dfs(dep+1,sum+i);
	}
}
int main()
{
	cin>>n;
	if(n>30)
		return cout<<0<<endl,0;
	dfs(0,0);
	cout<<cnt<<endl; 
	for(int i=1;i<=cnt;++i)
		for(int j=0;j<10;++j)
		{
			cout<<a[j][i];
			if(j<9)
				cout<<" ";
			else
				cout<<endl;		
		}
	return 0;
}