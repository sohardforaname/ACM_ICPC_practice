#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int j = 0;
	sort(b.begin(), b.end(), greater<char>());
	for (int i = 0; i < a.size() && j < b.size();)
	{
		while (b[j] <= a[i])
			++i;
		swap(b[j], a[i]);
		++j;
	}
	cout << a << endl;
	return 0;
}