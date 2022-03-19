#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[2], b[2];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		++a[s[i] - '0'];
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		++b[s[i] - '0'];
	int le1;
	if (!b[0] || !b[1])
		le1 = 0;
	else
		le1 = min(a[0] / b[0], a[1] / b[1]);
	for (int i = 0; i < le1; ++i)
		cout << s;
	for (int i = 0; i < a[0] - le1 * b[0]; ++i)
		cout << 0;
	for (int i = 0; i < a[1] - le1 * b[1]; ++i)
		cout << 1;
	cout << endl;
	return 0;
}