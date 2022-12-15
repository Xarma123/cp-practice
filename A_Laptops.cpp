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
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);
    lol mx = 0;
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        lol m2 = a[i].second, mn = a[i].second;
        lol j = i + 1;
        while (j < n && a[j].first == a[i].first)
        {

            m2 = max(m2, a[j].second);
            mn = min(mn, a[j].second);
            j++;
        }
        i = j - 1;

        if (mn < mx)
            f = false;

        mx = max(mx, m2);
    }
    if (f)
        cout << "Poor Alex";
    else
        cout << "Happy Alex";

    return 0;
}