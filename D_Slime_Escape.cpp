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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        k--;
        lol l = k - 1;
        lol r = k + 1;
        lol rmax = 0;
        lol lmax = 0;
        lol sl = 0;
        lol sr = 0;
        while (l >= 0 && r < n)
        {
            bool f = true;
            while (l >= 0 && sl + rmax + a[l] + a[k] >= 0)
            {
                sl += a[l--];
                lmax = max(lmax, sl);
                f = false;
            }
            while (r < n && sr + lmax + a[r] + a[k] >= 0)
            {
                sr += a[r++];
                rmax = max(rmax, sr);
                f = false;
            }
            if (f)
                break;
        }
        if (l == -1 || r == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}