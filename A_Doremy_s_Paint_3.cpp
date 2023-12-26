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
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            mp[v]++;
        }
        lol c1 = 0, c2 = 0;
        lol c3 = 0;
        for (auto e : mp)
        {
            if (e.second == (n / 2))
                c1++;
            if (e.second == (n / 2) + (n % 2))
                c2++;
            if (e.second == n)
                c3++;
        }
        if (n % 2 == 0 && c1 == 2)
            cout << "Yes\n";
        else if (n % 2 != 0 && c1 == 1 && c2 == 1)
            cout << "Yes\n";
        else if (c3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
