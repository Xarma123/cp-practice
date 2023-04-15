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
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<lol> x;
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < mn)
            {
                mn = a[i];
                x.insert(i);
            }
        }
        while (m--)
        {
            lol k, d;
            cin >> k >> d;
            k--;
            a[k] -= d;
            auto it = x.upper_bound(k);
            auto it1 = it;
            it1--;
            if (k == (*it1))
            {
                while (it != x.end() && a[(*it)] >= a[k])
                {
                    auto l = it;
                    it++;
                    x.erase(l);
                }
            }
            else
            {
                if (a[(*it1)] > a[k])
                {
                    while (it != x.end() && a[(*it)] >= a[k])
                    {
                        auto l = it;
                        it++;
                        x.erase(l);
                    }
                    x.insert(k);
                }
            }
            cout << x.size() << ' ';
        }
        cout << '\n';
    }

    return 0;
}