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
        lol n;
        cin >> n;
        lol a[n];
        lol b[n];
        map<lol, map<lol, lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]][(i % 2)]++;
            b[i] = a[i];
        }
        sort(b, b + n);
        for (lol i = 0; i < n; i++)
        {
            mp[b[i]][(i % 2)]--;
            if (mp[b[i]][(i % 2)] == 0)
                mp[b[i]].erase((i % 2));
            if (mp[b[i]].size() == 0)
                mp.erase(b[i]);
        }

        if (mp.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}