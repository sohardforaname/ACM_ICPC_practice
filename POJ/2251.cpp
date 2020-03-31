#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char g[35][35][35];
int depth[35*35*35];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int a,b,c;
int e;
bool check(int x,int y,int z)
{
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x<0||y<0||z<0||x>=a||y>=b||z>=c)
        return 0;
    if(g[x][y][z]=='#')
        return 0;
    return 1;    
}
void bfs(int x,int y,int z)
{
    queue<int>que;
    memset(depth,0,sizeof(depth));
    depth[z*a*b+y*a+x]=1;
    que.push(z*a*b+y*a+x);
    while(!que.empty())
    {
        int u=que.front();
        if(u==e)
            break;
        que.pop();
        int z=u/(a*b),y=u%(a*b)/a,x=u%(a*b)%a;
        for(int i=0;i<6;++i)
        {
            int v=(x+dir[i][0])+(y+dir[i][1])*a+(z+dir[i][2])*a*b;
            //cout<<v<<endl;
            //cout<<g[x+dir[i][0]][y+dir[i][1]][z+dir[i][2]]<<endl;
            if(check(x+dir[i][0],y+dir[i][1],z+dir[i][2]))
            {
                //cout<<v<<endl;
                if(!depth[v])
                {
                    depth[v]=depth[u]+1;
                    que.push(v);
                }
            }
        }
    }
    //for(int i=0;i<a*b*c;++i)
        //cout<<depth[i]<<endl;
    if(depth[e])
        cout<<"Escaped in "<<depth[e]-1<<" minute(s)."<<endl;
    else
        cout<<"Trapped!"<<endl;
}
int main()
{
    int x,y,z;
    while(cin>>c>>b>>a&&a&&b&&c)
    {
        for(int i=0;i<c;++i)
            for(int j=0;j<b;++j)
                for(int k=0;k<a;++k)
                {
                    cin>>g[k][j][i];
                    if(g[k][j][i]=='S')
                        x=k,y=j,z=i;
                    else if(g[k][j][i]=='E')
                        e=i*a*b+j*a+k;
                }
        /*for(int i=0;i<c;++i)
            for(int j=0;j<b;++j)
            {
                for(int k=0;k<a;++k)  
                    cout<<g[k][j][i];
                cout<<endl;    
            }*/
        bfs(x,y,z);
    }
    return 0;
}
