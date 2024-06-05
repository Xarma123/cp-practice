#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol x = 0, y = 0;
        lol nr = 0, es = 0;
        for (auto e : s)
        {
            if (e == 'N')
                nr++, x++;
            else if (e == 'S')
                x--;
            else if (e == 'E')
                es++, y++;
            else
                y--;
        }
        if ((x % 2) || (y % 2))
        {
            cout << "NO\n";
        }
        else
        {
            map<char, lol> mp;
            if (x > 0)
            {
                mp['N'] = x / 2ll;
            }
            else if (x < 0)
            {
                mp['S'] = (-x) / 2ll;
            }
            if (y > 0)
            {
                mp['E'] = y / 2ll;
            }
            else if (y < 0)
                mp['W'] = (-y) / 2ll;

            if (mp.size() == 0)
            {
                if (min(nr, nr - x) > 1)
                {
                    mp['N']++;
                    mp['S']++;
                }
                else if (min(es, es - y) > 1)
                {
                    mp['E']++;
                    mp['W']++;
                }
                else if (min(nr, nr - x) == 1 && min(es, es - y) == 1)
                {
                    mp['E']++;
                    mp['W']++;
                }
                else
                {
                    cout << "NO\n";
                    continue;
                }
            }
            for (auto e : s)
            {
                if (mp[e] > 0)
                {
                    cout << 'R';
                    mp[e]--;
                }
                else
                    cout << "H";
            }
            cout << '\n';
        }
    }

    return 0;
}
