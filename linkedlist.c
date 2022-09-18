#include <stdio.h>
#include <malloc.h>
#include <conio.h>
struct linklist
{
    lol item;
    struct linklist *list;
} s1;
void add(lol);
void display();
void addend(lol);
void addloc(lol, lol);
struct linklist *p;
int main()
{
    p = NULL;
    lol d, n;
    scanf("%d ", &n);
    for (lol i = 0; i < n; i++)
    {
        scanf("%d", &d);
        add(d);
    }
    addend(12);
    addloc(0, 2);
    display();
    getch();
}
void add(lol ite)
{
    struct linklist *q = (struct linklist *)malloc(sizeof(struct linklist));
    q->item = ite;
    q->list = p;
    p = q;
}
void display()
{
    struct linklist *q = p;
    while (q != NULL)
    {
        prlolf("%d \n", q->item);
        q = q->list;
    }
}

void addend(lol i)
{
    struct linklist *q = (struct linklist *)malloc(sizeof(struct linklist));
    q->item = i;
    q->list = NULL;
    struct linklist *l = p;
    while (l->list != NULL)
    {
        l = l->list;
    }
    l->list = q;
}
void addloc(lol k, lol l)
{
    struct linklist *q = p;
    lol i = 1;
    while (i != l - 1)
    {
        i++;
        q = q->list;
    }

    struct linklist *x = (struct linklist *)malloc(sizeof(struct linklist));
    x->item = k;
    x->list = q->list;
    q->list = x;
}