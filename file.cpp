#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol n = s.size();
    lol b = 0;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            b++;
    }
    lol pod[n];
    lol pev[n];
    for (lol i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            pev[i] = (s[i] - '0');
            pod[i] = 0;
        }
        else
        {
            pod[i] = (s[i] - '0');
            pev[i] = 0;
        }
        if (i)
        {
            pev[i] += pev[i - 1];
            pod[i] += pod[i - 1];
        }
    }
    if (2ll * b - 1 > n)
    {
        cout << -1;
    }
    else if (b == 0)
    {
        cout << 0;
    }
    else
    {
        lol ans = LONG_LONG_MAX;
        lol j = n - 1 - (2ll * b - 2);
        if (j % 2 == 0)
        {
            lol v = pev[n - 1];
            if (j)
                v -= pev[j - 1];
            ans = min(ans, b - v);
        }
        else
        {
            lol v = pod[n - 1];
            if (j)
                v -= pod[j - 1];
            ans = min(ans, b - v);
        }
        j = n - 2 - (2ll * b - 2);
        if (j >= 0)
        {
            if (j % 2 == 0)
            {
                lol v = pev[n - 2];
                if (j)
                    v -= pev[j - 1];
                ans = min(ans, b - v);
            }
            else
            {
                lol v = pod[n - 2];
                if (j)
                    v -= pod[j - 1];
                ans = min(ans, b - v);
            }
        }
        
        cout << ans;
    }

    return 0;
}