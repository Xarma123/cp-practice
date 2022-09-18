#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        string s, t, p;
        cin >> s >> t >> p;
        lol pt = 0;
        for (lol i = 0; i < t.size(); i++)
        {
            if (t[i] == s[pt])
                pt++;
            if (pt == s.size())
                break;
        }
        if (pt != s.size())
            cout << "NO" << endl;
        else
        {
            map<char, lol> mp;
            for (lol i = 0; i < t.size(); i++)
            {
                mp[t[i]]++;
            }
            for (lol i = 0; i < s.size(); i++)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
            }
            map<char, lol> mp2;
            for (lol i = 0; i < p.size(); i++)
            {
                mp2[p[i]]++;
            }
            bool ans = true;
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                if (mp2[(*i).first] < (*i).second)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}