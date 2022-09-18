#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    for (lol k = 1; k <= t; k++)
    {
        string n;
        cin >> n;
        lol v = 0;
        for (lol i = 0; i < n.size(); i++)
        {
            v += (n[i] - '0');
        }

        char c = char('0' + (9 - ((v) % 9)));
        if (v % 9 == 0)
            c = '0';

        for (lol i = 0; i <= n.size(); i++)
        {
            if (i == 0 && c == '0')
                continue;
            if (i < n.size())
            {
                if (n[i] > c)
                {
                    n.insert(i, 1, c);
                    break;
                }
            }
            else
            {
                n.push_back(c);
                break;
            }
        }

        cout << "Case #" << k << ": " << n << endl;
    }

    return 0;
}