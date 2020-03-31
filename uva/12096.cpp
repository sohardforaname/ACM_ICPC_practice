#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
map<set<int>, int>mp;
vector<set<int>>vec;
stack<int>s;
int n;
int getID(set<int> x)
{
	if (mp.count(x))
		return mp[x];
	vec.push_back(x);
	return mp[x] = vec.size() - 1;
}
#define ALL(x) x.begin(),x.end()
int main()
{
#ifdef _Aya
	freopen("D:\\out.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	string op;
	while (T--)
	{
		while (s.size())
			s.pop();
		mp.clear();
		vec.clear();
		cin >> n;
		while (n--)
		{
			cin >> op;
			if (op[0] == 'P')
				s.push(getID(set<int>()));
			else if (op[0] == 'D')
				s.push(s.top());
			else
			{
				set<int>tmp1 = vec[s.top()];
				s.pop();
				set<int>tmp2 = vec[s.top()];
				s.pop();
				set<int>tmp;
				if (op[0] == 'U')
					set_union(ALL(tmp1), ALL(tmp2), inserter(tmp, tmp.begin()));
				else if (op[0] == 'I')
					set_intersection(ALL(tmp1), ALL(tmp2), inserter(tmp, tmp.begin()));
				else if (op[0] == 'A')
					tmp = tmp2, tmp.insert(getID(tmp1));
				s.push(getID(tmp));
			}
			cout << vec[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
	return 0;
}
