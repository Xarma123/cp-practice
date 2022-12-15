#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<string, vector<string>> mp;
map<string, lol> ind;
string name[7] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
lol solve(string s)
{
    lol v = 0;
    for (lol i = 0; i < 7; i++)
    {
        for (auto c : mp[name[i]])
        {
            if (s[i] == s[ind[c]])
                v++;
        }
    }
   
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 0; i < 7; i++)
    {
        ind[name[i]] = i;
    }

    while (n--)
    {
        string a, b;
        cin >> a >> b >> b;
        mp[a].push_back(b);
    }
    lol a, b, c;
    cin >> a >> b >> c;
    lol mn = LONG_LONG_MAX;
    vector<vector<lol>> q;
    for (lol x = 1; x <= 7; x++)
    {
        for (lol y = 1; y <= 7; y++)
        {
            if (x + y < 7)
            {
                lol v = max(a / x, max(b / y, c / (7 - x - y))) - min(a / x, min(b / y, c / (7 - x - y)));
                if (v < mn)
                {
                    mn = v;
                    q.clear();
                    q.push_back({x, y, 7 - x - y});
                }
                else if (v == mn)
                {
                    q.push_back({x, y, 7 - x - y});
                }
            }
        }
    }
    lol ans = 0;
    for (auto e : q)
    {
        for (lol i = 0; i < powl(3, 7); i++)
        {
            lol v = i;
            string s = "0000000";
            lol j = 0;
            while (v)
            {
                s[j] = char('0' + v % 3);
                v /= 3;
                j++;
            }

            lol co = 0, c1 = 0, c2 = 7;
            for (auto c : s)
            {
                if (c == '0')
                {
                    co++;
                    c2--;
                }
                else if (c == '1')
                {
                    c1++;
                    c2--;
                }
            } 
            
            if (co == e[0] && c1 == e[1] && c2 == e[2])
            {
                ans = max(ans, solve(s));
            }
        }
    }
    cout << mn << " " << ans;

    return 0;
}