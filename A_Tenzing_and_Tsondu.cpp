#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n], b[m];
        lol x = 0, y = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x += a[i];
        }
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
            y += b[i];
        }
        if (x > y)
            cout << "Tsondu\n";
        else if (x < y)
            cout << "Tenzing\n";
        else
            cout << "Draw\n";
    }
}