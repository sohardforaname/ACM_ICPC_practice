#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
long long h[1000005];
int v[1000005];
long rec[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld %d",&h[i],&v[i]);
	deque<int>que;
	for(int i=0;i<n;++i)
	{
		while(!que.empty()&&h[que.back()]<h[i])
		{
			rec[i]+=v[que.back()];
			que.pop_back();
		}
		que.push_back(i);
	}
	while(!que.empty())
		que.pop_front();
	for(int i=n-1;i>=0;--i)
	{
		while(!que.empty()&&h[que.back()]<h[i])
		{
			rec[i]+=v[que.back()];
			que.pop_back();
		}
		que.push_back(i);
	}
	//for(int i=0;i<n;++i)
		//printf("%d ",rec[i]);
	printf("%ld\n",*max_element(rec,rec+n));
	return 0;
}