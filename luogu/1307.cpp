#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str, ans = "";
	cin >> str;
	bool flag = 0;
	if (str[0] == '-')
	{
		reverse(str.begin() + 1, str.end());
		ans += '-';
		for (int i = 1; i < str.size(); ++i)
		{
			if (str[i] != '0' || flag)
			{
				ans += str[i];
				flag = 1;
			}
		}
	}
	else
	{
		reverse(str.begin(), str.end());
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != '0' || flag)
			{
				ans += str[i];
				flag = 1;
			}
		}
	}
	if (ans == "" || ans == "-")
		cout << "0" << endl;
	else
		cout << ans << endl;
	return 0;
}