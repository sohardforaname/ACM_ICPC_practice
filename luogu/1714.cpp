#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int num[500005];
long long sum[500005];
struct node
{
	long long sum;
	int pos;
	node(long long a,int b)
	{
		sum=a,pos=b;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>num[i],sum[i]=sum[i-1]+num[i];
	long long ans=-0x3f3f3f3f;
	deque<node>maxq;
	maxq.push_back(node(sum[0],0));
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,sum[i]-maxq.front().sum);
		while(!maxq.empty()&&maxq.back().sum>=sum[i])
			maxq.pop_back();	
		maxq.push_back(node(sum[i],i));
		while(maxq.front().pos<i-m+1)
			maxq.pop_front();
	}
	cout<<ans<<endl;
	return 0; 
}