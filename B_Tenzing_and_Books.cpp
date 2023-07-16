#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n], b[n], c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol aa = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v = aa | a[i];
            if ((v & x) != v)
            {
                break;
            }
            else
                aa = v;
        }
        lol bb = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v = bb | b[i];
            if ((v & x) != v)
            {
                break;
            }
            else
                bb = v;
        }
        lol cc = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v = cc | c[i];
            if ((v & x) != v)
            {
                break;
            }
            else
                cc = v;
        }
        if (((aa | bb) | cc) == x)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}