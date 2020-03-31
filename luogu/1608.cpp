#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int dis[2005],vis[2005],cnt[2005];
struct edge
{
	int to,w;
	edge(int a,int b)
	{
		to=a,w=b;
	}
	bool operator<(const edge &a)const
	{
		return this->w>a.w;
	}
};
vector<edge>node[2005];
void dijkstra(int n)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dis[1]=0,cnt[1]=1;
	priority_queue<edge>que;
	que.push(edge(1,dis[1]));
	while(!que.empty())
	{
		edge u=que.top();
		que.pop();
		if(vis[u.to])
			continue;
		vis[u.to]=1;
		for(int i=0;i<node[u.to].size();++i)
		{
			edge v=node[u.to][i];
			if(!vis[v.to])
			{
				if(dis[v.to]==dis[u.to]+v.w)
					cnt[v.to]+=cnt[u.to];
				else if(dis[v.to]>dis[u.to]+v.w)
				{
					dis[v.to]=dis[u.to]+v.w;
					cnt[v.to]=cnt[u.to];
					que.push(edge(v.to,dis[v.to]));
				}
			}
		}
	}
	/*for(int i=1;i<=n;++i)
		cout<<dis[i]<<" ";
	cout<<endl;*/
	if(dis[n]>=0x3f3f3f3f)
		cout<<"No answer"<<endl;
	else
		cout<<dis[n]<<" "<<cnt[n]<<endl;
}
int graph[2005][2005]; 
int main()
{
	memset(graph,0x3f3f3f3f,sizeof(graph));
	int n,m,a,b,c;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>c;
		if(graph[a][b]>c)
			graph[a][b]=c;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(graph[i][j]<0x3f3f3f3f)
				node[i].push_back(edge(j,graph[i][j]));
	dijkstra(n);
	return 0;
}