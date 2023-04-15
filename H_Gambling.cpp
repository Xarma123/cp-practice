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
        lol a[n];
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        lol mx = 0;
        lol l, r;
        lol ans;
        for (auto e : mp)
        {
            lol f = e.first;
            vector<lol> v = e.second;
            lol mxtill = 1;
            lol s = v[0];
            if (mxtill > mx)
            {
                ans = f;
                l = s;
                r = v[0];
                mx = 1;
            }
            for (lol i = 1; i < v.size(); i++)
            {
                if (mxtill + v[i - 1] - v[i] + 2 < 1ll)
                {
                    s = v[i];
                }
                mxtill = max(1ll, mxtill + v[i - 1] - v[i] + 2);
                if (mxtill > mx)
                {
                    ans = f;
                    l = s;
                    r = v[i];
                    mx = mxtill;
                }
            }
        }
        cout << ans << " " << l+1 << " " << r+1 << endl;
    }

    return 0;
}