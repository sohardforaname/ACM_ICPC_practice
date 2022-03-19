#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int alpha[26];
int main()
{
	string str, tmp;
	int n;
	cin >> n;
	cin >> str;
	for (int i = 0; i < str.size() - 1; ++i)
	{
		for (int j = 1; j + i <= str.size(); ++j)
		{
			tmp = str.substr(i, j);
			memset(alpha, 0, sizeof(alpha));
			bool flag = 0;
			for (int k = 0; k < tmp.size(); ++k)
				++alpha[tmp[k] - 'a'];
			for (int k = 0; k < 26; ++k)
				if (alpha[k] > tmp.size() / 2)
				{
					flag = 1;
					break;
				}
			if (!flag)
			{
				cout << "YES" << endl << tmp << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}