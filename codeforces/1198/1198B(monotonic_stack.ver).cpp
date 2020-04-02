#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int sta[MAXN],top=0,num[MAXN],lstch[MAXN],add[MAXN];

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
    
inline void read(int &x) 
{
    x = 0; 
    char c = gc();
    for(; c < '0' || c > '9'; c = gc())
        ;
    for(; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + c - '0';
    return;
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
    //putchar('\n');
}

int main()
{
    int n,m,a,p,x;
    //scanf("%d",&n);
    read(n);
    for(int i=1;i<=n;++i)
        read(num[i]);
        //scanf("%d",&num[i]);
    //scanf("%d",&m);
    read(m);
    for(int i=1;i<=m;++i)
    {
        read(a);
        //scanf("%d",&a);
        read(p);
        //scanf("%d",&p);
        if(a==1)
        {
            read(x);
            //scanf("%d",&x);
            num[p]=x;
            lstch[p]=i;
        }
        else
        {
            while(top&&p>=sta[top])
                --top;
            sta[++top]=p;
            add[top]=i;
        }
    }
    sta[++top]=0;
    add[top]=m+1;
    for(int i=1;i<=n;++i)
        num[i]=max(num[i],sta[lower_bound(add+1,add+top+1,lstch[i])-add]);
    for(int i=1;i<=n;++i)
        write(num[i]),putchar(i==n?'\n':' ');
    return 0;
}
