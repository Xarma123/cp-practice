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
        bool ans = false;
        set<lol> v;
        v.insert(0);
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
                s += a[i];
            else
                s -= a[i];
            if (v.count(s))
                ans = true;
            v.insert(s);
        }
        if (!ans)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
