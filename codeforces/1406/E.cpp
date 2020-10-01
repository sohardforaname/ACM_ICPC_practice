#include <bits/stdc++.h>
using namespace std;
unsigned short buf[200];
int main()
{
    FILE *fp = fopen("D:\\c.txt", "rb");
    int len = fread(buf, sizeof(unsigned short), 200, fp);
    for (int i = 0; i < len; ++i)
        printf("%x ", (buf[i] >> 8) | (buf[i] << 8));
    return 0;
}