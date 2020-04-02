#include <bits/stdc++.h>
using namespace std;
int alpn[26],alpo[26];
bool check1()
{
    bool flag=1;
    for(int i=0;i<26;++i)
        if(alpn[i]<alpo[i])
        {
            flag=0;
            break;
        }
    return flag;
}
bool check2(string &s,string &t)
{
    bool flag=0;
    int spos=0,tpos=0;
    while(spos!=s.size())
    {
        if(tpos==t.size())
            return 0;
        if(s[spos]==t[tpos])
            ++spos,++tpos;
        else
            ++tpos;
    }
    return 1;
}
int main()
{
    string s,t,p;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s>>t>>p;
        memset(alpn,0,sizeof(alpn));
        memset(alpo,0,sizeof(alpo));
        for(int i=0;i<s.size();++i)
            ++alpn[s[i]-'a'];
        for(int i=0;i<p.size();++i)
            ++alpn[p[i]-'a'];
        for(int i=0;i<t.size();++i)
            ++alpo[t[i]-'a'];
        if(!check1()||!check2(s,t))
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
