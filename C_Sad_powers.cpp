#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol p = 3;
    set<lol> x;
    while (powl(2ll, p) <= 1e18)
    {
        for (lol i = 2; powl(i, p) <= 1e18; i++)
        {
            if (abs(sqrtl(powl(i, p)) * 1ll * sqrtl(powl(i, p)) - powl(i, p)) > 1e-9)
                x.insert((long long)powl(i, p));
        }
        p++;
    }
    vector<lol> v;
    for (auto it = x.begin(); it != x.end(); it++)
    {
        v.push_back((*it));
    }
    sort(v.begin(), v.end());

    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r;
        cin >> l >> r;
        cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) + (long long)sqrtl(r) - (long long)sqrtl(l - 1) << endl;
    }

    return 0;
}