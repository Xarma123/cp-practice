#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol h[n];
    lol mn = LONG_LONG_MAX;
    lol mx = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        cin >> h[i];
        mn = min(mn, h[i]);
    }
    for (lol i = 0; i < n; i++)
    {
        h[i] -= mn;
        mx = max(mx, h[i]);
    }
    if (mx == 0)
        cout << 0;
    else
    {
        sort(h, h + n);
        lol c[n];
        c[0] = h[0];
        for (lol i = 1; i < n; i++)
        {
            c[i] = c[i - 1] + h[i];
        }
        
    }

    return 0;
}