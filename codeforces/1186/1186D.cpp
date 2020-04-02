#include <bits/stdc++.h>
using namespace std;
double num[100005];
int tmp[100005];
double eps=1e-7;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%lf",&num[i]);
    for(int i=0;i<n;++i)
        tmp[i]=ceil(num[i]);
    long long sum=0;
    for(int i=0;i<n;++i)
        sum+=tmp[i];
    if(sum>0)//ÕıÊıÌ«´ó
    {
        for(int i=0;i<n&&sum;++i)
        {
            if(abs(num[i]-tmp[i])<eps)
                continue;
            --tmp[i];
            --sum;
        }
    }
    for(int i=0;i<n;++i)
        printf("%d\n",tmp[i]);
    return 0;
}
