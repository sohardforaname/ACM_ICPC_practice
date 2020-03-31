#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 200005
struct value
{
    int id;
    int x;
};
value v[MAXN];
int hashing[MAXN];
bool cmp(const value &a,const value &b)
{
    return a.x<b.x;
}
int cnt=0;
struct cheiftree
{
    struct node
    {
        int l,r;//l,r记录节点编号而不是区间长
        int sum;
        node()
        {
            sum=0;
        }
    };
    node tr[MAXN*20];
    int root[MAXN];
    void init()
    {
        cnt=1;//树根计数
        tr[0].l=tr[0].r=tr[0].sum=0;//左右孩子的权值初始化为0
        root[0]=0;//树根初始化为0      
    }
    void update(int l,int r,int &nrt,int num)//l，m表示区间范围
    {
        tr[cnt++]=tr[nrt];//新的树根，nrt代表的单元此时为root[i-1]
        nrt=cnt-1;//将cnt-1赋给root[i]即为将树根标记序号
        ++tr[nrt].sum;//然后传入一个新数，权值即数的个数+1，数量即为root[i-1]+1
        if(l==r)//到达叶节点
            return;
        int m=(l+r)/2;//计算区间中点
        if(num<=m)
            update(l,m,tr[nrt].l,num);//把当前树根的左孩子传入
            //由于update使用引用，故左孩子将会被挂到其父亲节点上
        else
            update(m+1,r,tr[nrt].r,num);
            //右孩子同理
    }
    int query(int rl,int rr,int k,int l,int r)//rl指前i棵树，rr指前j棵树，k指第k大，l和r指范围
    {
        int d=tr[tr[rr].l].sum-tr[tr[rl].l].sum;//首次传入rl与rr是树根root[a-1]与root[b]，然后tr[rr].l与tr[rl].l就是两树根的左儿子，d表示这个区间的前半段的最大权值（就是最大第几小）
        if(l==r)
            return l;
        int m=(l+r)/2;
        if(k<=d)
            return query(tr[rl].l,tr[rr].l,k,l,m);//k在其中
        else
            return query(tr[rl].r,tr[rr].r,k-d,m+1,r);//k大于最大权值
    }
};
cheiftree ct;
int main()
{
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    //离散化
    for(int i=1;i<=n;++i)
        cin>>v[i].x,v[i].id=i;
    sort(v+1,v+1+n,cmp);
    for(int i=1;i<=n;++i)
        hashing[v[i].id]=i;
    //主席树
    ct.init();
    for(int i=1;i<=n;++i)
    {
        ct.root[i]=ct.root[i-1];
        ct.update(1,n,ct.root[i],hashing[i]);//每次加入一个值时建立一棵新树，把节点新值加入到权值树中
    }
    int a,b,k;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>k;
        //v[i].id=b,hash[v[i].id]=c => v[c]=v[hash[v[i].id]]=v[i];
        cout<<v[ct.query(ct.root[a-1],ct.root[b],k,1,n)].x<<endl;//查询区间第k大的hash值，然后逆推出真实值
    }
    return 0;
}
