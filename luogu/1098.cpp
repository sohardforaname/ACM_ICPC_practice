#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string str;
void solve(int p1,int p2,int p3,char a,char b)
{
    if(b-a>1)
    {
        if(isdigit(a)&&isdigit(b))
        {
            if(p1==1||p1==2)
            {
                if(p3==1)
                {
                    for(int i=a+1;i<b;++i)
                        for(int j=0;j<p2;++j)
                            cout<<char(i);
                }
                else if(p3==2)
                {
                    for(int i=b-1;i>a;--i)
                        for(int j=0;j<p2;++j)
                            cout<<char(i);
                }
            }
            else if(p1==3)
            {
                for(int i=a+1;i<b;++i)
                    for(int j=0;j<p2;++j)
                            cout<<'*';
            }
        }
        else if(isalpha(a)&&isalpha(b))
        {
            if(p1==1)
            {
                if(p3==1)
                {
                    for(int i=a+1;i<b;++i)
                        for(int j=0;j<p2;++j)
                            cout<<char(tolower(i));
                }
                else if(p3==2)
                {
                    for(int i=b-1;i>a;--i)
                        for(int j=0;j<p2;++j)
                            cout<<char(tolower(i));
                }
            }
            else if(p1==2)
            {
                if(p3==1)
                {
                    for(int i=a+1;i<b;++i)
                        for(int j=0;j<p2;++j)
                            cout<<char(toupper(i));
                }
                else if(p3==2)
                {
                    for(int i=b-1;i>a;--i)
                        for(int j=0;j<p2;++j)
                            cout<<char(toupper(i));
                }
            }
            else if(p1==3)
            {
                for(int i=a+1;i<b;++i)
                        for(int j=0;j<p2;++j)
                            cout<<'*';
            }
        }
        else
            cout<<'-';
    }
    else if(b-a<1)
        cout<<'-';
}
int main()
{
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    cin>>str;
    for(int i=0;i<str.size();++i)
    {
        if(str[i]=='-')
        {
            if(i==0||i==str.size()-1)
                cout<<'-';
            else if(str[i-1]!='-'&&str[i+1]!='-') 
                solve(p1,p2,p3,str[i-1],str[i+1]);
            else
                cout<<'-'; 
        }
        else if(str[i]!='-')
        {
            cout<<str[i];
        }
    }
    cout<<endl;
    return 0;
}
