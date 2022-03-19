#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[205][205];
int t[205];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a,b,c,q;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>t[i];
	memset(map,0x3f3f3f3f,sizeof(map));
	for(int i=0;i<n;++i)
		map[i][i]=0;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>c;
		map[a][b]=c;
		map[b][a]=c;
	}
	cin>>q;
	int k=0;
	for(int i=0;i<q;++i)
	{
		cin>>a>>b>>c;
		if(t[a]>c||t[b]>c)
		{
			cout<<-1<<endl;
			continue;
		}
		while(t[k]<=c&&k<n)
		{
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			++k;
		}
		if(map[a][b]==0x3f3f3f3f)
			cout<<-1<<endl;
		else
			cout<<map[a][b]<<endl;
	}
	return 0;
}
