#include <iostream>
#include <vector>
using namespace std;
struct node
{
	char c,a;
}num[5005];
vector<int>aa,bb,cc,dd;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>num[i].c;
	for(int i=1;i<=n;++i)
		cin>>num[i].a;	
	for(int i=1;i<=n;++i)
	{
		if(num[i].c=='0'&&num[i].a=='0')
			aa.push_back(i);
		else if(num[i].c=='0'&&num[i].a=='1')
			bb.push_back(i);
		else if(num[i].c=='1'&&num[i].a=='0')
			cc.push_back(i);
		else if(num[i].c=='1'&&num[i].a=='1')
			dd.push_back(i);			
	}	
	int A=aa.size(),B=bb.size(),C=cc.size(),D=dd.size();
	bool flag=0;
	//cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
	for(int a=0;a<=A&&a<n/2+1;++a)
	{
		int d=B+D-n/2+a;
		if(d<=D&&d>=0)
		{
			for(int b=0;b<=B&&b<n/2+1-a;++b)
			{
				int c=B-b+D-2*d;
				if(c<=C&&c>=0)
				{
					flag=1;
					//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
					for(int i=0;i<a;++i)
						cout<<aa[i]<<" ";
					for(int i=0;i<b;++i)
						cout<<bb[i]<<" ";
					for(int i=0;i<c;++i)
						cout<<cc[i]<<" ";
					for(int i=0;i<d;++i)
						cout<<dd[i]<<" ";
					cout<<endl;
					goto l;		
				}		
			}
		}
	}
	l:
	if(!flag)
		cout<<-1<<endl;
	return 0;
}