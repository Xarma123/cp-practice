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
void insertathead(lol data, node *&head)
{
    node *n = new node(data);
    n->next = head;
    head = n;
}
void insertatp(node *head, lol data, lol p)
{
    if (p != 0)
    {
        p -= 1;
        while ((p)--)
        {
            head = head->next;
        }
        node *a = new node(data);
        a->next = head->next;
        head->next = a;
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

void deleteatp(node *&head, lol p)
{
    node *t = head, *prv;
    while (p--)
    {
        prv = t;
        t = t->next;
    }
    prv->next = t->next;
    delete t;
}
void deleteathead(node *&head)
{
    node *t = head->next;
    delete head;
    head = t;
}
lol search(node *&head, lol data, lol c)
{
    node *t = head;
    if (t->data == data)
        return c;
    else if (t->next == NULL)
    {
        return -1;
    }
    else
    {
        search(t->next, data, c + 1);
    }
}
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
void reverse(node *&head)
{
    node *cur, *pre;
    cur = head;
    pre = NULL;
    while (cur != NULL)
    {
        node *t = cur;

        cur = cur->next;
        t->next = pre;
        pre = t;
    }

    head = pre;
}
void rec(node *&head, node *cur, node *pre)
{
    if (cur == NULL)
    {
        head = pre;
        return;
    }
    node *t = cur->next;
    cur->next = pre;
    rec(head, t, cur);
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
    node *head = NULL;
    node *head2 = NULL;

    // insertathead(5, head);
    // insertathead(4, head);
    // insertathead(3, head);
    // insertathead(2, head);
    // insertathead(1, head);
    //  insertathead(0, head);
    // // insertatp(head, 98, 3);
    // // deleteathead(head);
    // // deleteatp(head, 2);

    // lol x = search(head, 2,0);
    // cout <<endl<< x;
    build(head);
    // build(head2);
    // rec(head,head,NULL);

    // cin >> k;
    // node *a = knode(head, k);
    // cout << a->data;

    // cout<<head;
    build(head2);
    head = merge(head, head2);
    prlol(head);
}