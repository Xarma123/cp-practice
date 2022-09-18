#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        unordered_map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {

            cin >> a[i];
            mp[a[i]] = i;
        }
        lol b[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        lol t = 0;
        lol prv = -1;
        lol c = 0;
        for (lol i = 0; i < m; i++)
        {
            lol j = mp[b[i]];

            if (prv == -1)
            {
                t += 2 * (j - c) + 1;
                prv = j;
            }
            else
            {
                if (j < prv)
                {
                    t += 1;
                }
                else
                {
                    t += 2 * (j - c) + 1;
                    prv = j;
                }
            }
            c++;
        }
        cout << t << endl;
    }

    return 0;
}