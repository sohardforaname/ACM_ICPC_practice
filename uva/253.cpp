#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string str,str11,str12,str13,str21,str22,str23;
    while(cin>>str){
        str11=str[0]+str[5];
        str12=str[1]+str[4];
        str13=str[2]+str[3];
        str21=str[6]+str[11];
        str22=str[7]+str[10];
        str23=str[8]+str[9];
        if((str11==str21||str11==str22||str11==str23)&&
           (str12==str21||str12==str22||str12==str23)&&
           (str13==str21||str13==str22||str13==str23))
            if((str21==str11||str21==str12||str21==str13)&&
               (str22==str11||str22==str12||str22==str13)&&
               (str23==str11||str23==str12||str23==str13))   //正反都来一次以确保有三个元素组成的可重复集合的单射映射
                 cout<<"TRUE"<<endl;
            else cout<<"FALSE"<<endl;
        else cout<<"FALSE"<<endl;
    }
    return 0;
}
