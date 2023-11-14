#include <bits/stdc++.h>
using namespace std;
#define lol long long
class node
{
public:
    node *a[2];
    lol c;
    node()
    {
        a[0] = a[1] = NULL;
        c = 0;
    }
};

class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }
    void insert(lol a)
    {
        node *temp = root;
        for (lol i = 63; i >= 0; i--)
        {
            temp->c++;
            if ((a & (1ll << i)))
            {
                if (!temp->a[1])
                {
                    temp->a[1] = new node();
                }

                temp = temp->a[1];
            }
            else
            {
                if (!temp->a[0])
                {
                    temp->a[0] = new node();
                }
                temp = temp->a[0];
            }
        }
        temp->c++;
    }
    void remove(lol a)
    {
        node *temp = root;
        for (lol i = 63; i >= 0; i--)
        {
            temp->c--;
            if ((a & (1ll << i)))
            {
                temp = temp->a[1];
            }
            else
            {
                temp = temp->a[0];
            }
        }
        temp->c--;
    }
    lol search(lol a, lol l)
    {
        node *temp = root;
        lol ans = 0;
        for (lol i = 63; i >= 0; i--)
        {
            if (temp == NULL)
                break;
            if ((a & (1ll << i)))
            {
                if ((l & (1ll << i)))
                {
                    if (temp->a[1] != NULL)
                    {
                        ans += temp->a[1]->c;
                    }
                    temp = temp->a[0];
                }
                else
                {
                    temp = temp->a[1];
                }
            }
            else
            {
                if ((l & (1ll << i)))
                {
                    if (temp->a[0] != NULL)
                    {
                        ans += temp->a[0]->c;
                    }
                    temp = temp->a[1];
                }
                else
                {
                    temp = temp->a[0];
                }
            }
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    trie s;
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol p;
            cin >> p;
            s.insert(p);
        }
        else if (t == 2)
        {
            lol p;
            cin >> p;
            s.remove(p);
        }
        else
        {
            lol p, l;
            cin >> p >> l;
            cout << s.search(p, l) << endl;
        }
    }

    return 0;
}
