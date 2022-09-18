#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol s = 1;
    lol e = 1e9;
    while (s != e - 1)
    {
        lol md = (s + e) / 2;
        if ((md) * (md + 1) / 2 <= m)
            s = md;
        else
            e = md;
    }

    if ((a[0] - 1) * (a[0]) / 2 >= m)
    {
        cout << s << endl;
        for (lol i = 1; i <= s; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        lol sum = (a[0] - 1) * (a[0]) / 2;
        lol prv = a[0];
        lol i;
        for (i = 1; i < n; i++)
        {
            if (sum + (a[i] - 1) * (a[i]) / 2 - (prv) * (prv + 1) / 2 >= m)
            {
                s = prv;
                e = a[i] - 1;
                while (s != e - 1)
                {
                    lol md = (s + e) / 2;
                    if (sum + (md + 1) * (md) / 2 - (prv) * (prv + 1) / 2 <= m)
                    {
                        s = md;
                    }
                    else
                        e = md;
                }
                break;
            }
            else
            {
                sum += (a[i] - 1) * (a[i]) / 2 - (prv) * (prv + 1) / 2;
            }
            prv = a[i];
        }
        if (i < n)
        {
            cout << s - (i) << endl;
            lol polol = 0;
            for (i = 1; i <= s; i++)
            {
                if (polol < n)
                {
                    if (a[polol] == i)
                        polol++;
                    else
                        cout << i << " ";
                }
                else
                    cout << i << " ";
            }
        }
        else
        {
            s = a[n - 1];
            e = 1e9;
            while (s != e - 1)
            {
                lol md = (s + e) / 2;
                if ((md) * (md + 1) / 2 - (a[n - 1]) * (a[n - 1] + 1) / 2 + sum <= m)
                    s = md;
                else
                    e = md;
            }

            cout << s - (i) << endl;
            lol polol = 0;
            for (i = 1; i <= s; i++)
            {
                if (polol < n)
                {
                    if (a[polol] == i)
                        polol++;
                    else
                        cout << i << " ";
                }
                else
                    cout << i << " ";
            }
        }
    }

    return 0;
}