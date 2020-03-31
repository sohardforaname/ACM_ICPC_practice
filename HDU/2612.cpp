#include <iostream> 
#include <queue>
#include <cstring>
using namespace std;
int dep1[40005],dep2[40005];
char ch[205][205];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,l,a,b;
int res[40005];
bool check(int x,int y,char s)
{
	if(x>=n||x<0||y>=m||y<0)
		return false;
	if(ch[x][y]=='#'||ch[x][y]==s)
		return false;	
	return true;	
}
void print(int *dep)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cout<<dep[i*m+j]<<" ";
		cout<<endl;	
	}
}
void bfs(int s,int *dep,char k)
{
	queue<int>que;
	dep[s]=1;
	que.push(s);
	while(!que.empty())
	{
		int t=que.front();
		que.pop();
		//cout<<"t="<<t<<endl;
		int x=t/m,y=t%m;
		//cout<<x<<" "<<y<<endl;
		for(int i=0;i<4;++i)
		{
			if(check(x+dir[i][0],y+dir[i][1],k))
				if(dep[(x+dir[i][0])*m+y+dir[i][1]]==0)
				{
					//cout<<(x+dir[i][0])*m<<" "<<y+dir[i][1]<<endl;
					dep[(x+dir[i][0])*m+y+dir[i][1]]=dep[t]+1;
					que.push((x+dir[i][0])*m+y+dir[i][1]);
					//print(dep);
					//cout<<endl;
				}
		}	
	}
	//cout<<endl; 
}
void solve()
{
	int ans=0x3f3f3f3f;
	for(int i=0;i<l;++i)
		if(dep1[res[i]]&&dep2[res[i]]&&ans>dep1[res[i]]+dep2[res[i]])
			ans=dep1[res[i]]+dep2[res[i]];
	cout<<(ans-2)*11<<endl;		
}
int main()
{
	while(cin>>n>>m)
	{
		memset(ch,0,sizeof(ch));
		memset(dep1,0,sizeof(dep1));
		memset(dep2,0,sizeof(dep2)); 
		l=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				cin>>ch[i][j];	
				if(ch[i][j]=='Y')
					a=i*m+j;
				else if(ch[i][j]=='M')
					b=i*m+j;
				else if(ch[i][j]=='@')
					res[l++]=i*m+j;	
			}
		/*for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				cout<<ch[i][j]<<" ";
			cout<<endl;	
		}
		cout<<l<<" "<<a<<" "<<b<<" "<<endl;
		for(int i=0;i<l;++i)
			cout<<res[i]<<endl;*/
		bfs(a,dep1,'M');
		bfs(b,dep2,'Y');
		solve();
	}
	return 0;
}
