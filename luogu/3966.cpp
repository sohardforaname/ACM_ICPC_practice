#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define maxn 1000005
#define gro 205
int strtag[gro],trie[maxn][30],fail[maxn],cntword[maxn],same[maxn];
int cnt=0,strid=0,sid=0;
int apr[maxn];
bool vis[maxn];
struct AC
{
    bool insert(char* str)
    {
        bool flag=0;
        ++sid;
        int root=0,next;
        int l=strlen(str);
        for(int i=0;i<l;++i)
        {
            next=str[i]-'a';
            if(!trie[root][next])
                trie[root][next]=++cnt;
            root=trie[root][next];
            ++apr[root];
        }
        if(!cntword[root])
            cntword[root]=sid;
        else    
            same[sid]=cntword[root],flag=1;
        return flag;
    }
    void getfail()
    {
        int root=0;
        queue<int>que;
        for(int i=0;i<30;++i)
        {
            if(trie[root][i])
            {
                fail[trie[root][i]]=0;
                que.push(trie[root][i]);
            }
        }
        while(!que.empty())
        {
            root=que.front();
            que.pop();
            for(int i=0;i<30;++i)
            {
                if(trie[root][i])
                {
                    fail[trie[root][i]]=trie[fail[root]][i];
                    que.push(trie[root][i]);
                }
                else
                    trie[root][i]=trie[fail[root]][i];
            }
        }
    }
    void query(char* str)
    {
        int root=0,next;
        int l=strlen(str);
        for(int i=0;i<l;++i)
        {
            next=str[i]-'a';
            root=trie[root][next];
            for(int j=root;j;j=fail[j])
                if(!vis[root]&&cntword[j])
                    strtag[cntword[j]]+=apr[root];
            vis[root]=1;
        }
    }
};
AC ac;
char tmp[1000005];
char str[1000225];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",tmp+1);
        if(!ac.insert(tmp+1))
        {
            tmp[0]=char('z'+1);
            strcat(str,tmp);
        }
    }
    ac.getfail();
    //cout<<str<<endl;
    ac.query(str);
    for(int i=1;i<=n;++i)
    {
        if(same[i]==0)
            printf("%d\n",strtag[i]);
        else
            printf("%d\n",strtag[same[i]]);
    }
    return 0;
}
