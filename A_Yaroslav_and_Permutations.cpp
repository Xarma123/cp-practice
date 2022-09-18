#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    map<lol, lol> mp;
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > n - mp[a[i]] + (n % 2))
            f = false;
    }
    if (f)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}