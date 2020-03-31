#include <bits/stdc++.h>
using namespace std;
set<string>s;
int main()
{
#ifdef _Aya
	freopen("out.txt", "w", stdout);
#endif
	string str, tmp;
	stringstream ss;
	while (cin >> str)
	{
 		for (auto& i : str)
		{
			if (isalpha(i))
				i = tolower(i);
			else
				i = ' ';
		}
		ss.clear();
		ss << str;
		while (ss >> tmp)
			s.insert(tmp);
	}
	for (auto& i : s)
		cout << i << endl;
	return 0;
}
