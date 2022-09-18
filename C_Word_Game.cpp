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
        map<string, lol> mp;
        lol n;
        cin >> n;
        vector<string> a[3];
        for (lol i = 0; i < 3; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                string s;
                cin >> s;
                a[i].push_back(s);
                mp[s]++;
            }
        }
        for (lol i = 0; i < 3; i++)
        {
            lol v = 0;
            for (auto s : a[i])
            {
                if (mp[s] == 1)
                    v += 3;
                else if (mp[s] == 2)
                    v++;
            }
            if (i == 2)
                cout << v;
            else
                cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}