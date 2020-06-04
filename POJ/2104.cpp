#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
struct value
{
    int id;
    int x;
};
value v[MAXN];
int hashing[MAXN];
bool cmp(const value &a, const value &b)
{
    return a.x < b.x;
}
int cnt = 0;
struct cheiftree
{
    struct node
    {
        int l, r; //l,r��¼�ڵ��Ŷ��������䳤
        int sum;
        node()
        {
            sum = 0;
        }
    };
    node tr[MAXN * 20];
    int root[MAXN];
    void init()
    {
        cnt = 1;                           //��������
        tr[0].l = tr[0].r = tr[0].sum = 0; //���Һ��ӵ�Ȩֵ��ʼ��Ϊ0
        root[0] = 0;                       //������ʼ��Ϊ0
    }
    void update(int l, int r, int &nrt, int num) //l��m��ʾ���䷶Χ
    {
        tr[cnt++] = tr[nrt]; //�µ�������nrt����ĵ�Ԫ��ʱΪroot[i-1]
        nrt = cnt - 1;       //��cnt-1����root[i]��Ϊ������������
        ++tr[nrt].sum;       //Ȼ����һ��������Ȩֵ�����ĸ���+1��������Ϊroot[i-1]+1
        if (l == r)          //����Ҷ�ڵ�
            return;
        int m = (l + r) / 2; //���������е�
        if (num <= m)
            update(l, m, tr[nrt].l, num); //�ѵ�ǰ���������Ӵ���
        //����updateʹ�����ã������ӽ��ᱻ�ҵ��丸�׽ڵ���
        else
            update(m + 1, r, tr[nrt].r, num);
        //�Һ���ͬ��
    }
    int query(int rl, int rr, int k, int l, int r) //rlָǰi������rrָǰj������kָ��k��l��rָ��Χ
    {
        int d = tr[tr[rr].l].sum - tr[tr[rl].l].sum; //�״δ���rl��rr������root[a-1]��root[b]��Ȼ��tr[rr].l��tr[rl].l����������������ӣ�d��ʾ��������ǰ��ε����Ȩֵ���������ڼ�С��
        if (l == r)
            return l;
        int m = (l + r) / 2;
        if (k <= d)
            return query(tr[rl].l, tr[rr].l, k, l, m); //k������
        else
            return query(tr[rl].r, tr[rr].r, k - d, m + 1, r); //k�������Ȩֵ
    }
};
cheiftree ct;
int main()
{
    int n, m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    //��ɢ��
    for (int i = 1; i <= n; ++i)
        cin >> v[i].x, v[i].id = i;
    sort(v + 1, v + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
        hashing[v[i].id] = i;
    //��ϯ��
    ct.init();
    for (int i = 1; i <= n; ++i)
    {
        ct.root[i] = ct.root[i - 1];
        ct.update(1, n, ct.root[i], hashing[i]); //ÿ�μ���һ��ֵʱ����һ���������ѽڵ���ֵ���뵽Ȩֵ����
    }
    int a, b, k;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> k;
        //v[i].id=b,hash[v[i].id]=c => v[c]=v[hash[v[i].id]]=v[i];
        cout << v[ct.query(ct.root[a - 1], ct.root[b], k, 1, n)].x << endl; //��ѯ�����k���hashֵ��Ȼ�����Ƴ���ʵֵ
    }
    return 0;
}
