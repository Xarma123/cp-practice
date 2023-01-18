#include <bits/stdc++.h>
#define lol long long
using namespace std;
//a
int main()
{
    lol n;
    cin >> n;
    lol a[n];

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1 || n == 2)
        cout << n << endl;
    else
    {

        bool c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i] = false;
        }

        for (lol i = 2; i < n; i++)
        {
            if (a[i] == a[i - 1] + a[i - 2])
            {
                c[i] = true;
            }
        }
        lol ans = 2;
        for (lol i = 0; i < n; i++)
        {
            lol c1 = 0;
            while (c[i])
            {
                c1++;
                i++;
                if (i == n)
                    break;
            }
            ans = max(ans, c1 + 2ll);
        }
        cout << ans;
    }
    return 0;
}