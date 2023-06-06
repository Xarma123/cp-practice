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
        lol p[n];
        lol o, t, h;
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == 1ll)
                o = i;
            else if (p[i] == 2ll)
                t = i;
            else if (p[i] == n)
                h = i;
        }
        if (abs(t - o) != 1)
        {
            if (t < o)
            {
                cout << h + 1 << " " << t + 2 << '\n';
            }
            else
            {
                cout << h + 1 << " " << o + 2 << '\n';
            }
        }
        else
        {
            if (h < min(t, o))
                cout << h + 1 << " " << min(t, o) + 1 << '\n';
            else if (h > max(t, o))
            {
                cout << h + 1 << " " << max(t, o) + 1 << '\n';
            }
            else
                cout << h + 1 << " " << h + 1 << '\n';
        }
    }
}