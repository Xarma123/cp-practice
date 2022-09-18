#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol k;
        cin >> k;
        lol a[n];
        bool ans = false;
        set<lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp.count(a[i] - k) || mp.count(k + a[i]))
                ans = true;
            mp.insert(a[i]);
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}