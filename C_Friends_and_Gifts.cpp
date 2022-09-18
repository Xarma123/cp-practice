#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    set<lol> x;
    for (lol i = 0; i < n; i++)
    {
        x.insert(i + 1);
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        if (x.count(a[i]))
            x.erase(a[i]);
    }

    for (lol i = 0; i < n; i++)
    {
        if (a[i] == 0 && x.count((i + 1)))
        {
            auto it = x.begin();
            while ((*it) == i + 1)
                it++;
            a[i] = (*it);
            x.erase(a[i]);
        }
    }
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            auto it = x.begin();
            a[i] = (*it);
            x.erase(a[i]);
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}