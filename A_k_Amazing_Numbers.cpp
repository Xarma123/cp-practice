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
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            mp[t].push_back(i);
        }
        map<lol, lol> val;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            lol c = LONG_LONG_MAX;
            c = max((*i).second[0] + 1, n - (*i).second[(*i).second.size() - 1]);
            for (lol j = 0; j < (*i).second.size() - 1; j++)
            {
                c = max(c, ((*i).second[j + 1] - (*i).second[j]));
            }

            val[(*i).first] = c;
        }

        lol ans[n];
        for (lol i = 0; i < n; i++)
        {
            ans[i] = -1;
        }
        lol last = n;
        for (auto i = val.begin(); i != val.end(); i++)
        {
            if (ans[(*i).second - 1] == -1)
            {
                for (lol j = (*i).second - 1; j < last; j++)
                {
                    if (ans[j] == -1)
                    {
                        ans[j] = (*i).first;
                    }
                }
                last = (*i).second - 1;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}