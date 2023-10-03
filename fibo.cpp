#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    lol d[n];
    bool ans = true;
    lol mn = LONG_LONG_MAX;
    for (lol i = 0; i < n && ans; i++)
    {
        d[i] = b[i] - a[i];
        if (d[i] < 0)
            ans = false;
        mn = min(mn, d[i]);
    }
    if (!ans)
    {
        cout << -1;
        return 0;
    }
    lol in = -1;
    for (lol i = 1; i < n && ans; i++)
    {
        if (in == -1)
        {
            if (a[i] > a[i - 1])
            {
                in = i;
            }
        }
        else
        {
            if (a[i] < a[i - 1])
                ans = false;
        }
    }
    if (!ans)
    {
        cout << -1;
        return 0;
    }
    if (in == -1)
    {
        cout << d[0];
    }
    else if (in == 1)
    {
        cout << d[n - 1];
    }
    else
    {
        cout << a[0] + a[n - 1] - mn;
    }
}