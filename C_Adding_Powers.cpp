#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, k;
        cin >> n >> k;
        lol c[80];
        for (lol i = 0; i < 80; i++)
        {
            c[i] = 0;
        }
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            lol j = 0;
            while (t > 0)
            {
                c[j] += t % k;
                t = t / k;
                j++;
            }
        }
        for (lol i = 0; i < 80; i++)
        {
            if (c[i] > 1)
            {
                f = false;
                break;
            }
        }

        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}