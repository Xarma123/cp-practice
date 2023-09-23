#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(lol a, lol b)
{
    if (a % 2 == 0)
        return 0;
    if (a % 4 == 3)
    {
        if (b % 2 == 0)
            return -1;
        return 1;
    }
    return 1;
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol w = 0;
        for (lol j = 31; j >= 0; j--)
        {
            lol o = 0;
            for (lol i = 0; i < n; i++)
            {
                if ((a[i] & (1ll << j)))
                    o++;
            }
            lol c = solve(o, n - o);
            if (c != 0)
            {
                w = c;
                break;
            }
        }
        if (w == -1)
            cout << "LOSE\n";
        else if (w == 0)
            cout << "DRAW\n";
        else
            cout << "WIN\n";
    }
}