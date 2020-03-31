#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
bool numans[26], numgue[26];
string a, b;
int main()
{
	int n;
	while (cin >> n && n != -1)
	{
		cout << "Round " << n << endl;
		cin >> a >> b;
		memset(numans, 0, sizeof(numans));
		memset(numgue, 0, sizeof(numgue));
		int ansall = 0;
		for (int i = 0; i < a.size(); ++i)
			if (!numans[a[i] - 'a'])
				numans[a[i] - 'a'] = 1, ++ansall;
		int right = 0, wrong = 0, flag = 0;
		for (int i = 0; i < b.size(); ++i)
		{
			if (numans[b[i] - 'a']&&!numgue[b[i] - 'a'])
				++right;
			else if(!numans[b[i]-'a'])
				++wrong;
			if (!numgue[b[i] - 'a'])
				numgue[b[i] - 'a'] = 1;
			if (right == ansall)
			{
				cout << "You win." << endl;
				flag = 1;
				break;
			}
			else if (wrong >= 7)
			{
				cout << "You lose." << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "You chickened out." << endl;
	}
	return 0;
}