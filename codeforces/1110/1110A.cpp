#include <iostream>
#include <string>
using namespace std;
int num[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int b, k;
	cin >> b >> k;
	for (int i = 0; i < k; ++i)
		cin >> num[i];
	int odds = 0, eves = 0;
	for (int i = 0; i < k - 1; ++i)
	{
		if (num[i] % 2 == 0 || b % 2 == 0)
			++eves;
		else
			++odds;
	}
	if (num[k - 1] % 2)
		++odds;
	else
		++eves;
	if (odds % 2 == 0)
		cout << "even" << endl;
	else if (odds % 2 == 1)
		cout << "odd" << endl;
	return 0;	
}