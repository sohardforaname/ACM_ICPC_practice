#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node {
	int vertex;
	struct node* next;
}Node;
void draw(int c[], Node* a[], int u, int ban1, int ban2);  //对root的邻接点着色，不能涂ban1和ban2
int max = 0;
int main(void)
{
	int n, i, u, v;
	while (scanf("%d", &n) != EOF)
	{

		max = 0;
		Node* a[n + 1];
		int color[n + 1];
		for (i = 1; i <= n; i++)
		{
			color[i] = 0;
			a[i] = (Node*)malloc(sizeof(Node));
			a[i]->vertex = 0;
			a[i]->next = NULL;
		}
		for (i = 1; i < n; i++)
		{
			scanf("%d %d", &u, &v);
			Node* p, * pnew = (Node*)malloc(sizeof(Node));
			for (p = a[u]; p->next; p = p->next)
				;
			pnew->vertex = v;
			pnew->next = p->next;
			p->next = pnew;

			Node* pnew2 = (Node*)malloc(sizeof(Node));
			for (p = a[v]; p->next; p = p->next)
				;
			pnew2->vertex = u;
			pnew2->next = p->next;
			p->next = pnew2;
		}
		color[1] = 1;
		draw(color, a, 1, 0, 1);
		printf("%d\n", max);
		for (i = 1; i < n; i++)
			printf("%d ", color[i]);
		printf("%d\n", color[n]);
	}
	return 0;
}

void draw(int c[], Node* a[], int u, int ban1, int ban2)
{
	int i;
	Node* p;
	for (i = 1, p = a[u]->next; p; p = p->next)
	{
		if (c[p->vertex])
			continue;
		if (i == ban1) i++;
		if (i == ban2) i++;
		c[p->vertex] = i;
		if (i > max)
			max = i;
		draw(c, a, p->vertex, ban2, i);
		i++;
	}
}