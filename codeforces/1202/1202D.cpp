#include <bits/stdc++.h>
using namespace std;
long long num[100005];
void init()
{
    for(long long i=1;i<100005;++i)
        num[i]=i*(i-1)/2;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int pos;
        for(pos=1;num[pos]<=n;++pos);
            pos-=1;
        if(n-num[pos])
        {
            cout<<"133";
            for(int i=0;i<n-num[pos];++i)
                cout<<'7';
            for(int i=0;i<pos-2;++i)
                cout<<'3';
            cout<<'7';
            cout<<endl;
        }
        else
        {
            cout<<'1';
            for(int i=0;i<pos;++i)
                cout<<'3';
            cout<<'7';
            cout<<endl;
        }
    }
    return 0;
}

