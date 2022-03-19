int a[N][N];
int cnt1, cnt2;
int n;

void set1()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!a[i][j] && (i + j) % 2) {
                a[i][j] = 1;
                ++cnt1;
                cout << 1 << " " << i << " " << j << endl;
                return;
            }
        }
    }
}

void set2()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!a[i][j] && (i + j) % 2 == 0) {
                a[i][j] = 2;
                ++cnt2;
                cout << 2 << " " << i << " " << j << endl;
                return;
            }
        }
    }
}

void set3()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!a[i][j] && (i + j) % 2) {
                a[i][j] = 3;
                cout << 3 << " " << i << " " << j << endl;
                return;
            }
        }
    }
}

void solve()
{
    cin >> n;
    int t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            if (t == 1) {
                if (cnt2 < (n * n) / 2) {
                    set2();
                } else {
                    set3();
                }
            } else if (t == 2) {
                if (cnt1 < (n * n) / 2) {
                    set1();
                } else {
                    set3();
                }
            } else {
                if (cnt1 < (n * n) / 2) {
                    set1();
                } else if (cnt2 < (n * n) / 2) {
                    set2();
                }
            }
        }
    }
}