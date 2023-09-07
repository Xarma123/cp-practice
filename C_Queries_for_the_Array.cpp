#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<pair<lol, lol>> v;
        lol l = -1;
        bool ans = true;
        lol i = 0;
        while (ans && i < s.size())
        {
            if (s[i] == '+')
            {
                if (v.size() == 0)
                {
                    v.push_back({1, i});
                }
                else
                    v.push_back({v.back().first, i});
            }
            else if (s[i] == '-')
            {
                v.pop_back();
            }
            else if (s[i] == '1')
            {
                if (v.size() > 1 && v.back().first == -1)
                {
                    ans = false;
                }
                else if (v.size())
                {
                    v[0].first = 1;
                }
                l = i;
            }
            else if (s[i] == '0')
            {
                if (v.size() <= 1)
                {
                    ans = false;
                }
                else if (v.back().first != -1)
                {
                    if (v.back().second > l)
                    {
                        v.back().first = -1;
                    }
                    else
                        ans = false;
                }
            }
            i++;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}