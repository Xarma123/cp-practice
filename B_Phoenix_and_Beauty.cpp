#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, k;
        cin >> n >> k;
        vector<lol> a;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;

            mp[t]++;

            a.push_back(t);
        }
        if (mp.size() > k)
            cout << -1 << endl;
        else
        {
            vector<lol> ans;
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                ans.push_back((*i).first);
            }
            while (ans.size() < k)
            {
                ans.push_back(ans.back());
            }
            cout << k * n << endl;
            while (n--)
            {
                for (lol i = 0; i < k; i++)
                {
                    cout << ans[i] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}