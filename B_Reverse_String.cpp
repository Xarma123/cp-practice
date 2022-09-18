#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        string t;
        cin >> t;
        lol n = s.size();
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            string c = "";
            c.push_back(s[i]);

            for (lol j = i; j < n; j++)
            {

                if (j != i)
                {
                    c.push_back(s[j]);
                }
                if (c == t)
                {
                    f = true;
                    break;
                }
                string c2 = c;
                for (lol k = j - 1; k >= 0; k--)
                {
                    c2.push_back(s[k]);

                    if (c2 == t)
                    {
                        f = true;
                        break;
                    }
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}