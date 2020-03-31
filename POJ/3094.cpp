#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str)&&str!="#")
    {
        int cnt=0;
        for(int i=0;i<str.size();++i)
            if(isalpha(str[i]))
                cnt+=(i+1)*(str[i]-'A'+1);
        cout<<cnt<<endl;
    }
    return 0;
}
