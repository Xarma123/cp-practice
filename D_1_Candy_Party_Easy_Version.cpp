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
        lol n;
        cin >> n;
        lol a[n];
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        s /= n;
        bool ans = true;
        map<lol, lol> mp;
        for (lol j = 0; j < n; j++)
        {
            if (a[j] == s)
                continue;
            if (a[j] > s)
            {
                lol v = a[j] - s;
                lol l = -1, r;
                for (lol i = 0; i < 33; i++)
                {
                    if ((v & (1ll << i)))
                    {
                        if (l == -1)
                        {
                            l = r = i;
                        }
                        else
                            r = i;
                    }
                }
                for (lol i = l; i <= r; i++)
                {
                    if (!(v & (1ll << i)))
                        ans = false;
                }
                mp[r + 1]++;
                if (mp[r + 1] == 0)
                    mp.erase(r + 1);
                mp[l]--;
                if (mp[l] == 0)
                    mp.erase(l);
            }
            else
            {
                lol v = s - a[j];
                lol l = -1, r;
                for (lol i = 0; i < 33; i++)
                {
                    if ((v & (1ll << i)))
                    {
                        if (l == -1)
                        {
                            l = r = i;
                        }
                        else
                            r = i;
                    }
                }
                for (lol i = l; i <= r; i++)
                {
                    if (!(v & (1ll << i)))
                        ans = false;
                }
                mp[r + 1]--;
                if (mp[r + 1] == 0)
                    mp.erase(r + 1);
                mp[l]++;
                if (mp[l] == 0)
                    mp.erase(l);
            }
        }
        if (ans && mp.size() == 0)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}