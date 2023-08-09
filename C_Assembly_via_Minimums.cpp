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
        lol n;
        cin >> n;
        lol m = (((n)*1ll * (n - 1)) / 2ll);
        lol a[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        sort(a, a + m);
        map<lol, lol> mp;
        for (lol i = 0; i < m; i++)
        {
            lol j = i + 1;
            while (j < m && a[i] == a[j])
                j++;
            lol f = j - i;
            lol s = 0, e = n + 1;
            while (s != e - 1)
            {
                lol mid = (s + e) / 2ll;
                if (mid == 0)
                    s = mid;
                else if (mid == n + 1)
                    e = mid;
                else
                {
                    lol c = n * 1ll * mid;
                    c -= mid * 1ll * (mid + 1) / 2ll;
                    if (c <= f)
                    {

                        s = mid;
                    }
                    else
                        e = mid;
                }
            }
           
            mp[a[i]] = s;
            n -= s;
            i = j - 1;
        }
        vector<lol> ans;
        for (auto e : mp)
        {
            lol c = e.second;
            while (c--)
            {
                ans.push_back(e.first);
            }
        }
        for (auto e : ans)
            cout << e << ' ';
        cout << '\n';
    }
}