#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        set<pair<pair<lol, lol>, pair<lol, lol>>> set;
        lol ans = 0;
        lol x = 0, y = 0;
        for (lol i = 0; i < str.size(); i++)
        {
            pair<lol, lol> a, b;
            if (str[i] == 'N')
            {

                a = make_pair(x, y);
                y++;
                b = make_pair(x, y);
            }
            else if (str[i] == 'S')
            {
                a = make_pair(x, y);
                y--;
                b = make_pair(x, y);
            }
            else if (str[i] == 'E')
            {
                a = make_pair(x, y);
                x++;
                b = make_pair(x, y);
            }
            else
            {
                a = make_pair(x, y);
                x--;
                b = make_pair(x, y);
            }

            pair<pair<lol, lol>, pair<lol, lol>> q = make_pair(a, b);
            if (set.count(q))
            {
                ans++;
            }
            else
            {
                ans += 5;
                pair<pair<lol, lol>, pair<lol, lol>> q2 = make_pair(b, a);
                set.insert(q);
                set.insert(q2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}