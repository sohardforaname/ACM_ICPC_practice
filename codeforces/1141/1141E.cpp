#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int num[200005];
int main()
{
	long long h;
	int n;
	long long minh=0; 
	cin>>h>>n;
	for(int i=0;i<n;++i)
	{
		cin>>num[i];
		if(num[i]<0)
			minh+=num[i];
	}
	//cout<<minh<<endl;
	long long copyh=h;
	for(int i=0;i<n;++i)
	{
		copyh+=num[i];
		if(copyh<=0)
			return cout<<i+1<<endl,0;
	}
	//cout<<copyh<<endl;
	if(copyh>=h)
		return cout<<-1<<endl,0;
	long long left=(h+minh)/(h-copyh);
	//cout<<left<<endl;
	h-=(h-copyh)*left;
	long long t=left*n;
	for(int i=0;;++i)
		for(int j=0;j<n;++j)
		{
			h+=num[j];
			//cout<<h<<endl;
			if(h<=0)
				return cout<<t+j+i*n+1<<endl,0;
		}
}
