#include <iostream>
#include <string>
using namespace std;
int alp1[26], alp2[26], sim;
int main()
{
	string n, m;
	cin >> n >> m;
	if (n.size() != m.size())
		return cout << "NO" << endl, 0;
	for (int i = 0; i < n.size(); ++i)
	{
		++alp1[n[i] - 'a'];
		++alp2[m[i] - 'a'];
		if (n[i] == m[i])
			++sim;
	}
	bool flag = 0;
	for (int i = 0; i < 26; ++i)
		if (alp1[i] != alp2[i])
			flag = 1;
	if (n.size() - sim != 2 || flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}