#include <bits/stdc++.h>
using namespace std;
#define lol long long
class node
{
public:
    node *a[2];
    node()
    {
        a[0] = a[1] = nullptr;
    }
};
class trie
{
public:
    node *st;
    trie()
    {
        st = new node();
    }
    void insert(lol a)
    {
        node *temp = st;
        for (lol i = 63; i >= 0; i--)
        {
            if ((a & (1ll << i)))
            {
                if (temp->a[1] == nullptr)
                {
                    temp->a[1] = new node();
                }
                temp = temp->a[1];
            }
            else
            {
                if (temp->a[0] == nullptr)
                {
                    temp->a[0] = new node();
                }
                temp = temp->a[0];
            }
        }
    }
    lol search(lol a)
    {
        node *temp = st;
        lol r = 0;
        for (lol i = 63; i >= 0; i--)
        {
            if ((a & (1ll << i)))
            {
                if (temp->a[0] == nullptr)
                {
                    temp = temp->a[1];
                }
                else
                {
                    r |= (1ll << i);
                    temp = temp->a[0];
                }
            }
            else
            {
                if (temp->a[1] == nullptr)
                {
                    temp = temp->a[0];
                }
                else
                {
                    r |= (1ll << i);
                    temp = temp->a[1];
                }
            }
        }
        return r;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n - 1];
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    for (lol i = 1; i < n - 1; i++)
    {
        a[i] ^= a[i - 1];
    }
    trie s;
    for (lol i = 0; i < n - 1; i++)
    {
        s.insert(a[i]);
    }
    for (lol i = 0; i < n; i++)
    {
        if (s.search(i) <= n - 1)
        {
            cout << i << " ";
            for (lol j = 0; j < n - 1; j++)
            {
                cout << (i ^ (a[j])) << ' ';
            }
            break;
        }
    }

    return 0;
}
