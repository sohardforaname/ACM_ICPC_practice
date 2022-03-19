#include <iostream>
using namespace std;
bool s[5][5]{ {0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1} ,{1,1,0,0,0} };
int x[1005], y[1005];
int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < a; ++i)
		cin >> x[i];
	for (int i = 0; i < b; ++i)
		cin >> y[i];
	int ans = 0, bns = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += s[x[i % a]][y[i % b]];
		bns += s[y[i % b]][x[i % a]];
	}
	cout << ans << " " << bns << endl;
	return 0;
}
