#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
set<long long>s;
priority_queue<long long, vector<long long>, greater<long long> >que;
int ope[3] = { 2,3,5 };
int main()
{
#ifdef _Aya
	freopen("D:\\out.txt", "w", stdout);
#endif
	s.insert(1);
	que.push(1);
	for (int i = 1;; ++i)
	{
		long long tmp = que.top();
		que.pop();
		if (i == 1500)
			return cout << "The 1500'th ugly number is " << tmp << "." << endl, 0;
		for (int j = 0; j < 3; ++j)
		{
			long long t = tmp * ope[j];
			if (!s.count(t))
			{
				s.insert(tmp * ope[j]);
				que.push(tmp * ope[j]);
			}
		}
	}
}
