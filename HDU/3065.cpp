#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int cnt=0;
int strid=0;
struct node
{
    string str;
    int num;
}s[1005];
struct AC
{
    int trie[50005][130];
    int fail[50005];
    int cntword[50005];
    void insert(string &str)
    {
        int root=0;
        for(int i=0;i<str.size();++i)
        {
            int next=str[i];
            if(!trie[root][next])
                trie[root][next]=++cnt;
            root=trie[root][next];
        }
        cntword[root]=++strid;
    }
    void buildfail()
    {
        queue<int>que;
        int now=0;
        for(int i=0;i<130;++i)
        {
            if(trie[now][i])
            {
                fail[trie[now][i]]=0;
                que.push(trie[now][i]);
            }
        }
        while(!que.empty())
        {
            now=que.front();
            que.pop();
            for(int i=0;i<130;++i)
            {
                if(trie[now][i])
                {
                    fail[trie[now][i]]=trie[fail[now]][i];
                    que.push(trie[now][i]);
                }
                else 
                    trie[now][i]=trie[fail[now]][i];
            }
        }
    }
    void query(string &str)
    {
        int next=0;
        for(int i=0;i<str.size();++i)
        {
            next=trie[next][str[i]];
            for(int j=next;j;j=fail[j])
                ++s[cntword[j]].num;
        }
    }
};
AC ac;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string tmp;
    while(cin>>n)
    {
        memset(ac.trie,0,sizeof(ac.trie));
        memset(ac.fail,0,sizeof(ac.fail));
        memset(ac.cntword,0,sizeof(ac.cntword));
        cnt=0,strid=0;
        for(int i=1;i<=n;++i)
        {
            cin>>tmp;
            ac.insert(tmp);
            s[i].str=tmp;
            s[i].num=0;
        }
        ac.buildfail();
        cin>>tmp;
        ac.query(tmp);
        for(int i=1;i<=n;++i)
            if(s[i].num)
                cout<<s[i].str<<": "<<s[i].num<<endl;
    }
    return 0;
}
