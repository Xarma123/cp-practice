#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    map<string, lol> mp;
    while (t--)
    {
        char a;
        cin >> a;
        string s;
        cin >> s;
        if (a == '+')
        {
            for (lol i = 0; i < s.size(); i++)
            {
                if ((s[i] - '0') % 2 == 0)
                    s[i] = '0';
                else
                    s[i] = '1';
            }
            lol ex = 21 - s.size();
            while (ex--)
            {
                s = "0" + s;
            }
            mp[s]++;
        }
        else if (a == '-')
        {
            for (lol i = 0; i < s.size(); i++)
            {
                if ((s[i] - '0') % 2 == 0)
                    s[i] = '0';
                else
                    s[i] = '1';
            }
            lol ex = 21 - s.size();
            while (ex--)
            {
                s = "0" + s;
            }
            mp[s]--;
        }
        else
        {
            lol ex = 21 - s.size();
            while (ex--)
            {
                s = "0" + s;
            }
            cout << mp[s] << endl;
        }
    }

    return 0;
}