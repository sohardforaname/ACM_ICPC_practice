#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool isprime[10000];
int prime[10000],pos=0;
void findprime()
{
    for(int i=0;i<10001;++i)
        isprime[i]=1;
    for(int i=2;i<10001;++i)
    {
        if(isprime[i])
            prime[pos++]=i;
        for(int j=0;j<pos&&prime[j]*i<10001;++j)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
    findprime();
    int n;
    queue<int>que;
    while(cin>>n&&n)
    {
        while(!que.empty())
            que.pop();
        int num=0,s=0,pos=0;
        que.push(0);
        while(1)
        {
            while(s>n)
                s-=que.front(),que.pop();
            if(que.empty())
                break;
            else if(s==n)
                ++num;
            que.push(prime[pos++]);
            s+=que.back();
        }
        cout<<num<<endl;
    }
    return 0;
}
