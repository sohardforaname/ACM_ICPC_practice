#include<iostream>  
#include<cstring>  
#include<algorithm>  
using namespace std;
const int L = 110;
string add(string& a, string& b)
{
	string ans;
	int na[L] = { 0 }, nb[L] = { 0 };
	int la = a.size(), lb = b.size();
	for (int i = 0; i < la; i++)
		na[la - 1 - i] = a[i] - '0';
	for (int i = 0; i < lb; i++)
		nb[lb - 1 - i] = b[i] - '0';
	int lmax = la > lb ? la : lb;
	for (int i = 0; i < lmax; i++)
		na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
	if (na[lmax])
		lmax++;
	for (int i = lmax - 1; i >= 0; i--)
		ans += na[i] + '0';
	return ans;
}
int main()
{
	string a, b;
	cin >> a;
	while (cin >> b && b != "0")
		a = add(a, b);
	cout << a << endl;
	return 0;
}
