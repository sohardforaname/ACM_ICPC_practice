#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dis[105],vis[105];
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
vector<edge>node[105];
int prim()
{
	int ans=0;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	priority_queue<edge>que;
	que.push(edge(1,dis[1]));
	while(!que.empty())
	{
		edge u=que.top();
		que.pop();
		if(vis[u.to])
			continue;
		vis[u.to]=1;
		ans+=u.w;
		for(int i=0;i<node[u.to].size();++i)
		{
			edge v=node[u.to][i];
			if(dis[v.to]>v.w)
			{
				dis[v.to]=v.w;
				que.push(edge(v.to,dis[v.to]));
			}
		}
	}
	return ans;
}
int main()
{
	int n,a;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cin>>a;
			if(i!=j)
				node[i].push_back(edge(j,a));
		}
	}
	cout<<prim()<<endl;
	return 0;
}