#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol mn = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    lol mx = 0;
    vector<lol> ind;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == mn)
            ind.push_back(i);
    }
    for (lol i = 0; i < ind.size(); i++)
    {
        lol v = ind[(i + 1) % ind.size()] - ind[i];
        if (v > 0)
            v--;
        else
        {
            v = -v;
            v++;
            v = n - v;
        }

        mx = max(mx, v);
    }

    cout << n * 1ll * mn + mx;

    return 0;
}