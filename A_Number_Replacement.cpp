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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;
        map<lol, char> mp;
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (mp.count(a[i]))
            {
                ans &= (s[i] == mp[a[i]]);
            }
            else
                mp[a[i]] = s[i];
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}