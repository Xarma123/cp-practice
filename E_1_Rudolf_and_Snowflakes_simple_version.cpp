    #include <bits/stdc++.h>
    using namespace std;
    #define lol long long
    int main()
    {
        lol t;
        cin >> t;
        while (t--)
        {
            lol n;
            cin >> n;
            bool ans = false;
            for (lol i = 2; i <= 63; i++)
            {
                lol st = 1, e = 1e9 + 1;
                while (st != e - 1)
                {
                    lol m = (st + e) / 2;
                    if (m == 1)
                    {
                        st = m;
                    }
                    else if ((long long)ceill(powl(1e18, 1 / (long double)i)) < m)
                    {
                        e = m;
                    }
                    else
                    {

                        lol v = 0;
                        lol pw = 1;
                        for (lol j = 0; j <= i && v < n && pw <= n; j++)
                        {
                            if (j)
                                pw = pw * 1ll * m;
                            v += pw;
                        }
                        if (v >= n)
                            e = m;
                        else
                            st = m;
                    }
                }
                lol v = 0;
                lol pw = 1;
                lol j;
                for (j = 0; j <= i && v < n && pw <= n; j++)
                {
                    if (j)
                        pw = pw * 1ll * e;
                    v += pw;
                }
                if (v == n && j > i)
                {
                    ans = true;
                }
            }

            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }