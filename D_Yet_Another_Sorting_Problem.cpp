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
        lol a[n], b[n];
        lol od = 0, ev = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
            if (a[i] % 2 == 0)
                ev++;
            else
                od++;
        }
        sort(b, b + n);
        bool f = true;
      
        for (lol i = 0; i < n; i++)
        {
            if (b[i] % 2 != a[i] % 2)
            {
                f = false;
                break;
            } 

            if (od < 3)
            {
                if (a[i] % 2 != 0)
                {
                    if (a[i] != b[i])
                    {
                        f = false;
                        break;
                    }
                }
            }
            if (ev < 3)
            {
                if (a[i] % 2 == 0)
                {
                    if (a[i] != b[i])
                    {
                        f = false;
                        break;
                    }
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}