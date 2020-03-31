#include <iostream>
#include <algorithm>
using namespace std;
int o[26];
int n[26];
bool check()
{
    sort(o,o+26);
    sort(n,n+26);
    for(int i=0;i<26;++i)
        if(o[i]!=n[i])
            return false;
    return true;
}
int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();++i)
        ++o[str[i]-'A'];
    cin>>str;
    for(int i=0;i<str.size();++i)
        ++n[str[i]-'A'];
    if(check())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
