#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
struct SuffixArray
{
	int n, m;
	int tax[N], rank[N], tp[N], sa[N];
	int height[N];
	//sa[i]=j����ʾ��i���ĺ�׺�Ǵ�j��ʼ�ģ�ע�������±꣩
	//rank[i]=j����i��ʼ�ĺ�׺�ǵ�j���ģ���sa���棬��������ֵ����
	//tp[i]���ڶ��ؼ���Ϊ i �ĺ�׺�Ǵ�j��ʼ�� ���൱���ǵڶ��ؼ��ֵ�sa���飬������±꣩
	//tax[i]=j����ʾ��һ�ؼ���Ϊi������j������������ʱ�õ�Ͱ����ֵ��
	char ch[N];
	void sort() //��������
	{
		for (int i = 0; i <= m; ++i) //Ͱ����
			tax[i] = 0;
		for (int i = 1; i <= n; ++i) //ÿ�����ŵ���Ӧ��Ͱ���õ����Ǵ�i��ʼ�ĺ�׺�ĵ�һ�ؼ����ǵ�rank[i]����
									 //���������εĺ�׺��tax[rank[i]]��
			++tax[rank[i]];
		for (int i = 1; i <= m; ++i) //����ǰ���Ͱ��������ɣ��õ�����
			tax[i] += tax[i - 1];
		for (int i = n; i >= 1; --i) //��iΪ�ڶ��ؼ��ֵĺ�׺�Ǻ�׺tp[i]��tax[rank[tp[i]]]=j����iΪ�ڶ��ؼ�
									 //�ֵĺ�׺�ĵ�һ�ؼ���Ϊ��һ�ؼ��ֵĺ�׺��j��,���ڻ����������ǰ׺���Ѿ�֪�������������ԾͰ���
									 //��������Ӧ���Ǹ���׺tp[i]��¼������ͬʱ������1��ÿһ�ζ���ȡ��iΪ�ڶ��ؼ��ֵĺ�׺�ĵ�һ�ؼ���
									 //Ϊ��һ�ؼ��ֵĺ�׺�����һ���������Ӿ��൱���ǵڶ��ؼ�����ͬ�����յ�һ�ؼ��������ˣ�����ڶ���
									 //���ֲ���ͬ��Ҳ�ǵ�һ�ؼ��ִ�ģ�һ��Խ���󣬴�ʱ��֤�˰��յ�һ�ڶ��ؼ��ֽ�������
			sa[tax[rank[tp[i]]]--] = tp[i];
	}
	bool cmp(int a, int b, int k)
	{
		//�������tp����һ��rank��
		//ǰ�����˼�Ǵ�sa[i]��ʼ�ʹ�sa[i-1]��ʼ�ĺ�׺�ǵ������Ƿ�һ����
		//����ͬ����j֮����ζ�űȽϵ������ǵڶ��ؼ��֡���֤����Խ��
		return tp[a] == tp[b] && tp[a + k] == tp[b + k];
	}
	void get_sa()
	{
		n = strlen(ch + 1);
		for (int i = 1; i <= n; ++i)
			m = max(m, rank[i] = ch[i] - '0'), tp[i] = i; //��һ�ֵ�һ�ؼ���ֱ�Ӱ�ASCII�룬�ڶ��ؼ��ְ����
		sort();											  //��һ�ֻ�������
		for (int p = 0, j = 1; p < n; j <<= 1, m = p)
		{
			p = 0; //���
			for (int i = 1; i <= j; ++i)
				tp[++p] = n - j + i; //�������Щ��׺iС�ڵ���j�ģ�ֻ�����Լ��ˣ�������������棬�ڶ��ؼ��ְ����ȼ�С������
			for (int i = 1; i <= n; ++i)
				if (sa[i] > j)
					tp[++p] = sa[i] - j; //sa[i]>j֤����׺i�ĳ��ȴ���j��tp[sa[i]-j]���Ǻ�׺sa[i]-j�ĵڶ��ؼ��֣���ʱ��������
			sort();						 //�ڶ��ּ��Ժ�Ļ�������
			swap(rank, tp);				 //tpû�����ˣ����ǽ�rank����Ϣ���Ƹ�tp��ͬʱ��rank�ճ���
			rank[sa[1]] = p = 1;		 //�ճ�����rank��¼�µ�sa�µĶ�Ӧ��ϵ��������һ������
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
				continue; //��һ����heightΪ0
			if (k)
				--k; //h[i]>=h[-1]-1
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
