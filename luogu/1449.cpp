#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<ll>num;
char str[1005];
ll del(ll a,ll b,int op)
{
    if(op=='+')
        return a+b;
    if(op=='-')
        return a-b;
    if(op=='*')
        return a*b;
    if(op=='/')
        return a/b;
    else 
        return 0;
}
ll atoi(int l,int r)
{
    ll sum=0;
    for(int i=l;i<r;++i)
        sum=sum*10+str[i]-'0';
    return sum;
}
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    int l,r;
    for(int i=0;i<len;++i)
    {
        if(isdigit(str[i]))
        {
            l=i;
            while(i<len&&isdigit(str[i]))
                ++i;
            r=i;
            num.push(atoi(l,r));
        }
        if(str[i]=='.'||str[i]=='@')
            continue;
        else
        {
            int a=num.top();
            num.pop();
            int b=num.top();
            num.pop();
            num.push(del(b,a,str[i]));
        }
    }
    printf("%lld\n",num.top());
    return 0;
}