#include <iostream>
#include <stack>
#include <string>
using namespace std;
string str;
stack<int>s;
bool f[5];
void gen(int i)
{
    int pos=0;
    while(pos<5)
    {
        f[pos++]=i%2;
        i>>=1;
    }
}
int hashing(char ch)
{
    if(ch=='p')
        return 0;
    else if(ch=='q')
        return 1;
    else if(ch=='r')
        return 2;
    else if(ch=='s')
        return 3;
    else if(ch=='t')
        return 4;
}
void solve(char ch)
{
    if(ch=='p'||ch=='q'||ch=='r'||ch=='s'||ch=='t')
        s.push(f[hashing(ch)]);
    else if(ch=='N')
    {
        bool tmp=s.top();
        s.pop();
        s.push(!tmp);
    }
    else if(ch=='K')
    {
        bool t1=s.top();
        s.pop();
        bool t2=s.top();
        s.pop();
        s.push(t1&&t2);
    }
    else if(ch=='A')
    {
        bool t1=s.top();
        s.pop();
        bool t2=s.top();
        s.pop();
        s.push(t1||t2);
    }
    else if(ch=='C')
    {
        bool t1=s.top();
        s.pop();
        bool t2=s.top();
        s.pop();
        s.push((!t1)||t2);
    }
    else if(ch=='E')
    {
        bool t1=s.top();
        s.pop();
        bool t2=s.top();
        s.pop();
        s.push(t1==t2);
    }
}
int main()
{
    bool flag;
    while(cin>>str&&str!="0")
    {
        flag=1;
        while(s.size())
            s.pop();
        for(int i=0;i<32;++i)
        {
            gen(i);
            //for(int i=0;i<5;++i)
                //cout<<f[i]<<" ";
            //cout<<endl;
            for(int j=str.size()-1;j>-1;--j)
                solve(str[j]);
            if(!s.top())
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"tautology"<<endl;
        else
            cout<<"not"<<endl;
    }
    return 0;
}
