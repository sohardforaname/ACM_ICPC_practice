#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct unit
{
	int a, squ;
	unit* next;
};
unit* push_back(unit data,unit *head)
{
	unit *tmp = new unit, *p = head;
	*tmp = data;
	if (p == NULL)
	{
		head = tmp;
		return head;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	return head;
}
unit* insert(unit *head, unit data)
{
	unit *tmp = new unit, *p = head, *pre = NULL;
	*tmp = data;
	if (p == NULL)
	{
		head = tmp;
		return head;
	}
	else
	{
		while (p != NULL && p->squ> data.squ)
			pre = p, p = p->next;
		if (pre == NULL)
			head = tmp, head->next = p;
		else if (p && p->squ == data.squ)
			p->a += data.a;
		else
			pre->next = tmp, tmp->next = p;
	}
	return head;
}
void del(unit *head)
{
	unit *pre;
	while (head != NULL)
	{
		pre = head;
		head = head->next;
		delete pre;
	}
}
int main()
{
	unit *l_1 = NULL, *l_2 = NULL, tmp;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp.a >> tmp.squ, tmp.next = NULL;
		l_1 = push_back(tmp, l_1);
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> tmp.a >> tmp.squ, tmp.next = NULL;
		l_2 = push_back(tmp, l_2);
	}
	unit *l_3 = NULL, *pp = l_1;
	while (pp != NULL)
	{
		unit *p = l_2, res;
		while (p != NULL)
		{
			res.a = pp->a*p->a;
			res.squ = pp->squ + p->squ;
			res.next = NULL;
			l_3 = insert(l_3, res);
			p = p->next;
		}
		pp = pp->next;
	}
	unit *p = l_3;
	bool f = false;
	while (p != NULL)
	{
		if (p->a)
		{
			if (f)
				cout << " ";
			f = 1;
			cout << p->a << " " << p->squ;
		}
		p = p->next;
	}
	if (!f)
		cout << 0 << " " << 0;
	cout << endl;
	del(l_3);
	l_3 = NULL;
	unit *p1 = l_1, *p2 = l_2;
	unit res;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->squ == p2->squ)
		{
			res.a = p1->a + p2->a;
			res.squ = p1->squ;
			p1 = p1->next, p2 = p2->next;
		}
		else if (p1->squ > p2->squ)
		{
			res.a = p1->a;
			res.squ = p1->squ;
			p1 = p1->next;
		}
		else
		{
			res.a = p2->a;
			res.squ = p2->squ;
			p2 = p2->next;
		}
		res.next = NULL;
		l_3 = insert(l_3, res);
	}
	if (p1)
		l_3 = insert(l_3, *p1);
	else if (p2)
		l_3 = insert(l_3, *p2);
	p = l_3;
	f = false;
	while (p != NULL)
	{
		if (p->a)
		{
			if(f)
				cout << " ";
			f = 1;
			cout << p->a << " " << p->squ;
		}
		p = p->next;
	}
	if (!f)
		cout << 0 << " " << 0;
	cout << endl;
	del(l_3);
	l_3 = NULL;
	return 0;
}