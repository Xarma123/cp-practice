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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<lol> x;
        x.insert(a[0]);
        bool ans = true;
        for (lol i = 1; i < n && ans; i++)
        {

            auto it = x.lower_bound(a[i - 1]);
            lol l = LONG_LONG_MIN;
            if (it != x.begin())
            {
                it--;
                l = (*it);
            }
            it = x.upper_bound(a[i - 1]);
            lol r = LONG_LONG_MAX;
            if (it != x.end())
            {
                r = (*it);
            }
           
            x.insert(a[i]);
            if (a[i] < l || a[i] > r)
                ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}