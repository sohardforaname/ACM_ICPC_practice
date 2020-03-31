#include <bits/stdc++.h>
using namespace std;
int code[8][1<<8];
char readchar()
{
    char ch;
    while((ch=getchar())&&(ch=='\n'||ch=='\r'));
    return ch;
}
int readint(int c)
{
    int v=0;
    while(c--)
        v=(v<<1)+(readchar()-'0');
    return v;

}
int readcode()
{
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    if(code[1][0]==EOF)
        return 0;
    for(int l=2;l<8;++l)
        for(int i=0;i<(1<<l)-1;++i)
        {
            char ch=getchar();
            if(ch==EOF)
                return 0;
            else if(ch=='\n'||ch=='\r')
                return 1;
            else 
                code[l][i]=ch;
        }
}
int main()
{
    while(readcode())
    {
        while(1)
        {
            int len=readint(3);
            if(len==0)
                break;
            int i;
            while(1)
            {
                i=readint(len);
                if(i==(1<<len)-1)
                    break;
                printf("%c",code[len][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
