#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define maxn int(1e6+9)
int trie[maxn][26],fail[maxn],cntword[maxn],tmp[maxn],cnt;
struct AC
{
	void insert(string &str)
	{
		int root=0,next;
		for(int i=0;i<str.size();++i)
		{
			next=str[i]-'a';
			if(!trie[root][next])
				trie[root][next]=++cnt;
			root=trie[root][next];	
		}
		cntword[root]=str.size();
	}
	void buildfail()
	{
		int now=0;
		queue<int>que;
		for(int i=0;i<26;++i)
		{
			if(trie[0][i])
			{
				fail[trie[0][i]]=0;
				que.push(trie[0][i]);	
			}
		}
		while(!que.empty())
		{
			int now=que.front();
			que.pop();
			for(int i=0;i<26;++i)
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
		int now=0;
		for(int i=0;i<str.size();++i)
		{
			now=trie[now][str[i]-'a'];
			for(int j=now;j;j=fail[j])
			{
				tmp[i]=cntword[j];	
			}
		}
	}
};
