#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int num[2000005];
struct node
{
	int num,pos;
	node()
	{
		num=0,pos=0;
	}
	node(int a,int b)
	{
		num=a,pos=b;
	}
};
node que[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&num[i]);
	//queue
	int head=1,tail=0;
	int i;
	for(i=0;i<m;++i)
	{
		while(head<=tail&&que[tail].num<=num[i])
			--tail;
		que[++tail]=node(num[i],i);
	}
	printf("%d\n",que[head].num);
	for(;i<n;++i)
	{
		while(head<=tail&&que[tail].num<=num[i])
			--tail;
		que[++tail]=node(num[i],i);
		while(que[head].pos<i-m+1)
			++head;
		printf("%d\n",que[head].num);	
	} 
	return 0;
}