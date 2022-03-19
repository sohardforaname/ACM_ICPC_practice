#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	while (cin >> a >> b)
	{
		int i = 0, j = 0;
		while (i < a.size() && j < b.size())
		{
			if (a[i] == b[j])
				++i, ++j;
			else
				++j;
		}
		if (i != a.size())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
