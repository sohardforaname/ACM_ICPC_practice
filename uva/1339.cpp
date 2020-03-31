#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int numbe[26], numae[26];
string a, b;
void solve(string &a, string &b)
{
	memset(numae, 0, sizeof(numae));
	memset(numbe, 0, sizeof(numbe));
	for (int i = 0; i < a.size(); ++i)
		++numae[a[i] - 'A'];
	for (int i = 0; i < a.size(); ++i)
		++numbe[b[i] - 'A'];
	sort(numbe, numbe + 26);
	sort(numae, numae + 26);
	for (int i = 0; i < 26; ++i)
		if (numbe[i] != numae[i])
		{
			cout << "NO" << endl;
			return;
		}
	cout << "YES" << endl;
	return;
}
int main()
{
	while (cin >> a >> b)
		solve(a, b);
	return 0;
}