#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int h,f;
};
node app[5005];
bool cmp(const node &a,const node &b)
{
	return a.f<b.f;	
}
int main()
{
	int n,s,a,b;
	cin>>n>>s>>a>>b;
	for(int i=0;i<n;++i)
		cin>>app[i].h>>app[i].f;
	int cnt=0;
	sort(app,app+n,cmp);
	for(int i=0;i<n;++i)
	{
		//cout<<app[i].h<<endl;
		if(app[i].h>a+b)
			continue;
		if(app[i].h<=a+b)
		{
			s-=app[i].f;
			if(s<0)
				break;
			++cnt;
		}
		//cout<<s<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}