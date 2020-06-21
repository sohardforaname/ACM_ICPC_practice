#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
int stoi(string &str)
{
	int ans = 0;
	for (int i = 0; i < str.size(); ++i)
		ans = ans * 10 + (str[i] - '0');
	return ans;
}
bool solve(int *exp)
{
	string tmp, num;
	cin >> tmp;
	//cout << "tmp=" << tmp << endl;
	if (tmp == "END")
		return false; //ÓÉEND·µ»Ø
	else if (tmp == "OP")
	{
		cin >> num;
		int i = stoi(num);
		exp[0] += i;
		return solve(exp);
	}
	else
	{
		int tmpexp[15] = {0};
		cin >> num;
		while (solve(tmpexp))
			;
		if (num == "n")
		{
			for (int i = 14; i > 0; --i)
				tmpexp[i] = tmpexp[i - 1];
			tmpexp[0] = 0;
		}
		else
		{
			int j = stoi(num);
			for (int i = 0; i < 15; ++i)
				tmpexp[i] *= j;
		}
		for (int i = 0; i < 15; ++i)
			exp[i] += tmpexp[i];
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
	{
		bool flag = 0;
		int exp[15] = {0};
		string tmp;
		cin >> tmp;
		while (solve(exp))
			;
		cout << "Program #" << j + 1 << endl;
		cout << "Runtime = ";
		for (int i = 14; i >= 0; --i)
		{
			if (i > 1 && exp[i])
			{
				if (flag)
					cout << "+";
				if (exp[i] == 1)
					cout << "n^" << i;
				else if (exp[i] > 1)
					cout << exp[i] << "*n^" << i;
				flag = 1;
			}
			else if (i == 1 && exp[i])
			{
				if (flag)
					cout << "+";
				if (exp[i] == 1)
					cout << "n";
				else
					cout << exp[i] << "*n";
				flag = 1;
			}
			else if (exp[i])
			{
				if (flag)
					cout << "+";
				cout << exp[i], flag = 1;
			}
		}
		if (!flag)
			cout << 0;
		cout << endl
			 << endl;
	}
	return 0;
}
