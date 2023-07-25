#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        bool ans = false;
        lol a[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        lol tot = 0;
        bool f = false;
        for (lol i = 0; i < k; i++)
        {
            if ((a[i] / n) > 1)
            {
                tot += a[i] / n;
            }
            if ((a[i] / n) > 2)
            {
                f = true;
            }
        }

        if (m == 1)
        {
            for (lol i = 0; i < k; i++)
            {
                if (a[i] >= n)
                    ans = true;
            }
        }
        else if ((m % 2 == 0 || f) && tot >= m)
        {
            ans = true;
        }

        swap(n, m);
        tot = 0;
        f = false;
        for (lol i = 0; i < k; i++)
        {
            if ((a[i] / n) > 1)
            {
                tot += a[i] / n;
            }
            if ((a[i] / n) > 2)
            {
                f = true;
            }
        }

        if (m == 1)
        {
            for (lol i = 0; i < k; i++)
            {
                if (a[i] >= n)
                    ans = true;
            }
        }
        else if ((m % 2 == 0 || f) && tot >= m)
        {
            ans = true;
        }

        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}