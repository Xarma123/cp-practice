#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        string ans = "";

        map<char, vector<lol>> mp;

        for (lol i = 0; i < n; i++)
        {
            mp[a[i]].push_back(i);
        }
        lol i;
        for (i = 0; i < 26; i++)
        {
            if (!mp.count(char('a' + i)))
            {
                break;
            }
        }
        if (i == 26)
        {
            bool c = true;
            for (auto j = mp.begin(); j != mp.end(); j++)
            {
                set<char> x;
                for (lol k = 0; k < (*j).second.size(); k++)
                {
                    if ((*j).second[k] + 1 < a.size())
                        x.insert(a[(*j).second[k] + 1]);
                }
                lol k;
                for (k = 0; k < 26; k++)
                {
                    if (!x.count(char('a' + k)))
                    {
                        break;
                    }
                }
                if (k < 26)
                {
                    ans = ans + (*j).first + char('a' + k);
                    c = false;
                    break;
                }
            } 
            if(c)
            {
                
            }
        }
        else
        {
            ans = ans + char('a' + i);
            break;
        }
    }

    return 0;
}