#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol s = 0;
    lol z = 0;
    for (lol i = 0; i < n; i++)
    {
        s += a[i];
        cin >> a[i];
        if (a[i] == 0)
            z++;
    }
    sort(a, a + n);
    vector<lol> o;
    vector<lol> t;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] % 3 == 1)
        {
            if (o.size() < 2)
                o.push_back(i);
        }
        if (a[i] % 3 == 2)
        {
            if (t.size() < 2)
                t.push_back(i);
        }
    }
    if (z == 0)
        cout << -1;
    else
    {
        if (s % 3 == 0)
        {
            for (lol i = n - 1; i >= 0; i--)
            {
                cout << a[i];
            }
        }
        else if (s % 3 == 2)
        {
            if (t.size() != 0)
            {
                for (lol i = n - 1; i >= 0; i--)
                {
                    if (i != t[0])
                        cout << a[i];
                }
            }
            else if (o.size() > 1)
            {
                for (lol i = n - 1; i >= 0; i--)
                {
                    if (i != o[0] && i != o[1])
                        cout << a[i];
                }
            }
            else
                cout << -1;
        }
        else
        {
            if (o.size() != 0)
            {
                for (lol i = n - 1; i >= 0; i--)
                {
                    if (i != o[0])
                        cout << a[i];
                }
            }
            else if (t.size() > 1)
            {
                for (lol i = n - 1; i >= 0; i--)
                {
                    if (i != t[0] && i != t[1])
                        cout << a[i];
                }
            }
            else
                cout << -1;
        }
    }

    return 0;
}