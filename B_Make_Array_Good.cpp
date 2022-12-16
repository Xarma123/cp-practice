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
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a, a + n);
        cout << n << endl;
        for (lol i = 0; i < n - 1; i++)
        {
            lol r = a[i + 1].first % a[i].first;
            if (r == 0)
                r = a[i].first;
            cout << a[i + 1].second << " " << a[i].first - r << endl;
            a[i + 1].first += a[i].first - r;
        }
        cout << a[n - 1].second << " " << 0 << endl;
    }

    return 0;
}