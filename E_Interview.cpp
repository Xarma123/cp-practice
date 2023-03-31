#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            p[i] = a[i];
            if (i)
                p[i] += p[i - 1];
        }
        lol st = -1, e = n - 1;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
            {
                st = -1;
            }
            else
            {
                cout << "? " << md + 1 << ' ';
                for (lol i = 0; i <= md; i++)
                {
                    cout << i + 1 << " ";
                }
                cout << endl;
                lol x;
                cin >> x;
                if (x != p[md])
                {
                    e = md;
                }
                else
                    st = md;
            }
        }
        cout << "! " << e + 1 << endl;
    }

    return 0;
}