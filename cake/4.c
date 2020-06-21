#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num, age;
    char name[10];
    struct node *next;
};
void create(struct node *head, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        scanf("%d%s%d", new->num, new->name, new->age);
        new->next = head->next;
        head->next = new;
    }
}