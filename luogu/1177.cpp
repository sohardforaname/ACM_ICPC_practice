#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int a[100005];
int n;
void quicksort(int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	swap(a[m],a[l]);
	int left = l, right = r;
	int key = l;
	while(left < right)
	{
		while(left < right && a[right] >= a[key])
			--right;
		while(left < right && a[left] <= a[key])
			++left;	
		//if(left < right)
		swap(a[left], a[right]);
	}
	swap(a[key], a[left]);
	quicksort(l, left - 1);
	quicksort(left + 1, r);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//int n;
	//cin >> n;
	srand(time(NULL));
	n = rand()%100005;
	for (int i = 0; i < n; ++i)
		//cin >> a[i];
		a[i] = rand();
	quicksort(0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
		if (i < n - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}

/*#include <iostream>
using namespace std;
int a[100005];
int tmp[100005];
void merge(int l, int m, int r)
{
	int i = l, j = m + 1, pos = 0;
	while (i <= m && j <= r)
	{
		if (a[i] <= a[j])
			tmp[pos++] = a[i++];
		else if (a[i] > a[j])
			tmp[pos++] = a[j++];
	}
	while (i <= m)
		tmp[pos++] = a[i++];
	while (j <= r)
		tmp[pos++] = a[j++];
	for (int i = 0; i < pos; ++i)
		a[l+i] = tmp[i];
	return;
}
void sort(int l, int r)
{
	int m = (l + r) / 2;
	if (l != r)
	{
		sort(l, m);
		sort(m + 1, r);
	}
	merge(l, m, r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
		if (i < n - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}*/
