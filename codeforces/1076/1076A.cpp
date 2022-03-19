#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alpha[26];
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	bool tag = 0;
	int pos = n - 1;
	for (int i = 1; i < n; ++i)
		if (str[i] < str[i - 1] && tag == 0)
			tag = 1, pos = i - 1;
	for (int i = 0; i < n; ++i)
		if (i != pos)
			cout << str[i];
	cout << endl;
	return 0;
}