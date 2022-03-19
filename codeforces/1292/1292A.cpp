#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool A[2][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int m = 0;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		--a;
		if (A[a][b])
		{
			A[a][b] = 0;
			m -= A[a ^ 1][b + 1] + A[a ^ 1][b] + A[a ^ 1][b - 1];
		}
		else if (!A[a][b])
		{
			A[a][b] = 1;
			m += A[a ^ 1][b + 1] + A[a ^ 1][b] + A[a ^ 1][b - 1];
		}
		cout << (m ? "No\n" : "Yes\n");
	}
	return 0;
}