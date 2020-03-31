#include <iostream>
using namespace std;
void output(int a)
{
    if(a>=0)
        cout<<a<<endl;
    else
        cout<<"Deficit"<<endl;
}
int main()
{
    int n,m;
    while(cin>>n>>m)//nÓ¯Àû£¬m¿÷Ëğ
    {
        if(n*4<m)
            output(n*10-m*2);
        else if(n*3<m*2)
            output(n*8-m*4);
        else if(n*2<m*3)
            output(n*6-m*6);
        else if(n<m*4)
            output(n*3-m*9);
        else
            cout<<"Deficit"<<endl;
    }
    return 0;
}
//5
//0 0 0 0 1 0 0 0 0 1 0 0
//4
//0 0 0 1 1 0 0 0 1 1 0 0
//3
//0 0 1 1 1 0 0 1 1 1 0 0
//4
//0 1 1 1 1 0 1 1 1 1 0 1
//5
//1 1 1 1 1 1 1 1 1 1 1 1
