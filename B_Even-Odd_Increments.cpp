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
        lol cev = 0, cod = 0;
        lol sev = 0, sod = 0;
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
            {
                cod++;
                sod += a[i];
            }
            else
            {
                cev++;
                sev += a[i];
            }
        }
        while (q--)
        {
            lol ti, x;
            cin >> ti >> x;
            if (ti)
            {
                // to all odd
                sod += x * 1ll * cod;
                if (x % 2)
                {
                    cev += cod;
                    sev += sod;
                    sod = 0;
                    cod = 0;
                }
            }
            else
            {
                sev += x * 1ll * cev;
                if (x % 2)
                {
                    cod += cev;
                    sod += sev;
                    sev = 0;
                    cev = 0;
                }
            }
            cout << sev + sod << endl;
        }
    }

    return 0;
}