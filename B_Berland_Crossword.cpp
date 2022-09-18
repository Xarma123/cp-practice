#include <bits/stdc++.h>
#define lol long long

using namespace std;
int main()
{

    lol t;
    cin >> t;

    while (t--)
    {
        lol n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool k = true;
        if (u == n - 1)
        {
            if (d == n - 1)
                k &= (l + r) > 1;
            else if (d == n)
                k &= (l + r) > 2 && l > 0 && r > 0;
            else
                k &= (l + r) > 0;
        }
        else if (u == n)
        {
            if (d == n - 1)
                k &= (l + r) > 2 && l > 0 && r > 0;
            else if (d == n)
                k &= l > 1 && r > 1;
            else
                k &= l > 0 && r > 0;
        }
        else if (d == n)
        {
            k &= l > 0 && r > 0;
        }
        else if (d == n - 1)
            k &= l > 0 || r > 0;

        if (l == n - 1)
        {
            if (r == n - 1)
                k &= (u + d) > 1;
            else if (r == n)
                k &= (d + u) > 2 && u > 0 && d > 0;
            else
                k &= (u + d) > 0;
        }
        else if (l == n)
        {
            if (r == n - 1)
                k &= (u + d) > 2 && d > 0 && u > 0;
            else if (r == n)
                k &= u > 1 && d > 1;
            else
                k &= d > 0 && u > 0;
        }
        else if (r == n)
        {
            k &= u > 0 && d > 0;
        }
        else if (r == n - 1)
            k &= u > 0 || d > 0;
        cout << (k ? "YES" : "NO") << endl;
    }
}