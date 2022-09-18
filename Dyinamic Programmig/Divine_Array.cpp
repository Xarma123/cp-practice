#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], f[n + 1];
        memset(f, 0, sizeof(f));

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        lol q;
        cin >> q;
        map<lol, vector<lol>> map;
        while (q--)
        {

            lol x, b;
            cin >> x >> b;
            if (map.find(b) == map.end())
            {
                lol t[n];
                lol ft[n + 1];
                for (lol i = 0; i < n; i++)
                {
                    t[i] = a[i];
                    ft[i] = f[i];
                }
                ft[n] = f[n];

                for (lol j = 0; j < b; j++)
                {
                    if (j <=  sqrt(n)+2)
                    {
                        for (lol k = 0; k < n; k++)
                            t[k] = ft[t[k]];

                        memset(ft, 0, sizeof(ft));
                        for (lol k = 0; k < n; k++)
                            ft[t[k]]++;
                    }
                    else
                        break;
                }
                for (lol i = 0; i < n; i++)
                {
                    map[b].push_back(t[i]);
                }
            }

            cout << map[b][x - 1] << endl;
        }
    }

    return 0;
}