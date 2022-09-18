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
        lol ans = LONG_LONG_MIN;

        for (lol i = 1; i <= n; i++)
        {
            lol c = 0;
            lol l = -1;
            vector<pair<lol, lol>> wow;
            for (lol j = 0; j < n; j++)
            {
                if (a[j] == i)
                {
                    c++;
                    l = i;
                }
                else
                {
                    if (c != 0)
                        wow.push_back({c, i});
                    c = 0;
                    l = a[j];
                    map<lol, lol> mp;
                    mp[a[j]]++;
                    lol f = 1;
                    lol k = j + 1;
                    if (k < n)
                    {
                        while (a[k] != i)
                        {
                            mp[a[k]]++;
                            if (f < mp[a[k]])
                                l = a[k];
                            f = max(f, mp[a[k]]);
                            k++;
                            if (k == n)
                                break;
                        }
                    }
                    if (f <= (k - j) / 2)
                    {
                        f = 0;
                        if ((k - j) % 2 != 0)
                            f++;
                    }
                    else
                        f = f - (k - j - f);
                    if (f != 0)
                        wow.push_back(f, l);
                    j = k - 1;
                }
            }
            if (l == i && c != 0)
                wow.push_back({c, i});
            

            
        }
        cout << max(ans, 0ll) << endl;
    }

    return 0;
}