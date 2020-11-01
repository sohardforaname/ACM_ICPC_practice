#include <bits/stdc++.h>
using namespace std;
const int maxn = 10100;
const double eps = 1e-6;
int dcmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    else return -1;
}
struct node
{
    char name[25];
    double dec;
    node() {}
} nds[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", nds[i].name);
        scanf("%lf", &nds[i].dec);
    }
    double ans = 0;
    if(n==1){
        if(dcmp(nds[1].dec-100.0)==0){
            printf("%s %.2lf %.2lf\n", nds[1].name,nds[1].dec,nds[1].dec);
        }
        else{
            printf("IMPOSSIBLE\n");
        }
    }
    else{
        for (int i = 1; i <= n; i++)
        {
            ans += nds[i].dec;
        }
        ans = ans + (n - 1) / 2.0;
        if (dcmp(ans - 100) == 0)
        {
            double lvalue, rvalue;
            for (int i = 1; i <= n; i++)
            {
                lvalue = nds[i].dec + 0.01 * (n - 1);
                rvalue = nds[i].dec + 0.49;
                printf("%s %.2lf %.2lf\n", nds[i].name, lvalue, rvalue);
            }
        }
        else if (dcmp(ans - 100) == 1)
        {
            double lvalue, rvalue;
            for (int i = 1; i <= n; i++)
            {
                lvalue = nds[i].dec - 0.50 + 0.01 * (n - 1);
                rvalue = nds[i].dec + 0.49;
                printf("%s %.2lf %.2lf\n", nds[i].name, lvalue, rvalue);
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    system("pause");
    return 0;
}