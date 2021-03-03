#include "base.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define ll long long
#define MOD 1000000007
#define MAXN 1005
using namespace std;

ll X[MAXN], Y[MAXN], Z[MAXN];

void add(int L, int R, int a, int b, int c)
{
    for (int i = L; i <= R; ++i) {
        X[i] = (X[i] + a) % MOD;
        Y[i] = (Y[i] + b) % MOD;
        Z[i] = (Z[i] + c) % MOD;
    }
}

void muil(int L, int R, int k)
{
    for (int i = L; i <= R; ++i) {
        X[i] = X[i] * k % MOD;
        Y[i] = Y[i] * k % MOD;
        Z[i] = Z[i] * k % MOD;
    }
}

void turn(int L, int R)
{
    for (int i = L; i <= R; ++i) {
        int tmp = X[i];
        X[i] = Y[i];
        Y[i] = Z[i];
        Z[i] = tmp;
    }
}

void query(int L, int R)
{
    ll dist;
    ll x = 0, y = 0, z = 0;
    for (int i = L; i <= R; ++i) {
        x = (x + X[i]) % MOD;
        y = (y + Y[i]) % MOD;
        z = (z + Z[i]) % MOD;
    }
    printf("%lld\n", (x * x % MOD + y * y % MOD + z * z % MOD) % MOD);
}

int main()
{
    int N, M;
    int m, l, r, a, b, c;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &m);
        if (m == 1) {
            scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
            add(l, r, a, b, c);
        } else if (m == 2) {
            scanf("%d%d%d", &l, &r, &a);
            muil(l, r, a);
        } else if (m == 3) {
            scanf("%d%d", &l, &r);
            turn(l, r);
        } else {
            scanf("%d%d", &l, &r);
            query(l, r);
        }
    }
    string s = "abc";
}
