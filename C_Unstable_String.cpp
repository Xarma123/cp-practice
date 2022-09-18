#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        vector<lol> index;
        lol ans = 0;

        lol last_c = -1;
        lol check = -1;
        lol prv = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] != '?')
            {
                if (last_c == -1)
                {

                    check = s[i] - '0';
                }
                else
                {
                    if (s[i] - '0' != check)
                    {
                        ans += (i - prv) * (i - prv + 1) / 2;
                        prv = last_c + 1;
                        ans -= (i - prv) * (i - prv + 1) / 2; 
                        

                        check = s[i] - '0';
                    }
                }
                last_c = i;
            }

            if (check != -1)
                check = 1 - check;
        }
        ans += (s.size() - prv) * (s.size() - prv + 1) / 2;

        cout << ans << endl;
    }

    return 0;
}