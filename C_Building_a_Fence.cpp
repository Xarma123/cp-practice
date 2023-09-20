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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol pl = LONG_LONG_MIN, pr = LONG_LONG_MAX;
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            lol l, r;
            if (i == 0)
            {
                l = a[i];
                r = a[i];
            }
            else if (i == n - 1)
            {
                l = a[i];
                r = a[i];
            }
            else
            {
                l = a[i];
                r = a[i] + k - 1;
            }
            if (l > pr || r < pl)
            {
                ans = false;
                
            }
            else
            {
                pl = max(l, pl);
                pr = min(r, pr);
                pl -= k - 1;
                pr += k - 1;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}