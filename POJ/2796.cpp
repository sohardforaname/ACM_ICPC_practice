#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int num,l,r;
}h[100005];
long long sum[100005];
long long ans=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&h[i].num),sum[i]=sum[i-1]+h[i].num,h[i].l=h[i].r=i;
	long long ans=0;
	int ml=1,mr=n;
	stack<node>s;
	node tmp;
	//cout<<"ok"<<endl;
	for(int i=1;i<=n;++i)
	{
		node t=h[i];
		while(!s.empty()&&s.top().num>h[i].num)
		{
			tmp=s.top();
			s.pop();
			if(!s.empty())
			{
				if(tmp.l<s.top().l)
					s.top().l=tmp.l;
				if(tmp.r>s.top().r)
					s.top().r=tmp.r;
			}
			if(tmp.l<t.l)
				t.l=tmp.l;
			if(tmp.r>t.r)
				t.r=tmp.r;
			//cout<<"ok"<<endl;
			if(ans<tmp.num*(sum[tmp.r]-sum[tmp.l-1]))
				ans=tmp.num*(sum[tmp.r]-sum[tmp.l-1]),mr=tmp.r,ml=tmp.l;
		}
		s.push(t);
		//cout<<"ok"<<endl;
	}
	while(!s.empty())
	{
		tmp=s.top();
		s.pop();
		if(!s.empty())
		{
			if(tmp.l<s.top().l)
				s.top().l=tmp.l;
			if(tmp.r>s.top().r)
				s.top().r=tmp.r;
		}
		if(ans<tmp.num*(sum[tmp.r]-sum[tmp.l-1]))
			ans=tmp.num*(sum[tmp.r]-sum[tmp.l-1]),mr=tmp.r,ml=tmp.l;
	}
	printf("%lld\n%d %d\n",ans,ml,mr);
	return 0;
}