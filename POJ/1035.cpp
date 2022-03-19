#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<string,int> >word;
vector<string>ans;
bool solve(string &str)
{
	bool flag = 0;
	int diff = 0;
	for (int i = 0; i < word.size(); ++i)//change
	{
		diff = 0;
		flag = 0;
		for (int j = 0; j < str.size() && str.size() == word[i].first.size() && diff < 2; ++j)
		{
			flag = 1;
			if (str[j] != word[i].first[j])
				++diff;
		}
		if (diff == 0 && flag)
			return 1;
		else if (diff == 1)
		{
			ans.push_back(word[i].first);
			continue;
		}
		diff = 0;
		flag = 0;
		int l_1 = 0, l_2 = 0;
		while (str.size() == word[i].first.size() - 1 && l_1 < str.size() && l_2 < word[i].first.size() && diff < 2)
		{
			flag = 1;
			if (str[l_1] == word[i].first[l_2])
				++l_1, ++l_2;
			else
				++l_2, ++diff;
		}
		if (diff <= 1 && flag)
		{
			ans.push_back(word[i].first);
			continue;
		}
		diff = 0;
		flag = 0;
		l_1 = 0, l_2 = 0;
		while (str.size() == word[i].first.size() + 1 && l_1 < str.size() && l_2 < word[i].first.size() && diff < 2)
		{
			flag = 1;
			if (str[l_1] == word[i].first[l_2])
				++l_1, ++l_2;
			else
				++l_1, ++diff;
		}
		if (diff <= 1 && flag)
		{
			ans.push_back(word[i].first);
			continue;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string tmp;
	int index = 1;
	while (cin >> tmp && tmp != "#")
		word.push_back(make_pair(tmp, tmp.size()));
	while (cin >> tmp && tmp != "#")
	{
		ans.clear();
		if (solve(tmp))
			cout << tmp << " is correct" << endl;
		else
		{
			cout << tmp << ":";
			for (int i = 0; i < ans.size(); ++i)
				cout << " " << ans[i];
			cout << endl;
		}
	}
	return 0;
}