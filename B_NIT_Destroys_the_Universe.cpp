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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool z = true;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                z = false;
            }
        }
        if (z)
            cout << 0 << endl;
        else
        {
            bool f1 = true;
            lol l, r;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] != 0)
                {
                    l = i;
                    break;
                }
            }
            for (lol i = n - 1; i >= 0; i--)
            {
                if (a[i] != 0)
                {
                    r = i;
                    break;
                }
            }
            for (lol i = l; i <= r; i++)
            {
                if (a[i] == 0)
                {
                    f1 = false;
                    break;
                }
            }
            if (f1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}