#include <iostream>
#include <deque>
using namespace std; 
#define maxn 1000005
long long num[maxn];
long long maxa[maxn];
long long mina[maxn];
int main()
{
	int n,m;
	cin>>n>>m; 
	for(int i=0;i<n;++i)
		cin>>num[i];
	deque<int>maxq,minq;
	for(int i=0;i<m;++i)
	{
		while(!maxq.empty()&&num[maxq.back()]<=num[i])
			maxq.pop_back();
		maxq.push_back(i);
		while(!minq.empty()&&num[minq.back()]>=num[i])
			minq.pop_back();
		minq.push_back(i);	
	}
	maxa[0]=num[maxq.front()];
	mina[0]=num[minq.front()];
	for(int i=m;i<n;++i)
	{
		while(!maxq.empty()&&num[maxq.back()]<=num[i])
			maxq.pop_back();
		maxq.push_back(i);
		while(maxq.front()<i-m+1)
			maxq.pop_front(); 
		while(!minq.empty()&&num[minq.back()]>=num[i])
			minq.pop_back();
		minq.push_back(i);	
		while(minq.front()<i-m+1)
			minq.pop_front();
		maxa[i-m+1]=num[maxq.front()];
		mina[i-m+1]=num[minq.front()];
	}
	for(int i=0;i<=n-m;++i)
	{
 		cout<<mina[i];
 		if(i<n-m)
 			cout<<" ";
 		else
		 	cout<<endl;	
	}
	for(int i=0;i<=n-m;++i)
	{
 		cout<<maxa[i];
 		if(i<n-m)
 			cout<<" ";
 		else
		 	cout<<endl;	
	}
	return 0;
} 