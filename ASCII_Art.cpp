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
    for (lol qqqw = 1; qqqw <= t; qqqw++)
    {
        cout << "Case #" << qqqw << ": ";
        lol n;
        cin >> n;
        lol st = 0, e = 1e7;
        while (st != e - 1)
        {
            lol m = (st + e) / 2;
            if (13ll * m * 1ll * (m + 1) < n)
                st = m;
            else
                e = m;
        }
        n -= 13ll * st * 1ll * (st + 1);
        st++;
        lol k = n / st;
        n -= k * st;
        if (n == 0)
        {
            cout << char('A' + k - 1);
        }
        else
        {
            k++;
            cout << char('A' + k - 1);
        }
        cout << '\n';
    }

    return 0;
}