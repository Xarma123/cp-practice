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
        lol ans = LONG_LONG_MIN;

        for (lol i = 0; i <= 9; i++)
        {
            for (lol j = 0; j <= 9; j++)
            {

                lol tggle = 1;
                char a = char('0' + i);
                char b = char('0' + j);
                lol cur = 0;
                for (lol k = 0; k < s.size(); k++)
                {
                    if (tggle)
                    {
                        if (s[k] == a)
                        {
                            cur++;
                            tggle = 1 - tggle;
                        }
                    }
                    else
                    {
                        if (s[k] == b)
                        {
                            cur++;
                            tggle = 1 - tggle;
                        }
                    }
                }
                if (cur % 2 != 0 && i != j)
                {
                    cur--;
                }

                ans = max(ans, cur);
            }
        }
        cout << s.size() - ans << endl;
    }

    return 0;
}