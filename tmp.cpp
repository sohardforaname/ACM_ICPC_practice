#include <stdio.h>
unsigned int data[10] = {
    0xff8181ff,
    0x181ff01,
    0x9f9191f1,
    0x919191ff,
    0xf8483f08,
    0xf989898f,
    0xff91919f,
    0x838cb0c0,
    0xff9999ff,
    0xf19191ff
};
unsigned int test[10] = {
    0xff8281ff,
    0x81ff01,
    0x9d5391f1,
    0x919393fd,
    0xb0493f08,
    0xd9a9898d,
    0xff85488f,
    0x8083acc0,
    0xff8989ff,
    0xfa8a89ff
};
int val[10];
int stat[10];
const unsigned int a[32] = {
    0x1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x1000000, 0x10000000,
    0x2, 0x20, 0x200, 0x2000, 0x20000, 0x200000, 0x2000000, 0x20000000,
    0x4, 0x40, 0x400, 0x4000, 0x40000, 0x400000, 0x4000000, 0x40000000,
    0x8, 0x80, 0x800, 0x8000, 0x80000, 0x800000, 0x8000000, 0x80000000
};

int res[10];

int main()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int v = data[j] ^ test[i];
            int tmp = 0;
            for (int k = 0; k < 32; ++k) {
                if (v & a[k]) {
                    tmp = tmp + 1;
                }
            }
            val[j] = (tmp << 16) + j;
        }
        for (int j = 0; j < 10; ++j) {
            int tmp = val[j];
            int k = j - 1;
            while (k >= 0 && val[k] > tmp) {
                val[k + 1] = val[k];
                --k;
            }
            val[k + 1] = tmp;
        }
        for (int j = 0; j < 10; ++j) {
            stat[j] = 0;
        }
        for (int j = 0; j < 1; ++j) {
            ++stat[val[j] & 0xffff];
        }
        int pos, maxn = 0;
        for (int j = 0; j < 10; ++j) {
            if (stat[j] > maxn) {
                pos = j;
                maxn = stat[j];
            }
        }
        res[i] = pos;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}