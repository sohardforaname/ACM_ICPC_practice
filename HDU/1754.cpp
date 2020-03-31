#include <iostream>
#include <cstring>
using namespace std;
#define Tree 200005
#define max(a,b) a>b?a:b
struct Segtree
{
	struct node
	{
		int l,r;
		long long val,lazy;
	}tree[Tree*4];
	void clean()
	{
		memset(tree,0,sizeof(tree));
	} 
	void build(int l,int r,int k)
	{
		tree[k].l=l,tree[k].r=r,tree[k].lazy=0;
		if(l==r)
		{
			cin>>tree[k].val;
			return; 
		}
		int m=(l+r)/2;
		build(l,m,k*2);
		build(m+1,r,k*2+1);
		tree[k].val=max(tree[k*2].val,tree[k*2+1].val);
	}
	void change(int pos,int k,long long val)
	{
		if(pos==tree[k].l&&pos==tree[k].r)
		{
			tree[k].val=val;
			return;
		}
		int m=(tree[k].l+tree[k].r)/2;
		if(pos<=m)
			change(pos,k*2,val);
		else if(pos>=m+1)
			change(pos,k*2+1,val);
		tree[k].val=max(tree[k*2].val,tree[k*2+1].val);		
	}
	long long ask(int l,int r,int k)
	{
		if(l<=tree[k].l&&r>=tree[k].r)
			return tree[k].val;
		int m=(tree[k].l+tree[k].r)/2;
		long long leftres=0,rightres=0;
		if(l<=m)
			leftres=ask(l,r,k*2);
		if(r>=m+1)
			rightres=ask(l,r,k*2+1);
		return max(leftres,rightres);		
	}
};
Segtree seg;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a,b;
	char ch;
	while(cin>>n>>m)
	{
		seg.clean();
		seg.build(1,n,1);
		for(int i=0;i<m;++i)
		{
			cin>>ch;
			if(ch=='Q')
			{
				cin>>a>>b;
				cout<<seg.ask(a,b,1)<<endl; 
			}
			else if(ch=='U')
			{
				cin>>a>>b;
				seg.change(a,1,b);
			}
		}
	}
	return 0;
}