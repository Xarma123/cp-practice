#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        lol c[n + 1];
        c[0] = 0;

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        for (lol i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + a[i - 1].first;
        }
        lol last = -1;
        for (lol i = 1; i <= n; i++)
        {
            if (i == n)
                continue;
            if (c[i] < a[i].first)
            {
                last = i - 1;
            }
        }
        set<lol> ans;
        for (lol i = last + 1; i < n; i++)
        {
            ans.insert(a[i].second);
        }
        cout << ans.size() << endl;
        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout << (*i) + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}