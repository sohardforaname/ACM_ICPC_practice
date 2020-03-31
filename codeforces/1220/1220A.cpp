#include <bits/stdc++.h>
using namespace std;
int num[128];
char str[100005];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;++i)
        ++num[str[i]];
    int m=min(num['o'],num['e']),k=min(num['z'],num['r']),p=num['n'];
    int tg0=0,tg1=0;
    if(k+p>m)
        tg1=p,tg0=m-p;
    else if(k+p<=m)
        tg1=p,tg0=k;
    for(int i=1;i<=tg1;++i)
        printf("1 ");
    for(int i=1;i<=tg0;++i)
        printf("0 ");
    printf("\n");
    return 0;
}