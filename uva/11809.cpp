#include <bits/stdc++.h>
using namespace std;
long double A[15][35];
long long B[15][35];
int main()
{
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    for(int i=0;i<=9;++i)
        for(int j=1;j<=30;++j)
        {
            double m=1-pow(2,-1-i);
            int e=pow(2,j)-1;
            B[i][j]=(long long)(log10(m)+e*log10(2));
            A[i][j]=pow(10,log10(m)+e*log10(2)-B[i][j]);
        }
    /*for(int i=0;i<=9;++i)
        for(int j=1;j<=30;++j)
            cout<<A[i][j]<<" "<<B[i][j]<<endl;*/
    string str;
    while(cin>>str&&str!="0e0")
    {
        for(auto &i:str)
            if(i=='e')
                i=' ';
        istringstream ss(str);
        long double a;
        long long b;
        ss>>a>>b;
        while(a<1)
        {
            a*=10;
            b-=1;
        }
        for(int i=0;i<=9;++i)
            for(int j=1;j<=30;++j)
            {
                if(B[i][j]==b&&abs(a-A[i][j])<1e-4)
                {
                    cout<<i<<" "<<j<<endl;
                    goto lab;
                }
            }
        lab:;
    }
    return 0;
}
