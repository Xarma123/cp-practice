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
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            mp[(q % 4)]++;
        }
        lol ans = 0;
        lol i;
        for (i = 1; i < 4; i++)
        {
            if (i == 2)
                continue;
            while (mp[i] > 0)
            {
                mp[i]--;
                if (mp[4 - i] > 0)
                {
                    mp[4 - i]--;
                    ans++;
                }
                else
                {
                    mp[i]++;
                    break;
                }
            }
        }
        for (i = 1; i < 4; i++)
        {
            if (i == 2)
                continue;
            while (mp[i] > 0)
            {
                mp[i]--;
                lol j;
                for (j = 1; j < 4; j++)
                {
                    lol k;
                    for (k = 1; k < 4; k++)
                    {
                        if ((j + k + i) % 4 == 0)
                        {
                            if (mp[j] > 0 && mp[k] > 0)
                            {

                                mp[j]--;
                                mp[k]--;
                                ans += 2;
                                break;
                            }
                        }
                    }
                    if (k != 4)
                        break;
                }
                if (j == 4)
                {
                    mp[i]++;
                    break;
                }
            }
            if (mp[i] > 0)
                break;
        }
        if (i == 4 && mp[2] % 2 == 0)
            cout << ans + mp[2] / 2 << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}