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
    lol ans = 0;
    bool aln = true;
    bool alp = true;
    lol mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += abs(a[i]);
        if (a[i] < 0)
            alp = false;
        if (a[i] > 0)
            aln = false;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (alp)
    {
        ans -= mn;
        ans -= mn;
    }
    else if (aln)
    {
        ans -= abs(mx);
        ans += mx;
    }
    if (n > 1)
        cout << ans;
    else
        cout << a[0];

    return 0;
}