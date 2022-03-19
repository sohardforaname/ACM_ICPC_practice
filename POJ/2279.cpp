#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[5];
vector< vector< vector< vector< vector< vector<int> > > > > >dp;
int main()
{
	int n;
	while (cin >> n)
	{
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; ++i)
			cin >> num[i];
		dp.resize(num[0]);
						
	}  
}
