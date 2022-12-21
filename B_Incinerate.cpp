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
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        sort(a, a + n);
        lol d = k;
        lol i = 0;
        while (k > 0 && i < n)
        {
            if (a[i].second - d > 0)
            {
                k -= a[i].first;
                d += k;
            }
            else
            {
                i++;
            }
        }
        for (i = 0; i < n; i++)
        {

            if (a[i].second - d > 0)
                break;
        }
        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}