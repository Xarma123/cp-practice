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
struct linklist *p;
int main()
{
    p = NULL;
    lol d, n;
    scanf("%d ", n);
    for (lol i = 0; i < n; i++)
    {
        scanf("%d", d);
        add(d);
    }
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
    struct linklist * q = p;
    while (q != NULL)
    {
        prlolf("%d \n", q->item);
        q = q->list;
    }
}