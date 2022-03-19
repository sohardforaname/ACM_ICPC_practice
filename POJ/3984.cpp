#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool graph[5][5];
int depth[25];
int pre[25];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
	if(x>4||x<0||y>4||y<0)
		return false;
	if(graph[x][y])
		return false;	
	return true;	
}
int main()
{
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			cin>>graph[i][j];
	queue<int>que;
	depth[0]=1;
	que.push(0);
	while(!que.empty())
	{
		int pos=que.front();
		int x=pos%5,y=pos/5;
		que.pop();
		for(int i=0;i<4;++i)
			if(check(x+dir[i][0],y+dir[i][1]))
			{
				if(depth[(x+dir[i][0])+(y+dir[i][1])*5]==0)
				{
					depth[(x+dir[i][0])+(y+dir[i][1])*5]=depth[pos]+1;
					pre[(x+dir[i][0])+(y+dir[i][1])*5]=pos;
					que.push((x+dir[i][0])+(y+dir[i][1])*5);
				}
			}
	}
	stack<int>sta;
	int end=24;
	while(end)
	{
		sta.push(end);
		end=pre[end];
	}
	sta.push(0);
	while(!sta.empty())
	{
		int pos=sta.top();
		cout<<"("<<pos%5<<", "<<pos/5<<")"<<endl;
		sta.pop();
	}
	return 0;
} 