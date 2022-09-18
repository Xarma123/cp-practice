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

        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0)
                continue;
            while (1)
            {
                bool f = true;

                lol x = i - 1;
                if (x >= 0)
                {
                    while (a[i] == a[x] || a[x] == 0)
                    {
                        if (a[x] != 0)
                        {
                            a[i]++;
                            f = false;
                        }
                        a[x] = 0;
                        x--;
                        if (x == n)
                            break;
                    }
                }
                x = i + 1;
                if (x < n)
                {
                    while (a[i] == a[x] || a[x] == 0)
                    {

                        if (a[x] != 0)
                        {
                            a[i]++;
                            f = false;
                        }
                        a[x] = 0;
                        x++;
                        if (x == n)
                            break;
                    }
                }
                if (f)
                    break;
            }
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}