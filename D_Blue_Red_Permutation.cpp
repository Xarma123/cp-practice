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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string c;
        cin >> c;
        lol cr = 0, cb = 0, maxb = INT_MIN, minr = INT_MAX,
            minb = INT_MAX, maxr = INT_MIN;
        for (lol i = 0; i < n; i++)
        {
            if (c[i] == 'B')
            {
                cb++;
                maxb = max(maxb, a[i]);
                minb = min(minb, a[i]);
            }
            else
            {
                cr++;
                minr = min(minr, a[i]);
                maxr = max(maxr, a[i]);
            }
        }
      
        if (cr == 0)
        {
            if (maxb >= n)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        else if (cb == 0)
        {
            if (minr > 1)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else
        {
            if (maxr <= n && minb >= 1)
            {
                if (minr > maxb)
                {
                    cout << "NO" << endl;
                }
                else
                    cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}