#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
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
        vector<lol> o, z;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                z.push_back(i + 1);
            }
            else
                o.push_back(i + 1);
        }
        if (z.size() == 0 || o.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(o.begin(), o.end());
            sort(z.begin(), z.end());
            lol i = 0;
            bool f = true;
            vector<lol> ans;
            while (n--)
            {
                if (f)
                {
                    ans.push_back(o[i]);
                    i++;
                    if (i >= o.size())
                    {
                        i = 0;
                        f = false;
                    }
                }
                else
                {
                    ans.push_back(z[i]);
                    i++;
                }
            }
            sort(ans.begin(), ans.end());
            for (auto e : ans)
                cout << e << ' ';
            cout << endl;
        }
    }

    return 0;
}