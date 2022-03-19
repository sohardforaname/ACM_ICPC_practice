#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn int(1e6+9)
int trie[maxn][26],fail[maxn],cntword[maxn],cnt=0,strid=0;
string in[155];
struct node
{
	int num,pos;
}ans[maxn];
struct ac
{
	void insert(string &str)
	{
		int next,root=0;
		for(int i=0;i<str.size();++i)
		{
			next=str[i]-'a';
			if(!trie[root][next])
				trie[root][next]=++cnt;
			root=trie[root][next];
		}
		cntword[root]=++strid;
	}
	void buildfail()
	{
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
				++ans[cntword[j]].num;
		}
	}
};
bool cmp(const node &a,const node &b)
{
	if(a.num==b.num)
		return a.pos<b.pos;
	return a.num>b.num;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ac a;
	string tmp; 
	while(cin>>n&&n)
	{
		memset(trie,0,sizeof(trie));
		memset(fail,0,sizeof(fail));
		memset(cntword,0,sizeof(cntword));
		cnt=strid=0;
		for(int i=1;i<=n;++i)
		{
			ans[i].pos=i;
			ans[i].num=0;
		}
		for(int i=0;i<n;++i)
		{
			cin>>in[i];
			a.insert(in[i]);		
		}
		a.buildfail();
		cin>>tmp;
		a.query(tmp);
		sort(ans+1,ans+n+1,cmp);
		cout<<ans[1].num<<endl;
		for(int i=1;ans[i].num==ans[1].num;++i)
			cout<<in[ans[i].pos-1]<<endl;
	}
	cout<<endl;
	return 0; 
}