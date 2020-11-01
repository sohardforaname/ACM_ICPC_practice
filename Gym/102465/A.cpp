#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
bool lights[maxn];
int main()
{
    memset(lights, true, sizeof(lights));
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int val;
    int maxx = -1;
    for (int i = 0; i < k; i++){
        scanf("%d", &val);
        for (int j = val; j <= n;j+=val){
            lights[j] = !lights[j];
        }
        int res = 0;
        for (int j = 1; j <= n;j++){
            if(!lights[j])
                res++;
        }
        maxx = max(res, maxx);
    }
    printf("%d\n", maxx);
    //system("pause");
    return 0;
}