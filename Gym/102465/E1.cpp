#include <bits/stdc++.h>
using namespace std;
const int maxn = 20100;
const double eps = 1e-6;
int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x > 0)
        return 1;
    else
        return -1;
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
    for (int i = 1; i <= n;i++){
        ans += nds[i].dec;
    }
    if(dcmp(ans+n*0.49-100)==-1||dcmp(ans-n*0.5-100)==1){
        printf("IMPOSSIBLE\n");
    }
    else{
        double lval = ans + (n - 1) * 0.49 - 100;
        if(dcmp(lval-0.5)==1){
            lval = 0.5;
        }
        double rval = 100 - (ans - (n - 1) * 0.5);
        if(dcmp(rval-0.49)==1){
            rval = 0.49;
        }
        for (int i = 1; i <= n;i++){
            double lvalue = nds[i].dec - lval;
            double rvalue = nds[i].dec + rval;
            printf("%s %.2lf %.2lf\n", nds[i].name, lvalue, rvalue);
        }
    }
    system("pause");
    return 0;
}