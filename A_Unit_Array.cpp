#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol ne = 0, o = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                o++;
            else
                ne++;
        }
        if (ne <= o)
        {
            cout << (ne % 2) << '\n';
        }
        else
        {
            lol v = ne - (n / 2);

            cout << v + ((n / 2) % 2) << '\n';
        }
    }
}