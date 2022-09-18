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
        map<char, lol> mp;
        for (lol i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        while (s.size() > 0)
        {
            char c = s[0];
            mp[c]--;

            if (mp[c] == 0)
                break;
            s.erase(0, 1);
        }
        cout << s << endl;
    }

    return 0;
}