#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol b[n];
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            s -= b[i];
        }
        set<pair<lol, lol>> x;
        for (lol i = 0; i < n; i++)
        {
            x.insert({-b[i] - a[i], i});
        }
        bool f = true;
        while (!x.empty())
        {
            auto it = *x.begin();
            x.erase(x.begin());
            if (f)
            {
                s += b[it.second] - 1;
                f = false;
            }
            else
            {
                s += 1 - a[it.second];
                f = true;
            }
        }
        cout << s << '\n';
    }

    return 0;
}
