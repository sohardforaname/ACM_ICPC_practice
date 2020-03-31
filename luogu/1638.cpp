#include <cstdio>
#include <algorithm>
using namespace std;
int num[1000005];
int k[2005]; 
//two pointer 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&num[i]);
	int l=0,r=-1,x=0;
	int len=n,al=0,ar=n-1;
	while(l<n&&r<n)//判断是否越界 
	{
		while(x<m&&r<n)//名画数量没有到m 
		{
			++k[num[++r]];//增加画的序号 
			if(k[num[r]]==1)//刚好从0到1，避免多次累加 
				++x;
		}
		if(x<m)//仍然不行，只能前一段了 
			break;
		if(len>r-l+1&&x==m)//更新 
			len=r-l+1,al=l,ar=r;
		//移动l指针 
		--k[num[l]];
		if(k[num[l]]==0)
			--x;
		++l;		
	}
	printf("%d %d\n",al+1,ar+1);
	return 0;
}