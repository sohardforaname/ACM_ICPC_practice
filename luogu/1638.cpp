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
	while(l<n&&r<n)//�ж��Ƿ�Խ�� 
	{
		while(x<m&&r<n)//��������û�е�m 
		{
			++k[num[++r]];//���ӻ������ 
			if(k[num[r]]==1)//�պô�0��1���������ۼ� 
				++x;
		}
		if(x<m)//��Ȼ���У�ֻ��ǰһ���� 
			break;
		if(len>r-l+1&&x==m)//���� 
			len=r-l+1,al=l,ar=r;
		//�ƶ�lָ�� 
		--k[num[l]];
		if(k[num[l]]==0)
			--x;
		++l;		
	}
	printf("%d %d\n",al+1,ar+1);
	return 0;
}