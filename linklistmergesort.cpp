#include <iostream>
using namespace std;
class node
{
public:
    lol data;
    node *next;
    // constructor
    node(lol d)
    {
        data = d;
        next = NULL;
    }
}; 
void insertattail(node *&head, lol data)
{
    if (head == NULL)
    {
        node *a = new node(data);
        head = a;
    }
    else
    {
        node *t;
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        node *a = new node(data);
        t->next = a;
    }
}
void prlol(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void build(node *&head)
{
    lol data;
    cin >> data;
    while (data != -1)
    {
        insertattail(head, data);
        cin >> data;
    }
    return;
}

node *mnode(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *a = head->next;
    node *b = head;

    while (a->next != NULL && a != NULL)
    {
        a = a->next->next;
        b = b->next;
    }
    return b;
}

node *merge(node *head, node *head2)
{
    if (head == NULL)
        return head2;
    else if (head2 == NULL)
        return head;

    node *c;
    if (head->data < head2->data)
    {
        c = head;
        c->next = merge(head->next, head2);
    }
    else
    {
        c = head2;
        c->next = merge(head, head2->next);
    }
    return c;
}
node *mergesort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *m = mnode(head);
    node *a = head;
    node *b = m->next;
    m->next = NULL;
    a = mergesort(a);
    b = mergesort(b);
    node *c = merge(a, b);
    return c;
}
int main()
{



    node * a= NULL;
    build(a);
    a=mergesort(a);
    prlol(a);
}