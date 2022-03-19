#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char ch[20][20];
int cnt=1;
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
	//cout<<x<<" "<<y<<" "<<ch[x][y]<<endl;
	if(x>m-1||x<0||y>n-1||y<0)
		return false;
	if(ch[x][y]=='#'||ch[x][y]=='@')
		return false;
	//cout<<"t"<<endl;	
	return true;
}
int main()
{
	int ax,ay;
	while(cin>>n>>m&&n+m)
	{
		cnt=1;
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
			{
				cin>>ch[i][j];
				if(ch[i][j]=='@')
					ax=i,ay=j;
			}
		queue<pair<int,int> >que;
		que.push(make_pair(ax,ay));
		while(!que.empty())
		{
			pair<int,int>u=que.front();
			que.pop();
			int x=u.first,y=u.second;
			for(int i=0;i<4;++i)
				if(check(x+dir[i][0],y+dir[i][1]))
				{
					//cout<<x+dir[i][0]<<" "<<y+dir[i][1]<<endl;
					ch[x+dir[i][0]][y+dir[i][1]]='@';
					++cnt;
					que.push(make_pair(x+dir[i][0],y+dir[i][1]));
				}
		}
		cout<<cnt<<endl;
	}
}