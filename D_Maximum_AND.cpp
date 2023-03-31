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
            lol b[n];
            for (lol i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            for (lol i = 0; i < n; i++)
            {
                cin >> b[i];
            }
            lol ans = 0;
            for (lol i = 31; i >= 0; i--)
            {
            

                map<lol, lol> mp;
                mp.clear();
                for (lol j = 0; j < n; j++)
                {
                    lol v = 0;
                    for (lol k = 0; k < 32; k++)
                    {
                        if ((ans & (1ll << k)) || k == i)
                        {
                            v |= (a[j] & (1ll << k));
                        }
                    }
                
                    mp[v]++;
                }
                
                for (lol j = 0; j < n; j++)
                {
                    lol v = 0;
                    for (lol k = 0; k < 32; k++)
                    {
                        if ((ans & (1ll << k)) || k == i)
                        {
                            if (!(b[j] & (1ll << k)))
                            {
                                v |= (1ll << k);
                            }
                        }
                    }
            
                    mp[v]--;
                    if (mp[v] == 0)
                        mp.erase(v);
                }

                if (mp.size() == 0)
                {
                    ans |= (1ll << i);
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }