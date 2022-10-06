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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            k--;
            string s2 = s;
            for (lol i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    s2[i] = '0';
                    if (i - 1 >= 0 && s[i - 1] == '0')
                        s2[i - 1] = '1';
                    if (i + 1 < n && s[i + 1] == '0')
                        s2[i + 1] = '1';
                }
            }
            s = s2;

            lol one[n];
            lol l = -1;
            for (lol i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    l = i;
                }
                if (l == -1)
                    one[i] = -1;
                else
                    one[i] = abs(i - l);
            }
            lol r = -1;
            for (lol i = n - 1; i >= 0; i--)
            {
                if (s[i] == '1')
                {
                    r = i;
                }
                if (r != -1)
                {
                    if (one[i] != -1)
                        one[i] = min(one[i], abs(i - r));
                    else
                        one[i] = abs(i - r);
                }
            }
            for (lol i = 0; i < n; i++)
            {
                if (one[i] != -1)
                {
                    if ((k - one[i]) >= 0)
                    {
                        if ((k - one[i]) % 2 == 0)
                            s[i] = '1';
                        else
                            s[i] = '0';
                    }
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}