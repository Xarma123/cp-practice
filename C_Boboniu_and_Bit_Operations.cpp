#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[n];
    lol b[m];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i <= powl(2, 9); i++)
    {
        bool q = true;
        for (lol j = 0; j < n; j++)
        {
            bool f = false;
            for (lol k = 0; k < m; k++)
            {
                if (((a[j] & b[k]) | i) == i)
                    f = true;
            }
            if (!f)
                q = false;
        }
        if (q)
        {
            cout << i;
            break;
        }
    }

    return 0;
}