#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num, age;
    char name[10];
    struct node *next;
};
void delete (struct node *head, int z)
{
    int i;
    struct node *pre = head;
    head = head->next;
    struct node *ptr = head;
    while (head)
    {
        if (head->age == z)
        {
            struct node *p = head;
            head = head->next;
            pre->next = head;
            free(p);
        }
        else
        {
            head = head->next;
            pre = pre->next;
        }
    }
    FILE *fp = fopen("test.txt", "w");
    if (!fp)
        return;
    while (head)
    {
        fprintf("%d %s %d\n", head->num, head->name, head->age);
        head = head->next;
    }
    fclose(fp);
}