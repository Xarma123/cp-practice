#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool even(lol n, lol o);
bool odd(lol n, lol o);
map<pair<lol, lol>, bool> od;
map<pair<lol, lol>, bool> ev;

bool odd(lol n, lol o)
{
    if (od.count({n, o}))
        return od[{n, o}];
    if (n == 1)
        return o == 1;
    if (n - o > 0)
    {
        // n-1, o

        if (o % 2)
        {
            if (!odd(n - 1, o))
                return od[{n, o}] = true;
        }
        else
        {
            if (!even(n - 1, o))
                return od[{n, o}] = true;
        }
    }

    if (o)
    {

        if ((o - 1) % 2)
        {
            if (!even(n - 1, o - 1))
                return od[{n, o}] = true;
        }
        else
        {
            if (!odd(n - 1, o - 1))
                return od[{n, o}] = true;
        }
    }
    return od[{n, o}] = false;
}

bool even(lol n, lol o)
{
    if (ev.count({n, o}))
        return ev[{n, o}];
    if (n == 1)
        return o == 0;
    if (n - o > 0)
    {
        // n-1, o

        if (o % 2)
        {
            if (!even(n - 1, o))
                return ev[{n, o}] = true;
        }
        else
        {
            if (!odd(n - 1, o))
                return ev[{n, o}] = true;
        }
    }
    if (o)
    {
        // n-1,o-1
        if ((o - 1) % 2)
        {
            if (!odd(n - 1, o - 1))
                return ev[{n, o}] = true;
        }
        else
        {
            if (!even(n - 1, o - 1))
                return ev[{n, o}] = true;
        }
    }
    return ev[{n, o}] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol o = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                o++;
        }

        if (even(n, o))
        {
            cout << "Alice" << endl;
        }
        else
            cout << "Bob" << endl;
    }

    return 0;
}