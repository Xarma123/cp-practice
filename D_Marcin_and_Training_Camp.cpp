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
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    lol mp[n];
    memset(mp, 0, sizeof(mp));

    for (int i = 0; i < n; i++)
    {
        lol c = 0;
        for (int j = 0; j < n; j++)
        {
            if ((a[i] & (a[i] ^ a[j])))
            {
                c++;
            }
        }

        mp[i] = c;
    }
    lol sz = n;
    while (1)
    {
        lol mx = -1;
        for (lol i = 0; i < n; i++)
        {
            if (mp[i] != -1)
            {
                if (mx == -1)
                    mx = i;
                else if (mp[mx] < mp[i])
                    mx = i;
            }
        }
        if (mx == -1)
            break;
        if (mp[mx] == sz - 1)
        {
            for (lol i = 0; i < n; i++)
            {
                if (mp[i] != -1)
                {
                    if ((a[i] & (a[i] ^ a[mx])))
                    {
                        mp[i]--;
                    }
                }
            }
            mp[mx] = -1;
            sz--;
        }
        else
            break;
    }

    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (mp[i] != -1)
            ans += b[i];
    }

    cout << ans;
}