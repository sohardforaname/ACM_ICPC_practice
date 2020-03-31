#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    char ch;
    while((ch=getchar())&&ch!='E')
    {
        if(ch=='\n')
            continue;
        else
            str+=ch;
    }
    while(cin>>ch)
        continue;
    int p1=0,p2=0;
    for(int i=0;i<str.size();++i)
    {
        if(str[i]=='W')
            ++p1;
        else if(str[i]=='L')
            ++p2;
        if(p1>=11&&p1-p2>1)
        {
            cout<<p1<<':'<<p2<<endl;
            p1=0,p2=0;
        }        
        else if(p2>=11&&p2-p1>1)
        {
            cout<<p1<<':'<<p2<<endl;
            p1=0,p2=0;
        }
    }
    cout<<p1<<':'<<p2<<endl;
    p1=0,p2=0;
    cout<<endl;
    for(int i=0;i<str.size();++i)
    {
        if(str[i]=='W')
            ++p1;
        else if(str[i]=='L')
            ++p2;
        if(p1>=21&&p1-p2>1)
        {
            cout<<p1<<':'<<p2<<endl;
            p1=0,p2=0;
        }        
        else if(p2>=21&&p2-p1>1)
        {
            cout<<p1<<':'<<p2<<endl;
            p1=0,p2=0;
        }
    }
    cout<<p1<<':'<<p2<<endl;
    return 0;
}
