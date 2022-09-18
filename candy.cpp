#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol x[n];
    lol p = n;
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i];
        if (x[i] >= 0 && p == n)
            p = i;
    }

    lol ans = INT_MAX;

    for (lol i = p - 1; i >= 0; i--)
    {
        if (p == n)
        {
            ans = min(ans, x[n - k]);
            break;
        }
        else if (x[p] == 0)
        {
            if (p - i == k)
            {
                break;
            }
            else
            {
                lol s = -x[i];
                lol r = k - 1 - (p - i);
                if (r > 0)
                {
                    s += -x[i];
                    if (p + r < n)
                    {
                        s += x[p + r];
                    }
                    else
                        continue;
                }
                ans = min(ans, s);
            }
        }
        else
        {
            if (p - i > k)
            {
                break;
            }
            else
            {
                lol s = -x[i];
                lol r = k - (p - i);
                if (r > 0)
                {
                    s += -x[i];
                    if (p + r - 1 < n)
                    {
                        s += x[p + r - 1];
                    }
                    else
                        continue;
                }
                ans = min(ans, s);
            }
        }
    }
    if (p + k - 1 < n)
    {
        ans = min(ans, x[p + k - 1]);
    }
    cout << ans;

    return 0;
}