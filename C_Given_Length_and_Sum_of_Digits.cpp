#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m, s;
    cin >> m >> s;
    if (s == 0)
    {
        if (m == 1)
            cout << 0 << " " << 0;
        else
            cout << -1 << " " << -1;
    }
    else
    {
        lol a[m], b[m];
        lol S = s;
        for (lol i = 0; i < m; i++)
        {
            if (S >= 9)
            {
                a[i] = 9;
                S -= 9;
            }
            else
            {
                a[i] = S;
                S = 0;
            }
        }
        S = s;
        S--;
        for (lol i = m - 1; i >= 0; i--)
        {
            if (S >= 9)
            {
                b[i] = 9;
                S -= 9;
            }
            else
            {
                b[i] = S;
                S = 0;
            }
        }
        b[0]++;
        bool f = true;
        for (lol i = 0; i < m; i++)
        {
            if (a[i] > 9 || b[i] > 9)
                f = false;
        }
        if (f)
        {
            for (lol i = 0; i < m; i++)
            {
                cout << b[i];
            }
            cout << " ";
            for (lol i = 0; i < m; i++)
            {
                cout << a[i];
            }
        }
        else
            cout << -1 << " " << -1;
    }

    return 0;
}