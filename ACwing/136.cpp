#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include <limits.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
set<pair<int, int> >s;
int main()
{
	int n;
	cin >> n;
	s.insert({ INT_MIN,0 });
	s.insert({ INT_MAX,0 });
	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		if (i > 1)
		{
			auto it = s.upper_bound({ v,0 });
			auto jt = it;
			jt--;
			ll lv = (ll)v - jt->first, rv = it->first - (ll)v;
			if (lv <= rv)
				cout << lv << " " << jt->second << endl;
			else
				cout << rv << " " << it->second << endl;
		}
		s.insert({ v,i });
	}
	return 0;
}