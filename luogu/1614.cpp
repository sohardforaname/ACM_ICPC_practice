// P3626.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[3005];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	long long now = 0;
	for (int i = 0; i < m; ++i)
		now += a[i];
	long long minn = now;
	for (int i = m; i < n; ++i)
	{
		now -= a[i - m];
		now += a[i];
		if (now < minn)
			minn = now;
	}
	printf("%lld\n", minn);
	return 0;
}