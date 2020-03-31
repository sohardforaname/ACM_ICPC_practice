#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define che(a,b) (ch1==a&&ch2==b)||(ch1==b&&ch2==a)
#define ee(a) (6.11*exp(5417.7530*((1.0/273.16) - (1.0/(a+273.16)))))
#define hh(a) (0.5555)*(a - 10.0)
#define chh(a) (a/0.5555+10.0)
#define cee(a) (1/((1.0/273.16)-log(a/6.11)/5417.7530)-273.16)
using namespace std;
double t,d,h;
char ch1,ch2;
void read(char &ch)
{
    cin>>ch;
    if(ch=='T')
        cin>>t;
    else if(ch=='D')
        cin>>d;
    else if(ch=='H')
        cin>>h;
    else
        exit(0);
}
int check(char ch1,char ch2)
{
    if(che('T','D'))
        return 1;
    else if(che('T','H'))
        return 2;
    else
        return 3;
}
int main()
{
    while(1)
    {
        read(ch1);
        read(ch2);
        int index = check(ch1,ch2);
        if(index==1)//know t and d
        {
            double e = ee(d);
            double h0 = hh(e);
            h = t+h0;
        }
        else if(index==2)//know t and h
        {
            double h0 = h-t;
            double e = chh(h0);
            d = cee(e);
        }
        else//know d and h
        {
            double e = ee(d);
            double h0 = hh(e);
            t = h-h0;
        }
        printf("T %.1f D %.1f H %.1f\n",t,d,h);
    }
}
