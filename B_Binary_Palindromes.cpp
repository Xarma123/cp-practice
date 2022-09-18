#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        string s[n];
        lol z = 0, o = 0;
        lol od = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> s[i];
            for (lol j = 0; j < s[i].size(); j++)
            {
                if (s[i][j] == '0')
                    z++;
                else
                    o++;
                s[i][j] = 'a';
            }
            if (s[i].size() % 2 != 0)
            {
                od++;
            }
        }
        sort(s, s + n);
        lol ans = 0;
        lol e = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i].size() % 2 == 0)
            {
                lol sz = s[i].size();
                if (sz <= o)
                {
                    o -= sz;
                    sz = 0;
                }
                else if (sz <= z)
                {
                    z -= sz;
                    sz = 0;
                }
                else
                {
                    sz -= o - o % 2;
                    o = o % 2;
                    if (sz <= z)
                    {
                        z -= sz - sz % 2;
                        sz = sz % 2;
                    }
                    else
                    {

                        sz -= z - z % 2;
                        z = z % 2;
                    }
                }
                if (sz == 0)
                    e++;
                else
                {
                    if (o >= sz)
                        o -= sz;
                    else if (z >= sz)
                        z -= sz;
                    else
                    {
                        sz -= o;
                        o = 0;
                        if (sz <= z)
                        {
                            z -= sz;
                            sz = 0;
                        }
                        else
                        {

                            sz -= z;
                            z = 0;
                        }
                    }
                }
            }
        }
        cout << e + od << endl;
    }

    return 0;
}