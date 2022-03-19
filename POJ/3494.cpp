#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;
bool mat[2005][2005];
int h[2005][2005];
int cal(int k,int m)
{
	int ans=0;
	stack<int>s;
	mat[k][m]=0;
	for(int i=0;i<=m;++i)
	{
		while(!s.empty()&&h[k][s.top()]>h[k][i])
		{
			int tmp=s.top();
			s.pop();
			ans=max(ans,(s.empty()?i:i-s.top()-1)*h[k][tmp]);
		}
		s.push(i);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&mat[i][j]);
		for(int j=0;j<m;++j)
		{
			h[0][j]=mat[0][j]?1:0;
			for(int i=1;i<n;++i)
			{
				if(mat[i-1][j]&&mat[i][j])
					h[i][j]=h[i-1][j]+1;
				else if(!mat[i-1][j]&&mat[i][j])
					h[i][j]=1;
				else if(!mat[i][j])
					h[i][j]=0;	
			}	
		}
		/*cout<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cout<<h[i][j]<<" ";	
			}
			cout<<endl;
		}*/
		int ans=0;
		for(int i=0;i<n;++i)
			ans=max(ans,cal(i,m));
		printf("%d\n",ans);	
	}
	return 0;
}