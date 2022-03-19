#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
char map[15][15][2];
int dep[205];
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
bool check(int x,int y,int f)
{
	if(x<0||x>=n||y<0||y>=m)
		return 0;
	else if(map[x][y][f]=='*')
		return 0;
	return 1;			
}
bool convey(int x,int y,int f)
{
	if(f==1)
	{
		if(map[x][y][0]=='*')
			return 0;
		else
			return 1;		
	}
	else if(f==0)
	{
		if(map[x][y][1]=='*')
			return 0;
		else
			return 1;	
	}
}
bool bfs(int s,int T)
{
	memset(dep,0,sizeof(dep));
	queue<int>que;
	que.push(s);
	dep[s]=1;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		int f=u/(n*m),x=(u-f*n*m)/m,y=(u-f*n*m)%m;
		//cout<<x<<" "<<y<<" "<<f<<endl; 
		if(map[x][y][f]=='P')
		{
			if(dep[u]<=T+1)
				return 1;
			else 
			    return 0;	
		}
		//cout<<map[x][y][f]<<endl;
		if(map[x][y][f]=='#')
		{
			int v;
			if(f==1)
				v=x*m+y;
			else if(f==0)
				v=n*m+x*m+y;
			if(!dep[v]&&convey(x,y,f))
			{
				dep[v]=dep[u];
				que.push(v);
			} 
		}
		else
		{
			for(int i=0;i<4;++i)
			{
				int v=n*m*f+(x+dir[i][0])*m+y+dir[i][1];
				//cout<<"v="<<v<<endl;
				if(!dep[v]&&check(x+dir[i][0],y+dir[i][1],f))
				{
					dep[v]=dep[u]+1;
					que.push(v); 
				}
			}
		}
	}
	return 0;
}
int main()
{
	int c,t;
	cin>>c;
	for(int i=0;i<c;++i)
	{
		cin>>n>>m>>t;
		for(int k=0;k<2;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					cin>>map[i][j][k];		
		if(bfs(0,t))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		/*for(int i=0;i<2;++i)
		{
			for(int j=0;j<n;++j)
			{
				for(int k=0;k<m;++k)
					cout<<dep[i*n*m+j*m+k]<<" ";
				cout<<endl;
			}
			cout<<endl;
		}*/
	}
	return 0;
}