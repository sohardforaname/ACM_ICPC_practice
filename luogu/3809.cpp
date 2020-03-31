#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct SuffixArray
{
	int n, m;
	int tax[MAXN], rank[MAXN], tp[MAXN], sa[MAXN];
	int height[MAXN];
	//sa[i]=j，表示第i名的后缀是从j开始的（注意存的是下标）
	//rank[i]=j，从i开始的后缀是第j名的（和sa互逆，是排名（值））
	//tp[i]，第二关键字为 i 的后缀是从j开始的 （相当于是第二关键字的sa数组，存的是下标）
	//tax[i]=j，表示第一关键字为i的数有j个（基数排序时用的桶，是值）
	char ch[MAXN];
	void sort()//基数排序
	{
		for (int i = 0; i <= m; ++i)//桶清零
			tax[i] = 0;
		for (int i = 1; i <= n; ++i)//每个数放到对应的桶，得到的是从i开始的后缀的第一关键字是第rank[i]名，
		//这样的名次的后缀有tax[rank[i]]个
			++tax[rank[i]];
		for (int i = 1; i <= m; ++i)//加上前面的桶，排序完成，得到排名
			tax[i] += tax[i - 1];
		for (int i = n; i >= 1; --i)//以i为第二关键字的后缀是后缀tp[i]，tax[rank[tp[i]]]=j是以i为第二关键
		//字的后缀的第一关键字为第一关键字的后缀有j个,由于基数排序后求前缀和已经知道其排名，所以就把这
		//个排名对应的那个后缀tp[i]记录下来，同时排名减1。每一次都是取以i为第二关键字的后缀的第一关键字
		//为第一关键字的后缀的最后一名，这样子就相当于是第二关键字相同，按照第一关键字排序了，如果第二关
		//键字不相同，也是第一关键字大的，一定越靠后，此时保证了按照第一第二关键字进行排序。
			sa[tax[rank[tp[i]]]--] = tp[i];
	}
	bool cmp(int a, int b, int k)
	{
		//现在这个tp是上一次rank，
		//前项的意思是从sa[i]开始和从sa[i-1]开始的后缀是的名次是否一样，
		//后项同理，加j之后意味着比较的名次是第二关键字。保证不会越界
		return tp[a] == tp[b] && tp[a + k] == tp[b + k];
	}
	void get_sa()
	{
		n = strlen(ch + 1);
		for (int i = 1; i <= n; ++i)
			m = max(m, rank[i] = ch[i] - '0'), tp[i] = i;//第一轮第一关键字直接按ASCII码，第二关键字按序号
		sort();//第一轮基数排序
		for (int p = 0, j = 1; p < n; j <<= 1, m = p)
		{
			p = 0;//清空
			for (int i = 1; i <= j; ++i)
				tp[++p] = n - j + i;//后面的这些后缀i小于等于j的，只有它自己了，所以排在最后面，第二关键字按长度减小而增大
			for (int i = 1; i <= n; ++i)
				if (sa[i] > j)
					tp[++p] = sa[i] - j;//sa[i]>j证明后缀i的长度大于j，tp[sa[i]-j]就是后缀sa[i]-j的第二关键字，此时仍是乱序
			sort();//第二轮及以后的基数排序
			swap(rank, tp);//tp没有用了，我们将rank的信息复制给tp。同时把rank空出来
			rank[sa[1]] = p = 1;//空出来的rank记录新的sa下的对应关系，进行下一轮排序
			for (int i = 2; i <= n; ++i)
				rank[sa[i]] = cmp(sa[i], sa[i - 1], j) ? p : ++p;
		}
	}
	void get_height()
	{
		int k = 0;
		for (int i = 1; i <= n; ++i)
			rank[sa[i]] = i;
		for (int i = 1; i <= n; ++i)
		{
			if (rank[i] == 1)
				continue;//第一名的height为0
			if (k)
				--k;//h[i]>=h[-1]-1
			int j = sa[rank[i] - 1];
			while (j + k <= n && i + k <= n && ch[j + k] == ch[i + k])
				++k;
			height[rank[i]] = k;
		}
	}
};
SuffixArray sa;
int main()
{
	//scanf("%d",&sa.n);
	scanf("%s", sa.ch + 1);
	sa.get_sa();
	for (int i = 1; i <= sa.n; ++i)
		printf("%d%c", sa.sa[i], (i == sa.n ? '\n' : ' '));
	return 0;
}
