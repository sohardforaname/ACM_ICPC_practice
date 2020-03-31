#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.size() / 2; ++i)
	{
		if (tmp[i] == 'R' && tmp[tmp.size() / 2 + i] == 'L')
			cout << tmp.size() / 2 + i + 1 << " " << i + 1 << endl;
		else
			cout << i + 1 << " " << tmp.size() / 2 + i + 1 << endl;
	}
	return 0;
}