#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
int num[2000005];
int que[2000005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&num[i]);
	int head=1,tail=0;
	printf("%d\n",0);
	for(int i=0;i<n-1;++i)
	{
		while(head<=tail&&num[que[tail]]>=num[i])
			--tail;
		que[++tail]=i;
		while(que[head]<i-m+1)
			++head;	
		//cout<<head<<" "<<tail<<endl;
		printf("%d\n",num[que[head]]);	
	}
	return 0;
}