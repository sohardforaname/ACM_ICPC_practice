#include <bits/stdc++.h>
using namespace std;
int num[400005],tmp[400005],sum[400005];
#define int128 __int128
const long long INF=0x3f3f3f3f3f3f3f3f;
struct reader
{
    const int MAXBUF = 1 << 20;
    char buf[1<<20], *fh=NULL, *ft=NULL;
    inline char gc() 
    {
        if(fh == ft) 
        {
            int l = fread(buf, 1, MAXBUF, stdin);
            ft = (fh = buf) + l;
        }
        return *fh++;
    }

    inline int read() 
    {
        int x = 0;
        char c = gc();
        for(; c < '0' || c > '9'; c = gc())
            ;
        for(; c >= '0' && c <= '9'; c = gc())
            x = (x << 3) + (x << 1) + c - '0';
        return x ;
    }
    inline void _write(long long x) 
    {
        if(x > 9)
            _write(x / 10);
        putchar(x % 10 + '0');
    }
    inline void write(long long x) 
    {
        _write(x);
        putchar('\n');
    }
};
reader r;

long long poww(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(a>=4e5+1)
            return INF;
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
        if(res>=4e5+1)
            return INF;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,I;
    cin>>n>>I;
    for(int i=0;i<n;++i)
        cin>>num[i];
    int maxk=(8*I)/n;
    long long Kmax=poww(2,maxk);
    //ÀëÉ¢»¯¼ÆÊý
    for(int i=0;i<n;++i)
        tmp[i]=num[i];
    sort(tmp,tmp+n);
    int nnew=unique(tmp,tmp+n)-tmp;
    if(nnew<=Kmax)
        cout<<0<<endl;
    else
    {
        int ans,minn=0;
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;++i)
            ++sum[lower_bound(tmp,tmp+nnew,num[i])-tmp];
        //sort(sum,sum+nnew);
        //for(int i=0;i<nnew;++i)
            //cout<<sum[i]<<endl;
        for(int i=0;i<Kmax;++i)
            minn+=sum[i];
        ans=n-minn;
        for(int i=Kmax;i<nnew;++i)
        {
            minn=minn-sum[i-Kmax]+sum[i];
            ans=min(ans,n-minn);
        }
        cout<<ans<<endl;
    }
    return 0;
}
