#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
};
int main()
{
    node *head;
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;

    first = new node();
    second = new node();
    third = new node();

    first->val = 1;
    second->val = 2;
    third->val = 3;

    first->next = second;
    second->next = third;
    third->next = NULL;

    head = first;

    int x = 1826;
    node *nw = new node();
    nw->val = x;
    nw->next = head;
    head = nw;

    x = 1826;
    int target = 2;

    node *nya_node = new node();
    nya_node->val = x;
    node *ptr = head;

    while (ptr->val != target)
    {
        ptr = ptr->next;
    }

    node *temp = ptr->next;
    ptr->next = nya_node;
    nya_node->next = temp;

    target = 2;
    ptr = head;

    while (ptr->next->val != target)
    {
        ptr = ptr->next;
    }
    node *d = ptr->next;
    ptr->next = ptr->next->next;
    delete d;

    ptr = head;

    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    return 0;
}
