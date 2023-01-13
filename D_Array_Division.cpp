#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 2 != 0)
    {
        cout << "NO";
    }
    else
    {
        s /= 2;
        bool f = false;
        set<lol> x;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            x.insert(a[i]);
            c += a[i];
            if (c == s)
                f = true;
            else if (x.count(c - s))
            {
                f = true;
            }
        }
        x.clear();
        c = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            x.insert(a[i]);
            c += a[i];

            if (c == s)
                f = true;
            else if (x.count(c - s))
            {
                f = true;
            }
        }
        if (f)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}