#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
map<string, string> mp;
char s1[100], s2[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stringstream ss;
    while (getline(cin, str) && str != "")
    {
        ss.clear();
        ss << str;
        ss >> s1 >> s2;
        mp[string(s2)] = string(s1);
    }
    while (getline(cin, str))
    {
        if (mp.find(str) == mp.end())
            cout << "eh\n";
        else
            cout << mp[str].c_str() << "\n";
    }
    return 0;
}