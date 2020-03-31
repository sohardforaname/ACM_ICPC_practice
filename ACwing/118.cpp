#include <bits/stdc++.h>
using namespace std;
char ch[740][740];
int dir[5][2]={{-1,-1},{-1,1},{1,-1},{1,1},{0,0}};
int poww[10]={1,3,9,27,81,243,729,2187};
void dfs(int x,int y,int div)
{
    ch[x][y]='X';
    if(div==1)
        return;
    for(int i=0;i<5;++i)
        dfs(x+poww[div-2]*dir[i][0],y+poww[div-2]*dir[i][1],div-1);
    return;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&~n)
    {
        int pos=pow(3,(n-1));
        pos=pos/2+1;
        dfs(pos,pos,n);
        for(int i=1;i<pos*2;++i)
        {
            int maxpos=0;
            for(int j=1;j<pos*2;++j)
                if(ch[i][j]=='X')
                    maxpos=j;
            for(int j=1;j<=maxpos;++j)
                printf("%c",ch[i][j]?'X':' ');
            printf("\n");
        }
        printf("-\n");       
    }
    return 0;
}