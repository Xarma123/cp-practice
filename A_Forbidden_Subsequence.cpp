#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        lol check = 0;
        sort(s.begin(), s.end());

        if (t[1] == 'a' || t[2] == 'a')

            cout << s << endl;
        else
        {
            if (t[2] == 'b')
            {
                cout << s << endl;
            }
            else
            {
                lol a = 0;
                lol b = 0, c = 0, bi = -1, ci = -1;
                for (lol i = 0; i < s.size(); i++)
                {
                    if (s[i] == 'a')
                        a++;
                    if (s[i] == 'b')
                    {
                        bi = i;
                        while (s[i] == 'b')
                        {
                            b++;
                            i++;
                        }
                    }
                    if (s[i] == 'c')
                    {
                        ci = i;
                        while (s[i] == 'c')
                        {
                            c++;
                            i++;
                        }
                    }
                }
                if (ci == -1 || bi == -1 || a == 0)
                {
                    cout << s << endl;
                }
                else
                {
                    for (lol i = bi; i < ci + c; i++)
                    {
                        if (i < bi + c)
                            s[i] = 'c';
                        else
                            s[i] = 'b';
                    }
                    cout << s << endl;
                }
            }
        }
    }

    return 0;
}