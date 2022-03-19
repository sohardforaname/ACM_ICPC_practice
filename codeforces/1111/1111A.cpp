#include <iostream>
#include <string>
using namespace std;
const char ch[6] = "aeiou";
int main()
{
	string a, b;
	cin >> a >> b;
	bool f1, f2;
	if (a.size() != b.size())
	{
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0; i < a.size(); ++i)
	{
		f1 = 0, f2 = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (a[i] == ch[j])
				f1 = 1;
			if (b[i] == ch[j])
				f2 = 1;
		}
		if (f1^f2)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}