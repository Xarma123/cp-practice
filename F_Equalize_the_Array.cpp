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
        lol a[n];
        set<lol> c;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        map<lol, lol> freq;
        for (lol i = 0; i < n; i++)
        {
            freq[a[i]]++;
        }
        vector<lol> f;
        for (auto i = freq.begin(); i != freq.end(); i++)
        {
            f.push_back((*i).second);
            c.insert((*i).second);
        }
        freq.clear();
        sort(f.begin(), f.end());
        lol sum[f.size() + 1];
        sum[0] = 0;
        for (lol i = 1; i <= f.size(); i++)
        {
            sum[i] = f[i - 1] + sum[i - 1];
        }
        lol ans = LONG_LONG_MAX;
        for (auto i = c.begin(); i != c.end(); i++)
        {
            lol count = 0;
            lol in = lower_bound(f.begin(), f.end(), (*i)) - f.begin();

            count += sum[in];

            in = upper_bound(f.begin(), f.end(), (*i)) - f.begin();
            count += (sum[f.size()] - sum[in]) - (f.size() - in) * ((*i));
            ans = min(ans, count);
        }
        cout << ans << endl;
    }

    return 0;
}