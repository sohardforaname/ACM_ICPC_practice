#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s;
    void *p = NULL, *p1 = &s;
    memcpy(p1, p, sizeof(int));
    return 0;
}