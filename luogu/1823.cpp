#include <iostream>
#include <stack>
#include <list>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long cnt=0;
	stack<pair<int,int> >s;
	int tmp;
	for(int i=0;i<n;++i)
	{
		cin>>tmp;
		pair<int,int>ptmp=make_pair(tmp,1);
		while(!s.empty()&&s.top().first<=tmp)
		{
			cnt+=s.top().second;
			if(tmp==s.top().first)
				ptmp.second+=s.top().second;
			s.pop();
		}
		if(!s.empty())
			++cnt;
		s.push(ptmp);
	}
	cout<<cnt<<endl;
	return 0;	
}
