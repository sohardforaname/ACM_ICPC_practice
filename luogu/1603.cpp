#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
map<string, int>m;
string str[] = { "a","both","another"," first"," second"," third" ,"one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty" };
int num[] = { 1,4,1,1,4,9,1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0 };
vector<int>vec;
void init()
{
	for (int i = 0; i < 26; ++i)
		m[str[i]] = num[i];
}
int main()
{
	init();
	string s, sn = "";
	for (int i = 0; i < 6; ++i)
	{
		cin >> s;
		for (int j = 0; j < s.size(); ++j)
		{
			if (isalpha(s[j]))
				sn += s[j];
			else if (isupper(s[j]))
				sn += tolower(s[j]);
		}
		if (m.find(sn) != m.end())
			vec.push_back((*(m.find(sn))).second);
	}
	sort(vec.begin(), vec.end());
	bool f = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (!f)
		{

		}
	}
	return 0;
}