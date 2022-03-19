#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long ans;
	cin >> ans;
	int d = sqrt(ans);
	if (d*d == ans)
		cout << d * 2 << endl;
	else if (d*(d + 1) < ans)
		cout << (d + 1) * 2 << endl;
	else
		cout << d * 2 + 1 << endl;
	return 0;
}