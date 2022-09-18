#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    map<pair<char, char>, lol> mp;
    for (lol i = 0; i < 2 * n; i++)
    {
        mp[make_pair(s[i], t[i])]++;
    }
    lol f = 0, sc = 0;
    lol tgle = 1;
    for (lol i = 0; i < 2 * n; i++)
    {
        if (tgle)
        {
            if (mp[make_pair('1', '1')] > 0)
            {
                f++;
                mp[make_pair('1', '1')]--;
            }
            else if (mp[make_pair('1', '0')] > 0)
            {
                f++;
                mp[make_pair('1', '0')]--;
            }
            else if (mp[make_pair('0', '1')] > 0)
            {
                mp[make_pair('0', '1')]--;
            }
            else
            {
                mp[make_pair('0', '0')]--;
            }
            tgle = 1 - tgle;
        }
        else
        {

            if (mp[make_pair('1', '1')] > 0)
            {
                sc++;
                mp[make_pair('1', '1')]--;
            }
            else if (mp[make_pair('0', '1')] > 0)
            {
                sc++;
                mp[make_pair('0', '1')]--;
            }
            else if (mp[make_pair('1', '0')] > 0)
            {

                mp[make_pair('1', '0')]--;
            }

            else
            {
                mp[make_pair('0', '0')]--;
            }
            tgle = 1 - tgle;
        }
    }
    if (sc == f)
        cout << "Draw";
    else if (sc > f)
        cout << "Second";
    else
        cout << "First";

    return 0;
}