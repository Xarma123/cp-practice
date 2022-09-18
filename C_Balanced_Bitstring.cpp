#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol q0 = 0, q1 = 0;
        bool ans = true;
        lol o = 0, z = 0;
        for (lol i = 0; i < k; i++)
        {
            if (s[i] == '0')
                z++;
            else if (s[i] == '1')
                o++;
        }

        if (z > k / 2 || o > k / 2)
            ans = false;
        else
        {
            q0 = k / 2 - z;
            q1 = k / 2 - o;
            lol st = 0;
            lol e = k;
            while (e < n)
            {
                if (s[st] == s[e])
                {
                }
                else
                {
                    if (s[st] == '?')
                    {
                        if (s[e] == '0')
                            q0--;
                        else
                            q1--;
                        if (q0 < 0 || q1 < 0)
                        {
                            ans = false;
                            break;
                        }
                    }
                    else if (s[e] == '?')
                    {
                        if (s[st] == '0')
                            s[e] = '0';
                        else
                            s[e] = '1';
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }

                st++;
                e++;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}