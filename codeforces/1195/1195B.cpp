#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n,k;
    cin>>n>>k;
    long i=0;
    while(++i)
    {
        if(i*(i+1)/2<k)
            continue;
        else
        {
            int tmp=(i*(i+1)/2)-k;
            if(tmp+i==n)
            {
                cout<<tmp<<endl;
                return 0;
            }
        }
    }
}
