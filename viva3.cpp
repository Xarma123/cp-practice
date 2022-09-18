#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Node
{

public:
    int val;
    Node *next;
    Node *prv;
    Node(int v)
    {
        val = v;
        next = NULL;
        prv = NULL;
    }
};
Node *create(int n)
{

    if (n <= 0)
        return NULL;
    cout << "Enter " << n << " Values" << endl;
    int v;
    cin >> v;
    Node *h = new Node(v);
    Node *c = h;
    n--;
    while (n--)
    {
        cin >> v;
        c->next = new Node(v);
        c->next->prv = c;
        c = c->next;
    }
    return h;
}
Node *del(Node *h)
{
    cout << "Enter value to Delete" << endl;

    lol v;
    cin >> v; 
    Node *c = h->next;
    if (h->val == v)
    {

        delete h;
        return c;
    }
    if (c != NULL)
    {
        while (c->val != v)
        {
            c = c->next;
            if (c == NULL)
                return h;
        }
    }
    c->prv->next = c->next;
    if (c->next != NULL)
        c->next->prv = c->prv;
    delete c;
    return h;
}
void disply(Node *h)
{
    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "Enter the no of Nodes to Add-:" << endl;
    lol n;
    cin >> n;
    Node *H = create(n);
    cout << "List ->" << endl;
    disply(H);
    cout << endl;

    H = del(H);
    cout << "List ->" << endl;
    disply(H);

    return 0;
}