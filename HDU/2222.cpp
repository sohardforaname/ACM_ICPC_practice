#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define maxn int(5e5+9)
#define m(a,b) memset (a,b,sizeof(a));
#pragma GCC Optimize(2)
int trie[maxn][26];
int cntword[maxn];
int fail[maxn];
int cnt = 0,ans=0;
struct AC
{
	void insert(char *str)
	{
		int root = 0, next;
		int len=strlen(str);
		for (int i = 0; i < len; ++i)
		{
			next = str[i] - 'a';
			if (!trie[root][next])
				trie[root][next] = ++cnt;
			root = trie[root][next];
		}
		++cntword[root];
	}
	void buildfail()
	{
		queue<int>que;
		for (int i = 0; i < 26; ++i)
			if (trie[0][i])
			{
				que.push(trie[0][i]);
				fail[trie[0][i]] = 0;
			}
		while (!que.empty())
		{
			int now = que.front();
			que.pop();
			for (int i = 0; i < 26; ++i)
			{
				if (trie[now][i])
				{
					fail[trie[now][i]] = trie[fail[now]][i];
					que.push(trie[now][i]);
				}
				else
					trie[now][i] = trie[fail[now]][i];
			}
		}
	}
	void query(char *str)
	{
		int now = 0;
		int len=strlen(str);
		for (int i = 0; i < len; ++i)
		{
			now = trie[now][str[i] - 'a'];
			for (int j = now; j&&cntword[j]!=-1 ; j = fail[j])
			{
				ans+=cntword[j];
				cntword[j]=-1;
			}
		}
	}
};
char mod[55],word[1000005];
int main()
{
	int n,m;
	AC ac;
	scanf("%d",&n);
	while(n--)
	{
		m(trie,0);
		m(fail,0);
		m(cntword,0);
		ans=0;
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			scanf("%s",mod);
			ac.insert(mod);
		}
		ac.buildfail();
		scanf("%s",word);
		ac.query(word);
		printf("%d\n",ans);
	}
	return 0;
}