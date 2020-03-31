//接受多组
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> complexd;
const ll maxn = 3e6 + 20;
const double PI = acos(-1.0);
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须取2的幂
 */
void change(complexd* y, int len)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
            j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complexd* y, int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        complexd wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            complexd w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                complexd u = y[k];
                complexd t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
        for (int i = 0; i < len; i++)
            y[i] = complexd(y[i].real() / len, y[i].imag());
}

char num1[maxn], num2[maxn];
complexd x1[maxn], x2[maxn];
int ans[maxn];

int main()
{
    while (scanf("%s%s", num1, num2) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        int len = 1, len1 = strlen(num1), len2 = strlen(num2);
        while (len < len1 + len2 + 1)
            len <<= 1;
        for (int i = 0; i < len1; i++)
            x1[len1 - 1 - i] = complexd((double)(num1[i] - '0'), 0);
        for (int i = len1; i < len; i++)
            x1[i] = complexd(0, 0);
        fft(x1, len, 1);
        for (int i = 0; i < len2; i++)
            x2[len2 - 1 - i] = complexd((double)(num2[i] - '0'), 0);
        for (int i = len2; i < len; i++)
            x2[i] = complexd(0, 0);
        fft(x2, len, 1);
        for (int i = 0; i < len; i++)
            x1[i] = x1[i] * x2[i];
        fft(x1, len, -1);
        for (int i = 0; i < len; i++)
            ans[i] = (int)(x1[i].real() + 0.5);
        for (int i = 1; i < len; i++)
        {
            ans[i] += ans[i - 1] / 10;
            ans[i - 1] %= 10;
        }
        while (len > 0 && !ans[len])
            len--;
        for (int i = len; i >= 0; i--)
            printf("%c", ans[i] + '0');
        puts("");
    }
    return 0;
}