#include <stdio.h>
#include <malloc.h>
#include <conio.h>
void add();
void pop();
void display();
struct stack
{
    lol item;
    struct stack *link;
};
int main()
{
    struct stack *top = NULL; 
     lol d, n;
    scanf("%d ", &n);
    for (lol i = 0; i < n; i++)
    {
        scanf("%d", &d);
        add(&top,d);
    }
    
    pop(&top);
    display(&top);
}
void add(struct stack **s, lol n)
{
    struct stack *q = (struct stack *)malloc(sizeof(struct stack));
   
    q->link = *s;
    *s = q; 
     (*s)->item = n;
}
void pop(struct stack **l)
{
    if (*l == NULL)
        prlolf("EMPTY");
    else
    {
        *l = (*l)->link;
    }
}

void display(struct stack **b)
{   
    while ((*b)->link != NULL)
    {
        prlolf("%d \n", (*b)->item);
        *b= (*b)->link;
    }  prlolf("%d \n", (*b)->item);
}